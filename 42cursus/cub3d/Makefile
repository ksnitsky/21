DIR			=	srcs/
SRC			=	cub3d.c \
				cub_parser.c \
				cub_parser_utils.c \
				cub_painter.c \
				cub_utils.c

SRCS 		=	$(SRC:%=$(DIR)%)

OBJS		=	$(SRCS:.c=.o)
HEAD		=	.

NAME		=	cub3d
LIBFT		=	libft
LIBFT_LIB	=	libft.a
MLX			=	mlx
MLX_LIB		=	libmlx.dylib

FLAGS		=	-Wall -Wextra -Werror
CUB_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

.c.o:		
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I$(LIBFT) -Imlx

$(NAME):	$(OBJS)
		make -C $(LIBFT)/
		mv $(LIBFT)/$(LIBFT_LIB) .
		make -C $(MLX)/
		cp $(MLX)/$(MLX_LIB) .
		$(CC) $(OBJS) $(CUB_FLAGS) $(LIBFT_LIB) -o $(NAME)

all:		$(NAME)

fclean:		clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

clean:		
		$(RM) $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
		make clean -C $(LIBFT)
		make clean -C $(MLX)

re:			fclean all

.PHONY:	all clean fclean re .c.o
