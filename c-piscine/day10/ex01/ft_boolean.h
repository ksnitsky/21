/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:22:47 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/26 15:22:49 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef enum
{
	true = 1,
	false = 0
}	t_bool;

# define TRUE	true
# define FALSE	false

# define EVEN(num) (num % 2 == 0)

# define EVEN_MSG ("I have an even number of arguments.\n")
# define ODD_MSG ("I have an odd number of arguments.\n")

# define SUCCESS (0)

#endif
