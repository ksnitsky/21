#/**************************/
#/*░░░░░▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░*/
#/*░░░▓▓▓▓СКОРПЕНЫ▓▓░░░░░░░*/
#/*░░▓▓▓▓▒▒▒▒▓▒▒▒▒▓▓▓▓░░░░░*/
#/*░▓▓▓▓▒░░▓▓▓▒▄▓░▒▄▄▄▓░░░░*/
#/*▓▓▓▓▓▒░░▒▀▀▀▀▒░▄░▄▒▓▓░░░*/
#/*▓▓▓▓▓▒░░▒▒▒▒▒▓▒▀▒▀▒▓▒▓░░*/
#/*▓▓▓▓▓▒▒░░░▒▒▒░░▄▀▀▀▄▓▒▓░*/
#/*▓▓▓▓▓▓▒▒░░░▒▒▓▀▄▄▄▄▓▒▒▒▓*/
#/*░▓█▀▄▒▓▒▒░░░▒▒░░▀▀▀▒▒▒▒░*/
#/*░░▓█▒▒▄▒▒▒▒▒▒▒░░▒▒▒▒▒▒▓░*/
#/*░░░▓▓▓▓▒▒▒▒▒▒▒▒░░░▒▒▒▓▓░*/
#/*░░░░░▓▓▒░░▒▒▒▒▒▒▒▒▒▒▒▓▓░*/
#/*░42.fr▓▒▒░░░░▒▒▒▒▒▒▒▓▓░░*/
#/**************************/

SRCS		=	ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c 
SRCS_B		=	ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstadd_back.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstclear.c

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)
HEAD		=	.
NAME		=	libft.a

FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
LIB			=	ar -rcs

.c.o:		
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I$(HEAD)

$(NAME):	$(OBJS)
		$(LIB) $(NAME) $(OBJS)

all:	$(NAME)

bonus:	$(NAME) $(OBJS_B)
		$(LIB) $(NAME) $(OBJS_B)

fclean:		clean
		$(RM) $(NAME) $(bonus)

clean:		
		$(RM) $(OBJS) $(OBJS_B)

re:			fclean all

.PHONY:	all bonus clean fclean re .c.o
