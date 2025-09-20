/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:18:46 by thribeir          #+#    #+#             */
/*   Updated: 2025/09/20 21:56:18 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*apply_width(char *s, t_format *fmt)
{
	int		len;
	char	*pad;
	char	*new_s;

	len = (int)ft_strlen(s);
	if (len < fmt -> width)
	{
		pad = ft_calloc((fmt -> width - len) + 1, 1);
		if (!pad)
			return (NULL);
		if (fmt -> zero_pad && !fmt -> has_precision && !fmt -> left_align)
			ft_memset(pad, '0', fmt -> width - len);
		else
			ft_memset(pad, ' ', fmt -> width - len);
		if (fmt -> left_align)
			new_s = ft_strjoin(s, pad);
		else
			new_s = ft_strjoin(pad, s);
		free(s);
		free(pad);
		return (new_s);
	}
	return (s);
}
