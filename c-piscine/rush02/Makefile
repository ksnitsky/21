# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 18:12:38 by tkathrin          #+#    #+#              #
#    Updated: 2020/09/28 18:12:41 by tkathrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_parse.c srcs/ft_validate.c srcs/ft_strlen.c srcs/ft_print.c srcs/main.c
HEAD	=	includes/ft_rush.h includes/numbers.dict
PNAME	= 	rush-02
OBJS	=	$(SRCS:.c=.o)

GCC		= 	gcc -Wall -Wextra -Werror
RM		=	rm -f

.PHONY:		all clean fclean re

.c.o:
			$(GCC) -c $< -o $(<:.c=.o)

$(PNAME):	$(OBJS) $(HEAD)
			$(GCC) -o $(PNAME) $(OBJS)

all:		$(PNAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(PNAME)

re:			fclean all
