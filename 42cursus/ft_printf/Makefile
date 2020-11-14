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
				prf_fmt_int.c \
				prf_fmt_uint.c \
				prf_fmt_char.c \
				prf_fmt_reg.c\
				prf_fmt_hex.c \
				prf_fmt_pointer.c \
				prf_fmt_percent.c \
				prf_fmt_str.c \
				prf_utils.c \
				prf_utils2.c \
				prf_utils3.c \
				prf_parse_flags.c \
				prf_parse_format.c \
				prf_parse.c

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
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

clean:		
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

re:			fclean all

.PHONY:	all clean fclean re .c.o
