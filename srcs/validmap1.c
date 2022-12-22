/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:32 by renstein          #+#    #+#             */
/*   Updated: 2022/12/21 21:22:28 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void separation(int	begin, t_params    *all)
{
	int size_map = all->countlines - begin;
	all->map = malloc(sizeof(char *) * size_map);
	if (!all->map)
		ft_clear(all);
	int i = begin;
	int j = 0;
	while (i < size_map && j < size_map)
	{
		all->map[j] = ft_strjoin2(all->all_file[i]);
		j++;
		i++;
	}
}


void    pars_params(t_params	*all)
{
	int i = 0; //stroka
	int j = 0; //stolbik - bukva
	int f = 0;
	
	while (i < all->countlines)
	{
		if (!all->all_file[i])
			return ;
		if (all->all_file[i][j] == 'N' && all->all_file[i][++j] == 'O' && j++)
		{
			f = 0;
			all->nord = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->nord)
				return ;
			while (all->all_file[i][j] != '\n')
				all->nord[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}
		else if (all->all_file[i][j] == 'S' && all->all_file[i][++j] == 'O' && j++)
		{
			f = 0;
			all->south = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->south)
				return ;
			while (all->all_file[i][j] != '\n')
				all->south[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}

		else if (all->all_file[i][j] == 'W' && all->all_file[i][++j] == 'E' && j++)
		{
			f = 0;
			all->west = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->west)
				return ;
			while (all->all_file[i][j] != '\n')
				all->west[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}

		else if (all->all_file[i][j] == 'E' && all->all_file[i][++j] == 'A' && j++)
		{
			f = 0;
			all->east = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->east)
				return ;
			while (all->all_file[i][j] != '\n')
				all->east[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}

		else if (all->all_file[i][j] == 'F')
		{
			j += 2;
			f = 0;
			all->color_floor = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->color_floor)
				return ;
			while (all->all_file[i][j] != '\n')
				all->color_floor[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}

		else if (all->all_file[i][j] == 'C')
		{
			j += 2;
			f = 0;
			all->color_ceiling = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->color_ceiling)
				return ;
			while (all->all_file[i][j] != '\n')
				all->color_ceiling[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}
		else
			i++;

		if (all->part1 == 6)
		{
			separation(i, all);
			break;
		}
	}
}