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

DIR			=	srcs/
SRC			=	ft_printf.c \
				prf_flags.c \
				prf_parse_flags.c \
				prf_parser.c \
				prf_utils.c \
				prf_flags.c \
				prf_parse_hex.c \
				prf_parse_int.c \
				prf_parse_pointer.c \
				prf_parse_str.c \
				prf_parse_uint.c 

SRCS 		=	$(SRC:%=$(DIR)%)

OBJS		=	$(SRCS:.c=.o)
HEAD		=	.

NAME		=	libftprintf.a
LIBFT		=	libft
LIBFT_LIB	=	libft.a

FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
LIB			=	ar -rcs

.c.o:		
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I$(HEAD) -I$(LIBFT)

$(NAME):	$(OBJS)
		make -C $(LIBFT)/
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
