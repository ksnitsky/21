/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:13:07 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:21:15 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft.h"

# define PRF_TYPES "cspdiuxX%"
# define PRF_DEC "0123456789"
# define PRF_HEX_UP "0123456789ABCDEF"
# define PRF_HEX_LOW "0123456789abcdef"

typedef struct	s_flags
{
	int			count;
	size_t		*index;
	const char	*format;
	va_list		args;
	char		letter;
	int			done;
	int			valid;
	int			width;
	int			width_enabled;
	int			width_negative;
	char		width_char;
	int			precision;
	int			precision_enabled;
	int			precision_negative;
	int			minus_sign_used;
	int			side;
	int			forced_length;
	int			hex_upper;
}				t_flags;

int				ft_printf(const char *format, ...);
void			prf_parse(t_flags *flags);
void			prf_parse_flags(t_flags *flags, size_t start, size_t end);
void			prf_parse_format(t_flags *flags, size_t *index);
char			*prf_fmt_char(t_flags *flags);
char			*prf_fmt_str(t_flags *flags);
char			*prf_fmt_int(t_flags *flags);
char			*prf_fmt_pointer(t_flags *flags);
char			*prf_fmt_percent(t_flags *flags);
char			*prf_fmt_hex(t_flags *flags);
char			*prf_fmt_uint(t_flags *flags);
void			*prf_get_f_func(char key);
void			prf_putchar(t_flags *flags, char c);
void			prf_putstr(char *str, t_flags *flags, int length);
int				prf_strchr(const char *str, char c);
char			*prf_chrtostr(char c);
void			prf_init_flags(t_flags *flags);
void			prf_validate_flags(t_flags *flags);
int				prf_is_flag(char c);
char			*prf_empty_func(t_flags *flags);
char			*prf_chrmult(char c, size_t times);
char			*prf_strjoin_sided(char const *s1, char const *s2, int side);
char			*prf_memjoin(void *s1, size_t l1, void *s2, size_t l2);
int				prf_fmt_empty(int iszero, t_flags *flags);
char			*prf_put_pads(t_flags *flags, char *abs_itoa,
													int negative, int offset);

#endif
