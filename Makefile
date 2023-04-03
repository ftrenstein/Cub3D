NAME	= cub3d

NAME_BONUS	= cub3d_bonus

HEADER	= includes/cub3d.h

MAIN		= main start_game

MOVEMENT	= keys move

RAY_CASTING	= ray_casting ray

RENDERING	= draw line

MAP			= val_main val_texture val_color val_map val_map2 gnl utils utils2 errors player

MINI_MAP = mini_map

SRCS	= $(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
		  $(addsuffix .c, $(addprefix srcs/movement/, $(MOVEMENT))) \
		  $(addsuffix .c, $(addprefix srcs/ray_casting/, $(RAY_CASTING))) \
		  $(addsuffix .c, $(addprefix srcs/rendering/, $(RENDERING))) \
		  $(addsuffix .c, $(addprefix srcs/map/, $(MAP)))

SRCS_BONUS	= $(addsuffix _bonus.c, $(addprefix bonuses/srcs/, $(MAIN))) \
			$(addsuffix _bonus.c, $(addprefix bonuses/srcs/movement/, $(MOVEMENT))) \
			$(addsuffix _bonus.c, $(addprefix bonuses/srcs/ray_casting/, $(RAY_CASTING))) \
			$(addsuffix _bonus.c, $(addprefix bonuses/srcs/rendering/, $(RENDERING))) \
			$(addsuffix _bonus.c, $(addprefix bonuses/srcs/map/, $(MAP))) \
			$(addsuffix _bonus.c, $(addprefix bonuses/srcs/rendering/, $(MINI_MAP)))

HEADER_BONUS = bonuses/includes/cub3d_bonus.h

OBJ_BONUS	= $(SRCS_BONUS:.c=.o)

OBJ		= $(SRCS:.c=.o)

MLX		= -Lmlx_linux -lmlx_Linux -L./mlx -Imlx_linux -lXext -lX11 -lm -lz  -g

CC		= cc

FLAGS	=  -Imlx -g -I includes/ -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME) $(MLX)

%.o : %.c	$(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

test: re
	@make clean
	@clear

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS) $(MLX)

.PHONY : all clean fclean re bonus