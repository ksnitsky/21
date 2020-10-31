/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:13:11 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/30 17:13:12 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_math(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '/')
		return (a / b);
	else if (op == '%')
		return (a % b);
	else
		return (a * b);
}

int		ft_opcheck(char op)
{
	if (op == '+' || op == '-' || op == '/' || op == '%' || op == '*')
		return (op);
	else
		return (0);
}
