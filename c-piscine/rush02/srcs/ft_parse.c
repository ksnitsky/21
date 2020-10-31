/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 11:48:35 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/31 12:08:48 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush.h"
#include <stdio.h>
char	*ft_parse(char *inp, int n, char *dict)
{
	int		file;
	ssize_t	ret;
	char	arr[BUFF_SIZE];
	int		i;
	char	temp[3];
	int 	k;

	i = 0;
	if ((file = open(dict, O_RDWR)) == -1)
	{
		write(2, "ERROR\n", 6);
		return (0);
	}
	else
		while ((ret = read(file, arr, BUFF_SIZE)) > 0);
	close(file);

	while (inp[i] != '\0' || n > 0)
	{
		k = n % 3;
		if (k == 2)
		{
			if (inp[i] == '1' || inp[i + 1] == '0')
				ft_print_two(&inp[i], arr);
			else
			{
				temp[0] = inp[i];
				temp[0 + 1] = '0';
				ft_print_two(temp, arr);
				ft_print_one(&inp[i + 1], arr);
			}
			if (n > 3 &&  n < 7)
				ft_print_pwr_th(arr);
			else if (n >= 7)
				ft_print_pwr(n, arr);
			n -= k;
			i += k;
		}
		else if (k == 1)
		{
			if (inp[i] != '0')
				ft_print_one(&inp[i], arr);
			if (inp[i] == '0')
				ft_print_one(&inp[i], arr);
			if (n > 3 &&  n < 7)
				ft_print_pwr_th(arr);
			else if (n >= 7)
				ft_print_pwr(n, arr);
			n -= k;
			i += k;
		}
		else if (k == 0)
		{
			if (inp[i] == '0' && inp[i + 1] == '0' && inp[i + 2] == '0');
			else
			{
				if (inp[i] != '0')
				{
					ft_print_one(&inp[i], arr);
					ft_print_pwr_mi(arr);
				}
				if ((inp[i + 1] == '1' || inp[i + 2] == '0'))
					ft_print_two(&inp[i + 1], arr);
				if (inp[i] == '0' && inp[i + 1] == '0' && inp[i + 2] != '0')
					ft_print_one(&inp[i + 2], arr);
				else if ((inp[i + 1] == '0' && inp[i + 2] == '0'))
				{
					ft_print_pwr_th(arr);
					break ;
				}
				else
				{
					temp[0] = inp[i + 1];
					temp[0 + 1] = '0';
					ft_print_two(temp, arr);
					ft_print_one(&inp[i + 2], arr);
				}
				if (n > 3 &&  n < 7)
					ft_print_pwr_th(arr);
				else if (n >= 7)
					ft_print_pwr(n, arr);
			}
			n -= 3;
			i += 3;
		}
	}
	write(1, "\n", 1);
	return (0);
}
