/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:32 by renstein          #+#    #+#             */
/*   Updated: 2023/04/03 20:57:23 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	check_path(char *path_map, t_params *all)
{
	int	fd;
	
	if (ft_ending(path_map, ".cub") != 0)
		ft_error(12, path_map, all);
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		ft_error(12, path_map, all);
	close(fd);
}

void	read_map(char *path_map, t_params *all)
{
	int		j;
	int		fd;
	char	*s;

	all->countlines = 0;
	fd = open(path_map, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		all->countlines++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	all->all_file = malloc(sizeof(char *) * (all->countlines + 1));
	if (!all->all_file)
		ft_clear(all);
	fd = open(path_map, O_RDONLY);
	j = 0;
	while (j < all->countlines)
		all->all_file[j++] = get_next_line(fd);
	all->all_file[j] = NULL;
	close (fd);
}

static void	pars_params2(t_params *all, int *i, int j)
{
	if (all->all_file[*i][j] == 'F')
	{
		all->color_floor = ft_alloc_memory_color(all,
				&all->all_file[(*i)++][j + 2]);
		if (all->color_floor == all->color_sky)
			ft_error(1, NULL, all);
	}
	else if (all->all_file[*i][j] == 'C')
	{
		all->color_sky = ft_alloc_memory_color(all,
				&all->all_file[(*i)++][j + 2]);
		if (all->color_floor == all->color_sky)
			ft_error(1, NULL, all);
	}
	else if (all->all_file[*i][j] != '\n')
		ft_error(3, all->all_file[*i], all);
	else
		(*i)++;
}

int	pars_params(t_params	*all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (all->count_par != 6 && all->all_file[i])
	{
		if (all->all_file[i][j] == 'N' && all->all_file[i][j + 1] == 'O')
			all->count_par += ft_alloc_memory(&all->all_file[i++][j + 3],
					&all->nord, all);
		else if (all->all_file[i][j] == 'S' && all->all_file[i][j + 1] == 'O')
			all->count_par += ft_alloc_memory(&all->all_file[i++][j + 3],
					&all->south, all);
		else if (all->all_file[i][j] == 'W' && all->all_file[i][j + 1] == 'E')
			all->count_par += ft_alloc_memory(&all->all_file[i++][j + 3],
					&all->west, all);
		else if (all->all_file[i][j] == 'E' && all->all_file[i][j + 1] == 'A')
			all->count_par += ft_alloc_memory(&all->all_file[i++][j + 3],
					&all->east, all);
		else
			pars_params2(all, &i, j);
	}
	return (i);
}

int	valid_main(char *path_map, t_params	*all)
{
	int	i;

	check_path(path_map, all);
	read_map(path_map, all);
	i = pars_params(all);
	if (all->count_par == 6)
		return (valid_map(i, all));
	else
		ft_error(4, NULL, all);
	return (0);
}
