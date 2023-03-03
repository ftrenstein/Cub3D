/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:02:02 by renstein          #+#    #+#             */
/*   Updated: 2023/03/02 19:49:44 by renstein         ###   ########.fr       */
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
		*dst++ = (255 << 24 | 200 << 16 | 230 << 8 | 255);
	i = (WINDOW_H / 2 + shift) * WINDOW_W + 1;
	while (--i > 0)
		*dst++ = (255 << 24 | 80 << 16 | 60 << 8 | 30);
}

//*dst = params->txt_index * 255 + (1 - params->txt_index) * (255 << 8);

void	ft_line2(t_params *params, int i, int h, unsigned int *sr)
{
	int				start;
	float			src_f;
	unsigned int	*dst;
	float			d_shift;

	src_f = 0.0f;
	d_shift = (float)params->textures[params->txt_index].height / h;
	start = ((WINDOW_H - h) / 2 - (int)params->player->dir_z);
	if (start < 0)
	{
		h += start;
		src_f += d_shift * -start;
		start = 0;
	}
	else if (start > WINDOW_H)
		return ;
	if (start + h > WINDOW_H)
		h = WINDOW_H - start;
	dst = (unsigned int *)params->img.addr + i + start * WINDOW_W;
	while (h-- > 0)
	{
		*dst = *(sr + ((int)src_f) * params->textures[params->txt_index].width);
		dst += WINDOW_W;
		src_f += d_shift;
	}
}

void	ft_line(t_params *params, int i, double dist)
{
	unsigned int	*src;
	int				h;
	// float			src_f;
	// int				start; unused variable

	h = WINDOW_H / dist;
	// src_f = 0.0f;
	src = (unsigned int *)params->textures[params->txt_index].addr;
	src += (int)(params->texture_w * params->textures[params->txt_index].width);
	ft_line2(params, i, h, src);
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
