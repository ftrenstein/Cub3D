/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:02:02 by renstein          #+#    #+#             */
/*   Updated: 2022/12/24 23:18:59 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

static void	draw_ceiling_and_floor(t_params *params)
{
	unsigned int	*dst;
	unsigned int	i;
	int				shift;

	if ((int)params->player->dirZ < -WINDOW_H / 2)
		shift = -WINDOW_H / 2;
	else if ((int)params->player->dirZ > WINDOW_H / 2)
		shift = WINDOW_H / 2;
	else
		shift = (int)params->player->dirZ;
	dst = (unsigned int *)params->img.addr;
	i = (WINDOW_H / 2 - shift) * WINDOW_W + 1;
	int r = 200;
	int g = 230;
	int b = 255;
	int t = 255;
	while (--i > 0)
		*dst++ = (t << 24 | r << 16 | g << 8 | b);
	i = (WINDOW_H / 2 + shift) * WINDOW_W + 1;
	while (--i > 0)
		*dst++ = (t << 24 | 80 << 16 | 60 << 8 | 30);
}

void	ft_line(t_params *params, int i, double dist)
{
	unsigned int	*dst;
	unsigned int	*src;
	int				h;
	int				original_h;
	float			src_f;
	float			d_shift;
	int				h_shift;

	h = WINDOW_H / dist;
	original_h = h;
	src_f = 0.0f;
	d_shift = (float)params->textures[params->txt_index].height / h;
	
	src = (unsigned int *)params->textures[params->txt_index].addr;
	src += (int)(params->texture_w * params->textures[params->txt_index].width);
	int	start = ((WINDOW_H - h) / 2 - (int)params->player->dirZ);
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
		*dst = *(src + ((int)src_f) * params->textures[params->txt_index].width);
		//*dst = params->txt_index * 255 + (1 - params->txt_index) * (255 << 8);
		dst += WINDOW_W;
		src_f += d_shift;
	}
}

static void	put_pixels(unsigned int **dst, int colour, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		**dst = colour;
		(*dst)++;
		i++;
	}
}

void	print_player(t_params *params)
{
	unsigned int	*dst;
	unsigned int	*pl_start;
	int				plX;
	int				plY;

	plX =  (int)(((int)params->player->posX - 0.5f) * 7 + ((params->player->posX - (int)params->player->posX) * 7));
	plY =  (int)(((int)params->player->posY - 0.5f) * 7 + ((params->player->posY - (int)params->player->posY) * 7));
	pl_start = (unsigned int *)params->img.addr + plY * WINDOW_W + plX;
	dst = pl_start + 2;
	put_pixels(&dst, (255 << 24 | 220 << 16 | 49 << 8 | 47), 3);
	dst = pl_start + WINDOW_W + 1;
	put_pixels(&dst, (255 << 24 | 220 << 16 | 49 << 8 | 47), 5);
	dst = pl_start + 2 * WINDOW_W;
	put_pixels(&dst, (255 << 24 | 220 << 16 | 49 << 8 | 47), 7);
	dst = pl_start + 3 * WINDOW_W;
	put_pixels(&dst, (255 << 24 | 220 << 16 | 49 << 8 | 47), 7);
	dst = pl_start + 4 * WINDOW_W;
	put_pixels(&dst, (255 << 24 | 220 << 16 | 49 << 8 | 47), 7);
	dst = pl_start + 5 * WINDOW_W + 1;
	put_pixels(&dst, (255 << 24 | 220 << 16 | 49 << 8 | 47), 5);
	dst = pl_start + 6 * WINDOW_W + 2;
	put_pixels(&dst, (255 << 24 | 220 << 16 | 49 << 8 | 47), 3);
}

void	mini_map(t_params *params)
{
	int				i;
	int				j;
	unsigned int	*dst;
	int				map_scale;

	i = 0;
	map_scale = 7;
	dst = (unsigned int *)params->img.addr;
	while (params->map[i/ map_scale])
	{
		j = 0;
		while (params->map[i / map_scale][j] && params->map[i / map_scale][j] != '\n')
		{
			if (params->map[i / map_scale][j] == '1')
				put_pixels(&dst, 255 << 24 | 44 << 16 | 49 << 8 | 47, map_scale);
			else
				dst += map_scale;
			j++;
		}
		dst = (unsigned int *)params->img.addr + i * WINDOW_W;
		i++;
	}
	print_player(params);
}

void	ft_draw(t_params *params)
{
	params->img.img = mlx_new_image(params->mlx, WINDOW_W, WINDOW_H);
	params->img.addr = mlx_get_data_addr(params->img.img, &params->img.bits_per_pixel, &params->img.line_length, &params->img.endian);
	draw_ceiling_and_floor(params);
	ray_casting(params);
	mini_map(params);
	mlx_put_image_to_window(params->mlx, params->mlx_win, params->img.img, 0, 0);
	mlx_destroy_image(params->mlx, params->img.img);
}