/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflint <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:06:22 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/11 19:55:56 by lflint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct	s_tab
{
	int			index;
	int			dot;
	const char	*format;
	va_list		args;					/* flags "-0.*" */
	int			width;					/* "*." */
	int			precision;				/* ".*" */
	char		c;						/* cspdiuxX% */
	int			length;					/* hz */
}				t_tab;

int				ft_printf(const char *format, ...);
int				prf_parser(t_tab *tab);
int				prf_percent(char *str, int n);
int				prf_flags(t_tab *tab);

#endif
