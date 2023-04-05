/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_texture_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:53:34 by renstein          #+#    #+#             */
/*   Updated: 2023/04/05 16:54:03 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <ctype.h>

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

void	check_texture(void *img, char *name, t_params *all)
{
	if (img == NULL)
		ft_error(13, name, all);
}

void	texture_xpm(t_params *all)
{
	all->textures[1].img = mlx_xpm_file_to_image(all->mlx,
			all->nord, &all->textures[1].width, &all->textures[1].height);
	check_texture(all->textures[1].img, all->nord, all);
	all->textures[1].addr = mlx_get_data_addr(all->textures[1].img,
			&all->textures[1].bits_per_pixel, &all->textures[1].line_length,
			&all->textures[1].endian);
	all->textures[2].img = mlx_xpm_file_to_image(all->mlx,
			all->east, &all->textures[2].width, &all->textures[2].height);
	check_texture(all->textures[2].img, all->east, all);
	all->textures[2].addr = mlx_get_data_addr(all->textures[2].img,
			&all->textures[2].bits_per_pixel, &all->textures[2].line_length,
			&all->textures[2].endian);
	all->textures[3].img = mlx_xpm_file_to_image(all->mlx,
			all->south, &all->textures[3].width, &all->textures[3].height);
	check_texture(all->textures[3].img, all->south, all);
	all->textures[3].addr = mlx_get_data_addr(all->textures[3].img,
			&all->textures[3].bits_per_pixel, &all->textures[3].line_length,
			&all->textures[3].endian);
	all->textures[0].img = mlx_xpm_file_to_image(all->mlx,
			all->west, &all->textures[0].width, &all->textures[0].height);
	check_texture(all->textures[0].img, all->west, all);
	all->textures[0].addr = mlx_get_data_addr(all->textures[0].img,
			&all->textures[0].bits_per_pixel, &all->textures[0].line_length,
			&all->textures[0].endian);
}

int	valid_texture_path(char *dir, t_params *all)
{
	int	fd;

	if (ft_ending(dir, ".xpm") != 0)
		ft_error(9, dir, all);
	fd = open(dir, O_RDONLY);
	if (fd < 0)
		ft_error(9, dir, all);
	close(fd);
	return (1);
}

int	ft_alloc_memory(char *texture, char **dir, t_params *all)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (*dir != NULL)
		ft_error(0, NULL, all);
	while (ft_isspace(*texture))
		texture++;
	*dir = texture;
	while (*texture && *texture != '\n')
		texture++;
	if (*texture == '\n')
		*texture = '\0';
	valid_texture_path(*dir, all);
	return (1);
}
