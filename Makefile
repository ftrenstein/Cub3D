NAME	= cub3d

HEDEAR	= includes/cub3d.h

MAIN		= main start_game

MOVEMENT	= keys

RAY_CASTING	= ray_casting

RENDERING	= draw mini_map line

MAP			= val_main val_texture val_color val_map gnl utils utils2 errors

SRCS	= $(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
		  $(addsuffix .c, $(addprefix srcs/movement/, $(MOVEMENT))) \
		  $(addsuffix .c, $(addprefix srcs/ray_casting/, $(RAY_CASTING))) \
		  $(addsuffix .c, $(addprefix srcs/rendering/, $(RENDERING))) \
		  $(addsuffix .c, $(addprefix srcs/map/, $(MAP)))

OBJ		= $(SRCS:.c=.o)

MLX		= -Lmlx_linux -lmlx_Linux -L./mlx -Imlx_linux -lXext -lX11 -lm -lz  -g

CC		= cc

FLAGS	=  -Imlx -g -I includes/ -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(HEDEAR)
	$(CC) $(OBJ) -o $(NAME) $(MLX)

%.o : %.c	$(HEDEAR)
	$(CC) $(CFLAGC) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: re
	@make clean
	@clear

.PHONY : all clean fclean re