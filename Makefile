NAME	= cub3D

SRCS	= srcs/main.c srcs/validmap1.c srcs/gnl.c srcs/utils.c srcs/start_game.c srcs/draw.c srcs/ray_casting.c srcs/keys.c
HEDEAR	= cub3D.h

MLX		= -Lmlx_linux -lmlx_Linux -L./mlx -Imlx_linux -lXext -lX11 -lm -lz  -g -o
OBJ		= $(SRCS:.c=.o)
CC		= cc
FLAGS	= -Wall -Wextra -Werror -Imlx -g -I includes/ #-fsanitize=address

all: $(NAME)

%.o: %.c $(HEDEAR)
	$(CC) $(FLAGS) $(MLX) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(MLX) $(NAME)

clean:
	@rm -rf : $(OBJ)

fclean: clean
	@rm -rf : $(NAME)

re: fclean all

.PHONY : all clean fclean re