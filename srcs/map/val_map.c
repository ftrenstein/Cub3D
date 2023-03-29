/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:45 by renstein          #+#    #+#             */
/*   Updated: 2023/03/28 17:56:55 by renstein         ###   ########.fr       */
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


int 	check_map(char **map)
{
	printf("\t MAPA \t \n");

	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' && map[i][j] != 'S' \
				&& map[i][j] != 'W' && map[i][j] != 'E' && !ft_isspace(map[i][j]))
				ft_error(6); //map_contain wrong simbol
			j++;
		}
		if (map[i][0] == '\n')
			ft_error(7);

		printf("\t %s\n", map[i]);
		i++;
	}
	return (0);
}




int	valid_map(int i, t_params *all)
{
	all->map = ft_find_begin(i+1, all->all_file);
	if(all->map == 0)
		ft_error(5);
	check_map(all->map);

	return (0);
}
