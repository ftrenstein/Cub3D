/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:02:02 by renstein          #+#    #+#             */
/*   Updated: 2023/03/13 12:05:41 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_sky_and_floor(t_params *params)
{
	unsigned int	*dst;
	unsigned int	i;
	int				shift;

	if ((int)params->player->dir_z < -WINDOW_H / 2)
		shift = -WINDOW_H / 2;
	else if ((int)params->player->dir_z > WINDOW_H / 2)
		shift = WINDOW_H / 2;
	else
		shift = (int)params->player->dir_z;
	dst = (unsigned int *)params->img.addr;
	i = (WINDOW_H / 2 - shift) * WINDOW_W + 1;
	while (--i > 0)
		*dst++ = (params->color_sky);
	i = (WINDOW_H / 2 + shift) * WINDOW_W + 1;
	while (--i > 0)
		*dst++ = (params->color_floor);
}

void	ft_draw(t_params *params)
{
	params->img.img = mlx_new_image(params->mlx, WINDOW_W, WINDOW_H);
	params->img.addr = mlx_get_data_addr(params->img.img,
			&params->img.bits_per_pixel,
			&params->img.line_length, &params->img.endian);
	draw_sky_and_floor(params);
	ray_casting(params);
	mini_map(params);
	mlx_put_image_to_window(params->mlx,
		params->mlx_win, params->img.img, 0, 0);
	mlx_destroy_image(params->mlx, params->img.img);
}
