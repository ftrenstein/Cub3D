/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:45 by renstein          #+#    #+#             */
/*   Updated: 2023/03/02 19:56:05 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


char**	ft_find_begin(int i, char **all_file)
{
	int j;

	j = 0;
	while (all_file[i])
	{
		while ((ft_isspace(all_file[i][j]) \
							|| all_file[i][j] == '1' || all_file[i][j] == '0') )
		{
			if (all_file[i][j] == '1' || all_file[i][j] == '0' )
				return(&all_file[i]);
			j++;
		}
		i++;
	}
	return ((char**)0);
}

// void	separation(int guess, t_params *all)
// {
// 	int begin = ft_find_begin(guess+1, all->all_file);
// 	int size_map = all->countlines - begin;
// 	all->map = malloc(sizeof(char *) * size_map + 1);
// 	if (!all->map)
// 		ft_clear(all);
// 	int i = begin;
// 	int j = 0;
// 	while (i < all->countlines && j < size_map)
// 	{
// 		all->map[j] = ft_strdup(all->all_file[i]);
// 		j++;
// 		i++;
// 	}

// }


int 	check_wall(char **map)
{
	printf("\t MAPA \t \n");

	int i = 0;
	while (map[i])
	{
		printf("\t %s\n", map[i]);
		i++;
	}
	return (0);
}




int	valid_map(int i, t_params *all)
{
	all->map = ft_find_begin(i+1, all->all_file);
	check_wall(all->map);
	// separation(i, all);
	// printf("%s\n", &map);
	return (0);
}
