/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:41:58 by mlakenya          #+#    #+#             */
/*   Updated: 2023/03/30 16:32:49 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**ft_find_begin(int i, char **all_file)
{
	int	j;

	while (all_file[i])
	{
		j = 0;
		while (ft_isspace(all_file[i][j]))
			j++;
		if (all_file[i][j] != '\0')
			return (&all_file[i]);
		i++;
	}
	return ((char **)0);
}

int	check_map(char **map_start, t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (map_start[i])
	{
		j = 0;
		while (map_start[i][j])
		{
			if (map_start[i][j] != '1' && map_start[i][j] != '0'
					&& !is_player(map_start[i][j])
					&& !ft_isspace(map_start[i][j]))
				ft_error(6, NULL);
			if (is_player(map_start[i][j]))
			{
				ft_check_wall(map_start, i, j);
				set_player_position(params, i, j);
			}
			j++;
		}
		if (map_start[i][0] == '\n')
			ft_error(7, NULL);
		i++;
	}
	return (0);
}

static void	copy_map(char **src, char **dst, int len)
{
	int	i;
	int	j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		while (j < len)
			dst[i][j++] = ' ';
		dst[i][j] = '\0';
		i++;
	}
}

int	ft_make_rectangle(t_params *all)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = 0;
	while (all->map_start[i])
	{
		if (ft_strlen(all->map_start[i]) > len)
			len = ft_strlen(all->map_start[i]);
		i++;
	}
	all->map_height = i;
	all->map_width = len - 1;
	all->map = (char **)malloc((i + 1) * sizeof(char *));
	j = 0;
	while (j < (i + 1))
		all->map[j++] = (char *)malloc(len + 1);
	copy_map(all->map_start, all->map, len);
	return (0);
}

int	valid_map(int i, t_params *all)
{
	all->map_start = ft_find_begin(i, all->all_file);
	if (all->map_start == 0)
		ft_error(5, NULL);
	check_map(all->map_start, all);
	ft_make_rectangle(all);
	ft_check_wall(all);
	return (0);
}
