NAME = cub3D

SRCS = main.c validmap.c gnl.c ft_paint_map.c
HEDEAR = cub3D.h

MLX = -Lmlx_linux -lmlx_Linux -L./mlx -Imlx_linux -lXext -lX11 -fsanitize=address  -lm -lz   -o
OBJ = $(SRCS:.c=.o)
CC  = cc
FLAGS = -Wall -Wextra -Werror -Imlx -g3 $(HEDEAR)

all : $(NAME)

%.o  : %.c  $(HEDEAR)
	$(CC) -Wall -Wextra -Werror -I $(HEDEAR) -Imlx_linux -g3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(NAME)

clean :
	@rm -rf : $(OBJ)

fclean : clean
	@rm -rf : $(NAME)
re: fclean all

.PHONY : all clean fclean re

# -fsanitize=address
