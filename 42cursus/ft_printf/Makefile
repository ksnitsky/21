#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣶⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠿⢋⣉⠀⠀⠀⠀⠀⠉⠻⣷⡀⠀⠀⠀⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡿⠋⠀⢾⣿⡆⢠⣾⡿⢿⣦⢸⣿⣷⡀⠀⠀⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠁⠀⠀⠈⠉⠀⣾⡏⠀⠈⣿⡇⠀⠹⣷⠀⠀⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⣸⡟⠀⠀⠀⠀⠀⠀⢿⣇⠀⠀⣿⡇⠀⠀⢻⡇⠀⠀
#⠀⠀⠀⠀⠀⠀⠀⢰⣿⠀⠀⠀⠀⠀⠀⠀⠘⣿⣆⣰⣿⠃⠀⠀⣸⡇⠀⠀
#⠀⠀⠀⠀⠀⠀⣰⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⠃⠀⠀⢀⣿⠁⠀⠀
#⠀⠀⠀⠀⢀⣼⠟⠀⠻⣷⡀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠀⠀⠀⣾⠇⠀⠀⠀
#⠀⠀⠀⣰⡿⠋⠀⠀⠀⠘⠿⣶⣤⣤⡄⠀⠀⠀⠀⠀⠀⠀⢸⡿⠀⠀⠀⠀
#⠀⣠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⢸⣇⠀⠀⠀⠀
#⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡀⠀⠀⠀ 


SRCS		=	ft_printf.c	

OBJS		=	$(SRCS:.c=.o)
HEAD		=	.

NAME		=	libftprintf.a
LIBFT		=	libft
LIBFT_LIB	=	libft.a

FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
LIB			=	ar -rcs

.c.o:		
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I$(HEAD)

$(NAME):	$(OBJS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
		$(LIB) $(NAME) $(OBJS)

all:		$(NAME)

fclean:		clean
		$(RM) $(NAME) $(bonus)
		make fclean -C $(LIBFT)

clean:		
		$(RM) $(OBJS) $(OBJS_B)
		make clean -C $(LIBFT)

re:			fclean all

.PHONY:	all clean fclean re .c.o
