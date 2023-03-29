/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_texture_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:53:34 by renstein          #+#    #+#             */
/*   Updated: 2023/03/29 00:28:33 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <ctype.h>

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

int valid_texture_path(char *dir)
{
	int fd;
	// printf("%s\n", dir);
	fd = 0;
	if ((fd = open(dir, O_RDONLY)) < 0)
	{
		printf("Error path texture\n");
		return(0);
	}
	return(1);
}

int ft_alloc_memory( char *texture, char **dir)
{
	int	i;
	int k = 0;
	i = 0;
	if (*dir != 0)
		ft_error(0);
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
	if (valid_texture_path(*dir))
		return(1);
	return (0);
}
