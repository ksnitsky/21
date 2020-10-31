/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxhoan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:24:08 by dxhoan            #+#    #+#             */
/*   Updated: 2020/10/06 16:26:35 by dxhoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define STDIN_MAP "stdin_map"

int		diff_printable_signs(char *empt, char *obst, char *full);
int		is_valid(int fd, int line_count, char *empt, char *obst);
int		take_first(int fd, char *empt, char *obst, char *full);
int		max_size(int j, int i, int max);
void	get_matrix(char *file_name);
int		validator(char *mapname);
void	insert_square(void);
void	print_square(void);
void	anti25lines(void);
void	find_max(void);
void	free_mem(void);
void	brain_f(void);

#endif
