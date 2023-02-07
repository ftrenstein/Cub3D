NAME	= cub3D

HEDEAR	= cub3d.h

MAIN		= main start_game

MOVEMENT	= keys

RAY_CASTING	= ray_casting

RENDERING	= draw mini_map

UTILS		= utils gnl

MAP			= validmap1

SRCS	= $(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
		  $(addsuffix .c, $(addprefix srcs/movement/, $(MOVEMENT))) \
		  $(addsuffix .c, $(addprefix srcs/ray_casting/, $(RAY_CASTING))) \
		  $(addsuffix .c, $(addprefix srcs/rendering/, $(RENDERING))) \
		  $(addsuffix .c, $(addprefix srcs/utils/, $(UTILS))) \
		  $(addsuffix .c, $(addprefix srcs/map/, $(MAP)))
		  
OBJ		= $(SRCS:.c=.o)

MLX		= -Lmlx_linux -lmlx_Linux -L./mlx -Imlx_linux -lXext -lX11 -lm -lz  -g -o

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