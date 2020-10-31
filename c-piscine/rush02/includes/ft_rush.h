/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 11:45:08 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/03 11:45:08 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 4096
# define DICT "includes/numbers.dict"

/*--main func--*/
char	*ft_parse(char *inp, int n, char *dict);

/*--helpers--*/
int		ft_validate(char *str);
int		ft_strlen(char *str);
int		ft_arrtos(int *a, int n);
int		ft_atoi(char *str);

/*--print functions--*/
void	ft_print_one(char *inp, char *arr);
void	ft_print_two(char *inp, char *arr);
void	ft_print_three(char *inp, char *arr);
void	ft_print(char *inp, char *arr, int n);
void	ft_print_pwr(int n, char *arr);
void	ft_print_pwr_mi(char *arr);
void	ft_print_pwr_th(char *arr);

#endif
