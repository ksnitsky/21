/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:38:56 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/25 20:39:06 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_arrtos(int *a, int n, int k);
int		ft_atoi(char *str);
int		ft_math(int a, int b, char op);
int		ft_opcheck(char o);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif
