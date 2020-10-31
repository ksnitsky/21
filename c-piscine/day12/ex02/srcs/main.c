/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:26:57 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/29 14:26:58 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		main(int argc, char *argv[])
{
	if (argc == 1 || argc == 3)
		ft_dog();
	else if (argc > 4)
		ft_tail(argc - 1, argv);
	else
		ft_tail(argc - 3, argv);
	return (0);
}
