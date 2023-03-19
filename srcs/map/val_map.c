/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:45 by renstein          #+#    #+#             */
/*   Updated: 2023/03/19 20:40:40 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


char**	ft_find_begin(int i, char **all_file)
{
	int j;

	while (all_file[i])
	{
		j = 0;
		while ((ft_isspace(all_file[i][j]) \
							|| all_file[i][j] == '1' || all_file[i][j] == '0') )
		{
			if (all_file[i][j] == '1' || all_file[i][j] == '0' )
				return(&all_file[i]);
			else if (all_file[i][j] != '\n')
				ft_error(4);
			j++;
		}
		i++;
	}
	return ((char**)0);
}


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
	// printf("%s\n", &map);
	return (0);
}
