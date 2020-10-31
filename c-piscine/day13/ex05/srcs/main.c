/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:44:31 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/30 13:44:32 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		main(int argc, char *argv[])
{
	int		a;
	int		b;
	char	op;

	if (argc != 4)
		return (0);
	else
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if ((op = ft_opcheck(*argv[2])) == 0 || argv[2][1] != '\0')
			write(1, "0", 1);
		else if (op == '/' && b == 0)
			write(2, "Stop : division by zero", 24);
		else if (op == '%' && b == 0)
			write(2, "Stop : modulo by zero", 22);
		else
			ft_putnbr(ft_math(a, b, op));
		write(1, "\n", 1);
		return (0);
	}
}
