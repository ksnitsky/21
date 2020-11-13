/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:06:22 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/13 00:55:05 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# include <stdio.h>				// !!!!!!!!!!!!!!

typedef struct	s_tab
{
	int			dot;
	int			zero;
	int			minus;
	int			star;
	int			width;					/* "*." */
	int			precision;				/* ".*" */
	int			type;					/* cspdiuxX% */
}				t_tab;

int				ft_printf(const char *format, ...);
int				prf_parser(const char *format, va_list args);
int				prf_percent(char *str, int n);
int				prf_flags(const char *format, int i, t_tab *tab, va_list args);
t_tab			prf_flag_minus(t_tab tab);
t_tab			prf_flag_digit(char c, t_tab tab);
t_tab			prf_flag_width(va_list args, t_tab tab);
int				prf_flag_dot(const char *format, int i,
				t_tab *tab, va_list args);
t_tab			prf_init_tab(void);
int				prf_is_in_flags_list(int c);
int				prf_is_in_type_list(int c);

int				prf_parse_width(int width, int minus, int zero);
int				prf_parse_prec(char *str, int prec);
int				prf_type_parse(int c, t_tab tab, va_list args);

int				prf_parse_char(int c, t_tab tab);
int				prf_parse_string(char *str, t_tab tab);
int				prf_parse_int(int i, t_tab tab);
int				prf_parse_perc(t_tab tab);
int				prf_parse_hex(unsigned int ui, int lower, t_tab tab);
int				prf_parse_uint(unsigned int unsi, t_tab tab);
int				prf_parse_pointer(unsigned long long ull, t_tab tab);

char			*ft_ull_base(unsigned long long ull, int base);
char			*prf_str_tolower(char *str);
char			*prf_uitoa(unsigned int n);

#endif
