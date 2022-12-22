/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cud3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:05:41 by renstein          #+#    #+#             */
/*   Updated: 2022/12/22 08:38:50 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define BUFFER_SIZE 5000

# define WINDOW_W 700
# define WINDOW_H 480

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 64364
# define KEY_ESC 65307

# define ROTATION_SPEED 0.01f
# define MOVE_SPEED 0.01f

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;	
}			t_player;

typedef struct s_ray
{
	double	cameraX;
	double	dirX;
	double	dirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaX;
	double	deltaY;
	int		stepX;
	int		stepY;
}		t_ray;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_move
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rot_right;
	int	rot_left;
}		t_move;


typedef struct s_params
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		countlines;
	int		part1;
	
	char	*nord;
	char	*south;
	char	*west;
	char	*east;

	int		nord_fd;
	int		south_fd;
	int		west_fd;
	int		east_fd;

	char	*color_floor;
	char	*color_ceiling;
	char	**all_file;
	char	**map;

	int		txt_index;


	t_move		move;
	t_player	*player;
}t_params;

char	*get_next_line(int fd);
char	*get_last_line(char *s, int i, char *res);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin2(char *src);


void	read_map(char *path_map, t_params *all);

void	pars_params(t_params *all);

void	ft_clear(t_params *all);

// Vova tut nasral
void	start_game(t_params *params);
void	ft_draw(t_params *params);
void	ray_casting(t_params *params);
void	ft_line(t_params *params, int i, double dist);
int		ft_key_down(int key, t_params *params);
int		ft_exit(t_params *params);
int		ft_key_up(int key, t_params *params);
int		main_loop(t_params *params);
double	ray(t_params *params, int i, double rayX, double rayY);


// int		moveplayer(t_all	*all);
// void	ft_clear(t_all *all);
// void	valid_map(t_all *all);
// void	check_wall(t_all *all);
// void	check_form(t_all *all);
// void	check_main(t_all *all);
// void	ft_error(t_all *all);
// void	ft_exit(t_all *all);
// int		quit(void);
// int		ft_key(int key, t_all	*all);
// void	read_map(char *map, t_all *all);
// void	get_images(t_all *all);
// void	paint_map(t_all *all);

#endif