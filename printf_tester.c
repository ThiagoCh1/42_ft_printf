// printf_tester.c
// Single-file tester for 42 ft_printf (no external deps).
// It runs each test twice—once with system printf, once with your ft_printf—
// captures stdout, compares both output and return value, and prints a summary.
//
// Build example:
//   cc -Wall -Wextra -Werror -I src printf_tester.c libftprintf.a -o printf_tester
// Run:
//   ./printf_tester
//
// If your header path is different, adjust the -I flag above.
// Make sure libftprintf.a is already built.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

// Include your ft_printf
#include "ft_printf.h"

// Counters
static int g_total = 0;
static int g_failed = 0;

// --- Capture helpers ---
// Redirect stdout to a temp file, run a print, restore stdout, read result.
static int begin_capture(int *saved_fd, FILE **tmpf)
{
    fflush(stdout);
    *saved_fd = dup(STDOUT_FILENO);
    if (*saved_fd < 0) {
        perror("dup");
        return -1;
    }
    *tmpf = tmpfile();
    if (!*tmpf) {
        perror("tmpfile");
        close(*saved_fd);
        return -1;
    }
    int tfd = fileno(*tmpf);
    if (tfd < 0) {
        perror("fileno");
        fclose(*tmpf);
        close(*saved_fd);
        return -1;
    }
    if (dup2(tfd, STDOUT_FILENO) < 0) {
        perror("dup2");
        fclose(*tmpf);
        close(*saved_fd);
        return -1;
    }
    return 0;
}

static int end_capture(int saved_fd, FILE *tmpf, char **out, size_t *out_len)
{
    fflush(stdout);
    int fd = fileno(tmpf);
    if (fd < 0) {
        perror("fileno/end");
        // attempt to restore stdout anyway
        dup2(saved_fd, STDOUT_FILENO);
        close(saved_fd);
        fclose(tmpf);
        return -1;
    }
    off_t sz = lseek(fd, 0, SEEK_END);
    if (sz < 0) sz = 0;
    if (lseek(fd, 0, SEEK_SET) < 0) {
        perror("lseek");
    }
    *out = (char *)malloc(sz + 1);
    if (!*out) {
        fprintf(stderr, "malloc failed in end_capture\n");
        dup2(saved_fd, STDOUT_FILENO);
        close(saved_fd);
        fclose(tmpf);
        return -1;
    }
    ssize_t rd = read(fd, *out, (size_t)sz);
    if (rd < 0) rd = 0;
    *out_len = (size_t)rd;
    (*out)[*out_len] = '\0'; // for convenience; content may contain '\0'

    if (dup2(saved_fd, STDOUT_FILENO) < 0) {
        perror("dup2 restore");
    }
    close(saved_fd);
    fclose(tmpf);
    return 0;
}

// --- Diff helpers ---
static void print_hex_snippet(const char *label, const unsigned char *buf, size_t len)
{
    // Print up to 32 bytes in hex for debugging invisible chars (like %c '\0')
    size_t max = len < 32 ? len : 32;
    fprintf(stderr, "%s [len=%zu]: ", label, len);
    for (size_t i = 0; i < max; ++i) {
        fprintf(stderr, "%02X ", buf[i]);
    }
    if (len > max) fprintf(stderr, "...");
    fputc('\n', stderr);
}

static void report_mismatch(const char *where, int line,
                            const char *fmt,
                            const char *sys_buf, size_t sys_len, int r_sys,
                            const char *ft_buf, size_t ft_len, int r_ft)
{
    fprintf(stderr, "❌ Mismatch at %s:%d\n", where, line);
    fprintf(stderr, "  format: \"%s\"\n", fmt);
    fprintf(stderr, "  return: sys=%d, ft=%d\n", r_sys, r_ft);
    if (sys_len != ft_len) {
        fprintf(stderr, "  output length differs: sys=%zu, ft=%zu\n", sys_len, ft_len);
    }
    if ((sys_len == ft_len && memcmp(sys_buf, ft_buf, sys_len) != 0) || (sys_len != ft_len)) {
        print_hex_snippet("  sys", (const unsigned char*)sys_buf, sys_len);
        print_hex_snippet("  ft ", (const unsigned char*)ft_buf, ft_len);
    }
}

// --- Comparison + test runner core ---
static void compare_and_report(const char *where, int line, const char *fmt,
                               const char *sys_buf, size_t sys_len, int r_sys,
                               const char *ft_buf, size_t ft_len, int r_ft)
{
    ++g_total;
    int ok = 1;
    if (r_sys != r_ft) ok = 0;
    if (sys_len != ft_len) ok = 0;
    else if (memcmp(sys_buf, ft_buf, sys_len) != 0) ok = 0;

    if (!ok) {
        ++g_failed;
        report_mismatch(where, line, fmt, sys_buf, sys_len, r_sys, ft_buf, ft_len, r_ft);
    }
}

// Macro to run a single test case: captures both printf and ft_printf, compares.
#define RUN_TEST(fmt, ...) do {                                             \
    char *sys_buf = NULL, *ft_buf = NULL;                                   \
    size_t sys_len = 0, ft_len = 0;                                         \
    int r_sys = 0, r_ft = 0;                                                \
    int saved_fd; FILE *tmpf;                                               \
    if (begin_capture(&saved_fd, &tmpf) == 0) {                             \
        r_sys = printf(fmt, __VA_ARGS__);                                   \
        fflush(stdout);                                                     \
        end_capture(saved_fd, tmpf, &sys_buf, &sys_len);                    \
    } else {                                                                \
        fprintf(stderr, "begin_capture failed for system printf\n");        \
        exit(1);                                                            \
    }                                                                       \
    if (begin_capture(&saved_fd, &tmpf) == 0) {                             \
        r_ft = ft_printf(fmt, __VA_ARGS__);                                 \
        fflush(stdout);                                                     \
        end_capture(saved_fd, tmpf, &ft_buf, &ft_len);                      \
    } else {                                                                \
        fprintf(stderr, "begin_capture failed for ft_printf\n");            \
        free(sys_buf);                                                      \
        exit(1);                                                            \
    }                                                                       \
    compare_and_report(__FILE__, __LINE__, fmt,                             \
                       sys_buf, sys_len, r_sys,                             \
                       ft_buf, ft_len, r_ft);                               \
    free(sys_buf);                                                          \
    free(ft_buf);                                                           \
} while(0)

// For tests without variadic args (e.g., just a literal), allow empty __VA_ARGS__
#define RUN_TEST0(fmt) do {                                                 \
    char *sys_buf = NULL, *ft_buf = NULL;                                   \
    size_t sys_len = 0, ft_len = 0;                                         \
    int r_sys = 0, r_ft = 0;                                                \
    int saved_fd; FILE *tmpf;                                               \
    if (begin_capture(&saved_fd, &tmpf) == 0) {                             \
        r_sys = printf(fmt);                                                \
        fflush(stdout);                                                     \
        end_capture(saved_fd, tmpf, &sys_buf, &sys_len);                    \
    } else {                                                                \
        fprintf(stderr, "begin_capture failed for system printf\n");        \
        exit(1);                                                            \
    }                                                                       \
    if (begin_capture(&saved_fd, &tmpf) == 0) {                             \
        r_ft = ft_printf(fmt);                                              \
        fflush(stdout);                                                     \
        end_capture(saved_fd, tmpf, &ft_buf, &ft_len);                      \
    } else {                                                                \
        fprintf(stderr, "begin_capture failed for ft_printf\n");            \
        free(sys_buf);                                                      \
        exit(1);                                                            \
    }                                                                       \
    compare_and_report(__FILE__, __LINE__, fmt,                             \
                       sys_buf, sys_len, r_sys,                             \
                       ft_buf, ft_len, r_ft);                               \
    free(sys_buf);                                                          \
    free(ft_buf);                                                           \
} while(0)

// --- Test suite ---
static void run_core_tests(void)
{
    // literals & percent
    RUN_TEST0("hello world\n");
    RUN_TEST0("%%\n");
    RUN_TEST("percent: [%%%c]\n", '!');

    // chars (including NUL)
    RUN_TEST("char: [%c]\n", 'A');
    RUN_TEST("nul: [%c]\n", '\0'); // writes a zero byte; captured correctly

    // strings
    RUN_TEST("str: [%s]\n", "hello");
    RUN_TEST("str.prec.3: [%.3s]\n", "abcdef");
    RUN_TEST("str.null: [%s]\n", (char*)NULL);
    RUN_TEST("str.null.prec.3: [%.3s]\n", (char*)NULL);

    // signed ints (%d/%i)
    RUN_TEST("d pos: [%d]\n", 42);
    RUN_TEST("d neg: [%d]\n", -42);
    RUN_TEST("i zero: [%i]\n", 0);
    RUN_TEST("d width 6: [%6d]\n", 42);
    RUN_TEST("d prec 5: [%.5d]\n", 42);
    RUN_TEST("d width 6 prec 5: [%6.5d]\n", 42);
    RUN_TEST("d left: [%-6d]\n", 42);
    RUN_TEST("d plus: [%+d]\n", 42);
    RUN_TEST("d space: [% d]\n", 42);
    RUN_TEST("d plus overrides space: [%+ d]\n", 42);
    RUN_TEST("d zero flag: [%010d]\n", -42);
    RUN_TEST("d zero ignored by precision: [%010.5d]\n", -42);
    RUN_TEST("d .0 with zero: [%.0d]\n", 0);
    RUN_TEST("d .0 width: [%5.0d]\n", 0);

    // unsigned
    RUN_TEST("u: [%u]\n", 3000000000u);
    RUN_TEST("u prec: [%.8u]\n", 123u);
    RUN_TEST("u width: [%8u]\n", 123u);
    RUN_TEST("u left: [%-8u]\n", 123u);
    RUN_TEST("u zero: [%08u]\n", 123u);
    RUN_TEST("u zero + prec: [%08.5u]\n", 123u);

    // hex (lower/upper) and hash
    RUN_TEST("x: [%x]\n", 0x2a);
    RUN_TEST("X: [%X]\n", 0x2a);
    RUN_TEST("x hash: [%#x]\n", 0x2a);
    RUN_TEST("x hash zero: [%#x]\n", 0);
    RUN_TEST("x width: [%8x]\n", 0x2a);
    RUN_TEST("x prec: [%.5x]\n", 0x2a);
    RUN_TEST("x width+prec: [%8.5x]\n", 0x2a);
    RUN_TEST("x left: [%-8x]\n", 0x2a);
    RUN_TEST("x zero: [%08x]\n", 0x2a);
    RUN_TEST("x hash+zero+width: [%#08x]\n", 0x2a);
    RUN_TEST("x .0 with zero: [%.0x]\n", 0);
    RUN_TEST("x .0 with nonzero: [%.0x]\n", 5);

    // pointer
    int local = 123;
    RUN_TEST("p: [%p]\n", &local);
    RUN_TEST("p null: [%p]\n", (void*)0);
    RUN_TEST("p width: [%20p]\n", &local);
    RUN_TEST("p left: [%-20p]\n", &local);

    // mixed
    RUN_TEST("mix: %d %s %x %c %%\n", -7, "ok", 0xBEEF, 'Z');
}

// Optional: extra edge cases & stress flags
static void run_extra_tests(void)
{
    RUN_TEST("rep flags: [%--10.5d]\n", 123);
    RUN_TEST("space+plus: [% +10d]\n", 123);
    RUN_TEST("zero with minus: [%-010d]\n", 123);
    RUN_TEST("large width: [%50s]\n", "abc");
    RUN_TEST("large prec: [%.20s]\n", "hello");
    RUN_TEST("width & .0 on string (ignored precision): [%10.s]\n", "hello");
}

int main(void)
{
    run_core_tests();
    run_extra_tests();

    printf("\n==== SUMMARY ====\n");
    printf("Total tests: %d\n", g_total);
    if (g_failed == 0) {
        printf("All tests passed ✅\n");
    } else {
        printf("Failed: %d ❌\n", g_failed);
    }
    return (g_failed != 0);
}
