/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:32 by renstein          #+#    #+#             */
/*   Updated: 2022/12/30 23:33:52 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

void	valid_texture(t_params	*all)
{
	int	height;
	int	width;
	int	fd;
	printf("%s\n", all->nord);
	if (fd = open(all->nord, O_RDONLY) < 0)
	{
		printf("Error path nord texture\n");
		ft_exit(all);
	}
	close(fd);
	printf("\n%s\n", all->east);
	if (fd = open(all->east, O_RDONLY) < 0)
	{
		printf("Error path east texture\n");
		ft_exit(all);
	}
	close(fd);
	if (fd = open(all->south, O_RDONLY) < 0)
	{
		printf("Error path south texture\n");
		ft_exit(all);
	}
	close(fd);
	if (fd = open(all->west, O_RDONLY)  < 0)
	{
		printf("Error path west texture\n");
		ft_exit(all);
	}
	close(fd);
	all->textures[1].img = mlx_xpm_file_to_image(all->mlx, all->nord, &all->textures[1].width, &all->textures[1].height);
	all->textures[1].addr = mlx_get_data_addr(all->textures[1].img, &all->textures[1].bits_per_pixel, &all->textures[1].line_length, &all->textures[1].endian);
	all->textures[2].img = mlx_xpm_file_to_image(all->mlx, all->east, &all->textures[2].width, &all->textures[2].height);
	all->textures[2].addr = mlx_get_data_addr(all->textures[2].img, &all->textures[2].bits_per_pixel, &all->textures[2].line_length, &all->textures[2].endian);
	all->textures[3].img = mlx_xpm_file_to_image(all->mlx, all->south, &all->textures[3].width, &all->textures[3].height);
	all->textures[3].addr = mlx_get_data_addr(all->textures[3].img, &all->textures[3].bits_per_pixel, &all->textures[3].line_length, &all->textures[3].endian);
	all->textures[0].img = mlx_xpm_file_to_image(all->mlx, all->west, &all->textures[0].width, &all->textures[0].height);
	all->textures[0].addr = mlx_get_data_addr(all->textures[0].img, &all->textures[0].bits_per_pixel, &all->textures[0].line_length, &all->textures[0].endian);
}


void separation(int	begin, t_params    *all)
{
	int size_map = all->countlines - begin;
	all->map = malloc(sizeof(char *) * size_map + 1);
	if (!all->map)
		ft_clear(all);
	int i = begin;
	int j = 0;
	while (i < all->countlines && j < size_map)
	{
		all->map[j] = ft_strdup(all->all_file[i]);
		j++;
		i++;
	}
}

	// int i;
	// int size_map;
	// int j;
	
	// // i = (int)begin_map(all);
	// i = 8;
	// size_map = all->countlines - i;
	// all->map = malloc(sizeof(char *) * size_map);
	// if (!all->map)
	// 	ft_clear(all);
	// j = 0;
	// while (i < all->countlines && j < size_map)
	// {
	// 	all->map[j] = ft_strdup(all->all_file[i]);
	// 	j++;
	// 	i++;
	// }


// int		begin_map(t_params	*all)
// {
// 	int i = all->countlines; //30
	
	
// 	while (i > 0)
// 	{
// 		if (all->all_file[i][0] == '\n' && all->all_file[i][1] == '\0')
// 			return (i);
// 		i--;
// 	}
// 	return (0);
// }

void    pars_params(t_params	*all)
{
	int i = 0; //stroka
	int j = 0; //stolbik - bukva
	int f = 0;
	
	while (i < all->countlines)
	{
		if (!all->all_file[i])
			return ;
		if (all->all_file[i][j] == 'N' && all->all_file[i][j + 1] == 'O' && all->all_file[i][j+2])
		{
			f = 0;
			all->nord = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->nord)
				return ;
			j += 3;
			while (all->all_file[i][j] != '\n')
				all->nord[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}
		else if (all->all_file[i][j] == 'S' && all->all_file[i][j + 1] == 'O' && all->all_file[i][j+2])
		{
			f = 0;
			all->south = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->south)
				return ;
			j += 3;
			while (all->all_file[i][j] != '\n')
				all->south[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}
		else if (all->all_file[i][j] == 'W' && all->all_file[i][j + 1] == 'E' && all->all_file[i][j+2])
		{
			f = 0;
			all->west = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->west)
				return ;
			j += 3;
			while (all->all_file[i][j] != '\n')
				all->west[f++] = all->all_file[i][j++];
			i++;
			all->part1++;
			j = 0;
		}

		else if (all->all_file[i][j] == 'E' && all->all_file[i][j + 1] == 'A' && all->all_file[i][j+2])
		{
			f = 0;
			all->east = malloc(sizeof(char) * ft_strlen(all->all_file[i]));
			if (!all->east)
				return ;
			j += 3;
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

int	ft_ending(char *path_map)
{
	char *cub = ".cub";

	int	len = ft_strlen(path_map);
	if (len <= 4)
		return 0;
	printf("%d\n", ft_strcmp(path_map + len  - 4, cub));
	return(ft_strcmp(path_map + len  - 4, cub));
}

int		check_path(char *path_map)
{
	
	if (ft_ending(path_map) == 0)
	{
		if (open(path_map, O_RDONLY))
			return 0;
	}
	else 
		return 0;
	
	
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
	while (j < all->countlines)
	{
		all->all_file[j++] = get_next_line(fd);
	}
	all->all_file[j] = NULL;
	close (fd);
}

int	valid_main(t_params	*all)
{
		pars_params(all);
		valid_texture(all);
		return 0;
}