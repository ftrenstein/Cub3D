/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:05:41 by renstein          #+#    #+#             */
/*   Updated: 2023/02/19 16:57:11 by renstein         ###   ########.fr       */
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

# define WINDOW_W 1080
# define WINDOW_H 720

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

# define ROTATION_SPEED 0.03f
# define MOVE_SPEED 0.03f

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	dir_z;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_ray
{
	double	cam_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
}		t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		height;
	int		width;
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
	int	rot_up;
	int	rot_down;
}		t_move;

typedef struct s_params
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	int			countlines;
	int			count_par;
	char		*nord;
	char		*south;
	char		*west;
	char		*east;
	t_img		textures[4];
	// char		*color_floor;
	// char		*color_sky;
	char		**all_file;
	char		**map;
	int			txt_index;
	double		texture_w;
	t_move		move;
	t_player	*player;

	int			color_floor;
	int			color_sky;

}t_params;

// parsing
char	*get_next_line(int fd);
char	*get_last_line(char *s, int i, char *res);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_clear(t_params *all);
int		ft_isspace(int c);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char	const *s, char c);




int		valid_main(char *path_map, t_params	*all);
void	read_map(char *path_map, t_params *all);
int		pars_params(t_params *all);

int		ft_alloc_memory(char *texture, char **dir);
int		ft_alloc_memory_color(t_params *all, char *color_str);

int		valid_texture_path(char *dir);
void	texture_xpm(t_params *all);
void	my_free(t_params *all);

char**		ft_find_begin(int i, char **all_file);
int	valid_map(int i, t_params *all);
void separation(int begin, t_params *all);


// Vova tut nasral
void	start_game(t_params *params);
void	ft_draw(t_params *params);
void	mini_map(t_params *params);
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