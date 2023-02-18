/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:53:34 by renstein          #+#    #+#             */
/*   Updated: 2023/02/18 18:47:00 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <ctype.h>

void separation(int begin, t_params *all)
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

void texture_xpm(t_params *all)
{
	all->textures[1].img = mlx_xpm_file_to_image(all->mlx, all->nord, &all->textures[1].width, &all->textures[1].height);
	all->textures[1].addr = mlx_get_data_addr(all->textures[1].img, &all->textures[1].bits_per_pixel, &all->textures[1].line_length, &all->textures[1].endian);
	all->textures[2].img = mlx_xpm_file_to_image(all->mlx, all->east, &all->textures[2].width, &all->textures[2].height);
	all->textures[2].addr = mlx_get_data_addr(all->textures[2].img, &all->textures[2].bits_per_pixel, &all->textures[2].line_length, &all->textures[2].endian);
	all->textures[3].img = mlx_xpm_file_to_image(all->mlx, all->south, &all->textures[3].width, &all->textures[3].height);
	all->textures[3].addr = mlx_get_data_addr(all->textures[3].img, &all->textures[3].bits_per_pixel, &all->textures[3].line_length, &all->textures[3].endian);
	all->textures[0].img = mlx_xpm_file_to_image(all->mlx, all->west, &all->textures[0].width, &all->textures[0].height);
	all->textures[0].addr = mlx_get_data_addr(all->textures[0].img, &all->textures[0].bits_per_pixel, &all->textures[0].line_length, &all->textures[0].endian);
}

int valid_texture_path(t_params *all, char *dir)
{
	int fd;
	// printf("%s\n", dir);
	fd = 0;
	if ((fd = open(dir, O_RDONLY)) < 0)
	{
		close(fd);
		printf("Error path texture\n");
		return(0);
	}
	all->count_par++;
	return(1);
}

int ft_alloc_memory(t_params *all, char *texture, char **dir)
{
	int	i;
	int k = 0;
	i = 0;
	while(ft_isspace(*texture))
		texture++;
	*dir = calloc(ft_strlen(texture), sizeof(char));
	if (!*dir)
		return(0);
	while (texture[i] && texture[i] != '\n')
	{
		(*dir)[k] = texture[i];
		i++;
		k++;
	}
	printf("texture: %s\n", *dir);
	if (valid_texture_path(all, *dir))
		return(1);
	return (0);
}
