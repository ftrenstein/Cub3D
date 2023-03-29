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


int 	check_map(char **map_start)
{
	printf("\t map_startA \t \n");

	int i = 0;
	while (map_start[i])
	{
		int j = 0;
		while (map_start[i][j])
		{
			if (map_start[i][j] != '1' && map_start[i][j] != '0' && map_start[i][j] != 'N' && map_start[i][j] != 'S' \
				&& map_start[i][j] != 'W' && map_start[i][j] != 'E' && !ft_isspace(map_start[i][j]))
				ft_error(6); //map_start_contain wrong simbol
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
	int i;
	int j;

	while (all->map_start[i])
	{
		if(ft_strlen(all->map_start[i]) > len)
			len = ft_strlen(all->map_start[i]);
		i++;
	}
	all->map = (char **)malloc(i * sizeof(char *));
	j = 0;
	while (j < i)
		all->map[j++] = (char *)malloc(len + 1);
	i = 0;
	while(all->map_start[i])
	{
		all->map[i] = all->map_start[i];
		i++;
	}
	return(0);
}

int	valid_map(int i, t_params *all)
{
	all->map_start = ft_find_begin(i+1, all->all_file);
	if(all->map_start == 0)
		ft_error(5);
	check_map(all->map_start);
	ft_make_rectangle(all);
	return (0);
}
