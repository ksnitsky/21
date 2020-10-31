/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:03:52 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/23 16:10:01 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_arrtos(int *a, int n, int k)
{
	int i;
	int nbr;

	i = 0;
	nbr = a[i];
	while (i < n - 1)
	{
		nbr = (nbr * 10) + a[i + 1];
		i++;
	}
	if (k % 2 == 0)
		return (nbr);
	else
		return (-nbr);
}

int		ft_atoi(char *str)
{
	int i;
	int j;
	int arr[10];

	i = 0;
	j = 0;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str == '-')
			i++;
		else if (*str >= 48 && *str <= 57)
			arr[j++] = *str - 48;
		else if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
			break ;
		str++;
	}
	if (j == 0)
		return (0);
	else
		return (ft_arrtos(arr, j, i));
}
