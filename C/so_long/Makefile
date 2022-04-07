NAME = so_long

MLX = ./libmlx.dylib

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC =	so_long.c \
		animation_utils.c \
		animation.c \
		check_map.c \
		ft_split.c \
		map.c \
		monster_moves.c \
		moves.c \
		utils.c \
		animation_utils2.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		make -C ./libft
		make -C ./ft_printf
		make -C ./mlx  && cp mlx/libmlx.dylib ../so_long
		$(CC) ${CFLAGS} $(OBJ) $(MLX) $(LIBFT) ${PRINTF} -o $(NAME)

all: $(NAME)

clean:
	${RM} $(OBJ)

fclean: clean
	${RM} $(NAME) ${OBJ} $(MLX)

cleanlib: clean
		make clean -C ./mlx && make fclean -C libft && make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re
