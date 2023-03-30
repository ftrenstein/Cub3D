/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:32 by renstein          #+#    #+#             */
/*   Updated: 2023/03/30 13:57:03 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_path(char *path_map)
{
	if (ft_ending(path_map) != 0)
	{
		printf("Error : Wrong path not have '.cub' \n");
		exit(1);
	}
	if (open(path_map, O_RDONLY) < 0)
	{
		printf("Error : No such file or directory\n");
		exit(1);
	}
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
			ft_error(1, NULL);
	}
	else if (all->all_file[*i][j] == 'C')
	{
		all->color_sky = ft_alloc_memory_color(all,
				&all->all_file[(*i)++][j + 2]);
		if (all->color_floor == all->color_sky)
			ft_error(1, NULL);
	}
	else if (all->all_file[*i][j] != '\n')
		ft_error(3, all->all_file[*i]);
	else
		(*i)++;
}

int	pars_params(t_params	*all)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (all->count_par != 6)
	{
		if (all->all_file[i][j] == 'N' && all->all_file[i][j + 1] == 'O')
			all->count_par += ft_alloc_memory(&all->all_file[i++][j + 3],
					&all->nord);
		else if (all->all_file[i][j] == 'S' && all->all_file[i][j + 1] == 'O')
			all->count_par += ft_alloc_memory(&all->all_file[i++][j + 3],
					&all->south);
		else if (all->all_file[i][j] == 'W' && all->all_file[i][j + 1] == 'E')
			all->count_par += ft_alloc_memory(&all->all_file[i++][j + 3],
					&all->west);
		else if (all->all_file[i][j] == 'E' && all->all_file[i][j + 1] == 'A')
			all->count_par += ft_alloc_memory(&all->all_file[i++][j + 3],
					&all->east);
		else
			pars_params2(all, &i, j);
	}
	return (i);
}

int	valid_main(char *path_map, t_params	*all)
{
	int	i;

	check_path(path_map);
	read_map(path_map, all);
	i = pars_params(all);
	if (all->count_par == 6)
		return (valid_map(i, all));
	else
		ft_error(4, NULL);
	return (0);
}
