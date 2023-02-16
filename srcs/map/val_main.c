/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:32 by renstein          #+#    #+#             */
/*   Updated: 2023/02/16 22:19:26 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	pars_params(t_params	*all)
{
	int i = 0; //stroka
	int j = 0; //stolbik - bukva

	while (i < all->countlines)
	{
		// if (!all->all_file[i])
		// 	return ;
		// printf("i = %d and j = %d\n", i,j);
		// printf("sign = %c, %c\n", all->all_file[i][j], all->all_file[i][j + 1]);
		if (all->all_file[i][j] == 'N' && all->all_file[i][j + 1] == 'O')
		{
			printf("first\n");
			ft_alloc_memory(all, &all->all_file[i][j + 3], &all->nord);
			i++;
		}
		else if (all->all_file[i][j] == 'S' && all->all_file[i][j + 1] == 'O')
		{
			ft_alloc_memory(all, &all->all_file[i][j + 3], &all->south);
			i++;
		}
		else if (all->all_file[i][j] == 'W' && all->all_file[i][j + 1] == 'E')
		{
			printf("threid\n");

			ft_alloc_memory(all, &all->all_file[i][j + 3], &all->west);
			i++;
		}
		else if (all->all_file[i][j] == 'E' && all->all_file[i][j + 1] == 'A')
		{
			ft_alloc_memory(all, &all->all_file[i][j + 3], &all->east);
			i++;
		}
		else if (all->all_file[i][j] == 'F')
		{
			ft_alloc_memory_col(all, &all->all_file[i][j + 2],  &all->color_floor);
			i++;
		}
		else if (all->all_file[i][j] == 'C')
		{
			ft_alloc_memory_col(all, &all->all_file[i][j + 2], &all->color_sky);
			i++;
		}
		else
			i++;
		// if (all->count_par == 6)
		// {
		// 	ft_find_map(all);
		// 	separation(i, all);
		// 	break;
		// }
	}
}

int	ft_ending(char *path_map)
{
	char *cub = ".cub";

	int	len = ft_strlen(path_map);
	if (len <= 5)
		return 1;
	printf("%s\n", path_map);

	// printf("%d\n", ft_strcmp(path_map + len  - 4, cub));
	return(ft_strcmp(path_map + len  - 4, cub));
}

void		check_path(char *path_map)
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
	int		i;
	char	*s;

	all->countlines = 0;
	i = 0;

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
	// all->all_file[j] = get_next_line(fd);

	while (j < all->countlines)
	{
				printf("line - %s\n", get_next_line(fd));
				j++;

	}

	all->all_file[j] = NULL;
	close (fd);
}

int	valid_main(char *path_map, t_params	*all)
{
	check_path(path_map);
	read_map(path_map, all);
	pars_params(all);
	return 0;
}

//check path map
// record file in array **all.file
/* 1) pars first line
2) val_texture / counter 4
3) pars color
4) val color
5) pars map
6) val map
*/