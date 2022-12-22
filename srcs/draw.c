/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:02:02 by renstein          #+#    #+#             */
/*   Updated: 2022/12/22 08:22:32 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

static void	draw_ceiling_and_floor(t_params *params)
{
	unsigned int	*dst;
	unsigned int	i;

	dst = (unsigned int *)params->img.addr;
	i = WINDOW_H * WINDOW_W / 2 + 1;
	int r = 200;
	int g = 230;
	int b = 255;
	int t = 255;
	int clr = (t << 24 | r << 16 | g << 8 | b);
	while (--i > 0)
		*dst++ = clr;
	i = WINDOW_H * WINDOW_W / 2 + 1;
	while (--i > 0)
		*dst++ = (t << 24 | 80 << 16 | 60 << 8 | 30);
}

void	ft_line(t_params *params, int i, double dist)
{
	unsigned int	*dst;
	//unsigned int	*src;
	unsigned int	h;
	//float			src_f;
	//float			d_shift;

	h = WINDOW_H / dist;
	//printf("\n%f %d\n", dist, i);
	//src_f = 0.0f;
	if (h > WINDOW_H)
	{
		h = WINDOW_H;
	}
	int up = (255 << 24 | 0 << 16 | 255 << 8 | 0);
	int down = (255 << 24 | 0 << 16 | 0 << 8 | 0);
	int left = (255 << 24 | 255 << 16 | 0 << 8 | 0);
	int right = (255 << 24 | 0 << 16 | 0 << 8 | 255);
	dst = (unsigned int *)params->img.addr + i + (WINDOW_H - (int)h) / 2 * WINDOW_W;
	while (h-- > 0)
	{
		if (params->txt_index == 0)
			*dst = left;
		if (params->txt_index == 1)
			*dst = up;
		if (params->txt_index == 2)
			*dst = right;
		if (params->txt_index == 3)
			*dst = down;
		dst += WINDOW_W;
	}
}

void	ft_draw(t_params *params)
{
	params->img.img = mlx_new_image(params->mlx, WINDOW_W, WINDOW_H);
	params->img.addr = mlx_get_data_addr(params->img.img, &params->img.bits_per_pixel, &params->img.line_length, &params->img.endian);
	draw_ceiling_and_floor(params);
	ray_casting(params);
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->img.img, 0, 0);
	mlx_destroy_image(params->mlx, params->img.img);
}