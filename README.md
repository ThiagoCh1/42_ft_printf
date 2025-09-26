# 42_ft_printf

Custom implementation of the `printf` function for the 42 curriculum.

## 📌 Project Overview
This project is part of the 42 school curriculum.  
It aims to recreate the standard C `printf` function with support for format specifiers, flags, width, and precision.  

The project is divided into two parts:
- **Mandatory**: Basic conversions (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`).
- **Bonus**: Implementing flags (`-`, `0`, `.`, width, precision, `#`, `+`, space).

---

## 🚀 Features
- Supports the following conversions:
  - `%c` → character
  - `%s` → string (handles `NULL` as `(null)`)
  - `%p` → pointer (prints `(nil)` for `NULL`)
  - `%d` / `%i` → signed decimal integer
  - `%u` → unsigned decimal integer
  - `%x` / `%X` → hexadecimal (lowercase/uppercase)
  - `%%` → literal `%`
- Bonus support for:
  - Flags: `-`, `0`, `#`, `+`, and space
  - Field width
  - Precision

---

## 🛠️ Compilation
Compile with:
```bash
make
```

This will generate `libftprintf.a`, which you can link with your own projects.

To test with the provided `main.c`:
```bash
cc -Wall -Wextra -Werror -I src -I 42_libft main.c libftprintf.a -o test
./test
```

---

## 📖 Usage
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Answer: %d\n", "world", 42);
    return (0);
}
```

---

## ✅ Testing
Compare outputs with the real `printf`.  
Special cases tested include:
- `%c` with `\0` character
- `%s` with `NULL`
- `%p` with `NULL` and precision
- Width and precision combinations
- Bonus flags (`-`, `0`, `#`, `+`, space)

---
