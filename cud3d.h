/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cud3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:05:41 by renstein          #+#    #+#             */
/*   Updated: 2022/12/20 23:25:15 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>


typedef struct s_counters
{
	int	exit;
	int	player;
	int	i;
	int	j;
}t_counters;

typedef struct s_params
{
	void	*mlx;
	void	*mlx_win;
	int		countlines;
	int		part1;
	
	char	*nord;
	char	*south;
	char	*west;
	char	*east;

	int		*color_floor;
	int		*color_ceiling;
	char	**all_file;
	char	**map;

	
	
	

}t_params;

char	*get_next_line(int fd);
char	*get_last_line(char *s, int i, char *res);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1, char *s2);
char    *ft_strcpy(char *s1, char *s2);





int		moveplayer(t_all	*all);
void	ft_clear(t_all *all);
void	valid_map(t_all *all);
void	check_wall(t_all *all);
void	check_form(t_all *all);
void	check_main(t_all *all);
void	ft_error(t_all *all);
void	ft_exit(t_all *all);
int		quit(void);
int		ft_key(int key, t_all	*all);
void	read_map(char *map, t_all *all);
void	get_images(t_all *all);
void	paint_map(t_all *all);

#endif