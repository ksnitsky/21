/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 11:45:01 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/03 11:45:03 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (ft_validate(argv[1]) == 0)
		write(2, "error\n", 6);
	else if (argc == 2)
		ft_parse(argv[1], ft_strlen(argv[1]), DICT);
	else if (argc == 3)
		ft_parse(argv[1], ft_strlen(argv[1]), argv[2]);
	else
		return (0);
}