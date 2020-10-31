SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

INCL	= includes/ft.h

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
RM		= rm -f
LIB		= ar rc

CFLAGS	= -Wall -Wextra -Werror -c

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

all:		make ${NAME}

make:		all

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
