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
# include <errno.h>
# include <string.h>
# include <libgen.h>

# define BUFF_SIZE 28672

void	ft_tail(int argc, char *argv[]);
void	ft_dog(void);
void	ft_puterr(char *str, char *pname, char *fname);
int		ft_strlen(char *str);

#endif
