NAME	= cub3d

HEDEAR	= cub3d.h

MAIN		= main start_game

MOVEMENT	= keys

RAY_CASTING	= ray_casting

RENDERING	= draw mini_map

MAP			= val_main val_texture val_color val_map gnl utils utils2

SRCS	= $(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
		  $(addsuffix .c, $(addprefix srcs/movement/, $(MOVEMENT))) \
		  $(addsuffix .c, $(addprefix srcs/ray_casting/, $(RAY_CASTING))) \
		  $(addsuffix .c, $(addprefix srcs/rendering/, $(RENDERING))) \
		  $(addsuffix .c, $(addprefix srcs/map/, $(MAP)))

OBJ		= $(SRCS:.c=.o)

MLX		= -Lmlx_linux -lmlx_Linux -L./mlx -Imlx_linux -lXext -lX11 -lm -lz  -g -o

CC		= cc

FLAGS	=  -Imlx -g -I includes/ -Wall -Wextra -Werror #-fsanitize=address

all: $(NAME)



$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(MLX) $(NAME)

.c.o: $(HEDEAR)
	$(CC) $(FLAGS)  -c $< -o $@

clean:
	@rm -rf : $(OBJ)

fclean: clean
	@rm -rf : $(NAME)

re: fclean all

.PHONY : all clean fclean re