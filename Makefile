NAME	= cub3d

HEADER	= includes/cub3d.h

MAIN		= main start_game

MOVEMENT	= keys move

RAY_CASTING	= ray_casting ray

RENDERING	= draw line mini_map

MAP			= val_main val_texture val_color val_map gnl utils utils2 errors

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

%.o : %.c	$(HEADER)
	$(CC) $(CFLAGC) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: re
	@make clean
	@clear

bonus: $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME) $(MLX)

.PHONY : all clean fclean re bonus