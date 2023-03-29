/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map_start.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:45 by renstein          #+#    #+#             */
/*   Updated: 2023/03/29 19:38:57 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


char**	ft_find_begin(int i, char **all_file)
{
	int j;

	while (all_file[i])
	{
		j = 0;
		while (ft_isspace(all_file[i][j]))
			j++;
		if (all_file[i][j] != '\0')
			return (&all_file[i]);
		i++;
	}
	return ((char**)0);
}

static int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	set_player_position(t_params *params, double dirX, double dirY)
{
	params->player->dir_y = dirY;
	params->player->dir_x = dirX;
	params->player->plane_x = -(int)dirY * 0.66f;
	params->player->plane_y = (int)dirX * 0.66f;
}

int 	check_map(char **map_start, t_params *params)
{
	printf("\t map_startA \t \n");

	int i = 0;
	while (map_start[i])
	{
		int j = 0;
		while (map_start[i][j])
		{
			if (map_start[i][j] != '1' && map_start[i][j] != '0' && !is_player(map_start[i][j]) \
					&& !ft_isspace(map_start[i][j]))
				ft_error(6); //map_start_contain wrong simbol
			if (is_player(map_start[i][j]))
			{
				if (params->player->pos_x != -1)
					ft_error(8); // Two players
				else
				{
					params->player->pos_x = j + 0.5f;
					params->player->pos_y = i + 0.5f;
					if (params->map[i][j] == 'N')
						set_player_position(params, 0.0f, -1.0f);
					if (params->map[i][j] == 'S')
						set_player_position(params, 0.0f, 1.0f);
					if (params->map[i][j] == 'E')
						set_player_position(params, 1.0f, 0.0f);
					if (params->map[i][j] == 'W')
						set_player_position(params, -1.0f, 0.0f);
				}
			}
			j++;
		}
		if (map_start[i][0] == '\n')
			ft_error(7);

		printf("\t %s\n", map_start[i]);
		i++;
	}
	return (0);
}


int	ft_make_rectangle(t_params *all)
{
	int len = 0;
	int i = 0;
	int j;

	while (all->map_start[i])
	{
		if(ft_strlen(all->map_start[i]) > len)
			len = ft_strlen(all->map_start[i]);
		i++;
	}
	printf("len %d\n", len);
	printf("count str %d\n", i + 1);

	all->map = (char **)malloc((i + 1) * sizeof(char *));
	j = 0;
	while (j < (i + 1))
		all->map[j++] = (char *)malloc(len + 1);
	i = 0;
	while(all->map_start[i])
	{
		j = 0;
		while (all->map_start[i][j])
		{
			all->map[i][j] = all->map_start[i][j];
			j++;
		}
		while (j < len)
			all->map[i][j++] = ' ';
		all->map[i][j] = '\0';
		i++;
	}
	return(0);
}

int	valid_map(int i, t_params *all)
{
	all->map_start = ft_find_begin(i+1, all->all_file);
	if(all->map_start == 0)
		ft_error(5);
	check_map(all->map_start, all);
	ft_make_rectangle(all);
	return (0);
}
