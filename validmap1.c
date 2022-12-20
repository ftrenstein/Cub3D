/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:32 by renstein          #+#    #+#             */
/*   Updated: 2022/12/20 23:26:54 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void separation(int		begin, t_params    *all)
{
	size_map = all->countlines - begin;
	all->map = malloc(sizeof(char *) * size_map);
	if (!all->map)
		ft_clear(all);
	while (i < all->countlines)
	{
		ft_strcopy(all->map[i],all->all_file[i]);
	}
}


void    pars_params(t_params	*all)
{
	int i = 0;
	int j = 0;
	int f = 0;


	while (i < all->countlines)
	{
		if (all->all_file[i][j] == 'N' && all->all_file[i][++j] == 'O' && j++)
		{
			while (all->all_file[i][j] != '\n')
				all->nord[f] = all->all_file[i][j++];
			i++;
			all_file->part1++;
		}
		else if (all->all_file[i][j] == 'S' && all->all_file[i][++j] == 'O' && j++)
		{
			while (all->all_file[i][j] != '\n')
				all->sounth[f] = all->all_file[i][j++];
			i++;
			all_file->part1++;
		}
		else if (all->all_file[i][j] == 'W' && all->all_file[i][++j] == 'E' && j++)
		{
			while (all->all_file[i][j] != '\n')
				all->west[f] = all->all_file[i][j++];
			i++;
			all_file->part1++;
		}
		else if (all->all_file[i][j] == 'E' && all->all_file[i][++j] == 'A' && j++)
		{
			while (all->all_file[i][j] != '\n')
				all->east[f] = all->all_file[i][j++];
			i++;
			all_file->part1++;
		}
		else if (all->all_file[i][j] == 'F' && j++)
		{
			while (all->all_file[i][j] != '\n')
				all->color_floor[f] = all->all_file[i][j++];
			i++;
			all_file->part1++;
		}
		else if (all->all_file[i][j] == 'C' && j++)
		{
			while (all->all_file[i][j] != '\n')
				all->color_floor[f] = all->all_file[i][j++];
			i++;
			all_file->part1++;
		}
		else
			i++;
		if (all_file->part1 == 6)
			separation(i, &all);
	}
}