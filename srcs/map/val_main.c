/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:32 by renstein          #+#    #+#             */
/*   Updated: 2023/03/29 20:06:36 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int	ft_ending(char *path_map)
{
	char *cub = ".cub";

	int	len = ft_strlen(path_map);
	if (len <= 5)
		return 1;
	// printf("%s\n", path_map);

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
	// int		i;
	char	*s;

	all->countlines = 0;
	// i = 0;
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


int	pars_params(t_params	*all)
{
	int		i;
	int		j;

	i = 0; //stroka
	j = 0; //stolbik - bukva
	while (all->count_par != 6)
	{
		if (all->all_file[i][j] == 'N' && all->all_file[i][j + 1] == 'O')
		{
			all->count_par += ft_alloc_memory(&all->all_file[i][j + 3], &all->nord);
			i++;
			printf("->nord -----%s\n", all->nord);
		}
		else if (all->all_file[i][j] == 'S' && all->all_file[i][j + 1] == 'O')
		{
			all->count_par += ft_alloc_memory(&all->all_file[i][j + 3], &all->south);
			i++;
			printf("->south -----%s\n", all->south);

		}
		else if (all->all_file[i][j] == 'W' && all->all_file[i][j + 1] == 'E')
		{
			all->count_par += ft_alloc_memory(&all->all_file[i][j + 3], &all->west);
			i++;
			printf("all->west -----%s\n", all->west);

		}
		else if (all->all_file[i][j] == 'E' && all->all_file[i][j + 1] == 'A')
		{
			all->count_par += ft_alloc_memory(&all->all_file[i][j + 3], &all->east);
			i++;
			printf("all->east -----%s\n", all->west);

		}
		else if (all->all_file[i][j] == 'F')
		{
			all->color_floor = ft_alloc_memory_color(all, &all->all_file[i][j + 2]);
			i++;
			printf("color floor %d\n", all->color_floor);
		}
		else if (all->all_file[i][j] == 'C')
		{
			all->color_sky = ft_alloc_memory_color(all, &all->all_file[i][j + 2]);
			i++;
			printf("color sky %d\n", all->color_sky);
			if (all->color_floor == all->color_sky)
				ft_error(1);
		}
		else if (all->all_file[i][j] != '\n')
			ft_error(3);
		else
			i++;
	}
	printf(" count line guess %d\n", i );
	return (i);
}

int	valid_main(char *path_map, t_params	*all)
{
	check_path(path_map);
	read_map(path_map, all);
	int i = pars_params(all);
	// texture_xpm(all);

	printf("%d\n", all->count_par);
	if (all->count_par == 6)
		return (valid_map(i, all));
	else
		ft_error(4);
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
