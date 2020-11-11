/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:06:22 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/11 17:21:36 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct
{
	char 	*str;
	int		width;
	int		precision;
	char	c;
	int		length;
}			t_flags;

int 		ft_printf(const char *, ...);
int			prf_percent(char *str);

#endif
