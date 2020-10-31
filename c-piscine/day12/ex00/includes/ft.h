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
# include <fcntl.h>

# define BUFF_SIZE 28672

void	ft_putstr(char *str, int n);

# define NO_FILE_MSG ("File name missing.\n")
# define T_MANY_MSG ("Too many arguments.\n")
# define R_ERR_MSG ("Cannot read file.\n")

#endif
