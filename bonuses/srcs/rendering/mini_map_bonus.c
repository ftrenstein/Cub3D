/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:11:58 by mlakenya          #+#    #+#             */
/*   Updated: 2023/03/29 00:28:57 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

static void	print_player_minimap(t_params *params)
{
	unsigned int	*dst;
	unsigned int	*pl_start;
	int				pl_x;
	int				pl_y;

	pl_x = (int)(((int)params->player->pos_x - 0.5f)
			* 7 + ((params->player->pos_x - (int)params->player->pos_x) * 7));
	pl_y = (int)(((int)params->player->pos_y - 0.5f)
			* 7 + ((params->player->pos_y - (int)params->player->pos_y) * 7));
	pl_start = (unsigned int *)params->img.addr + pl_y * WINDOW_W + pl_x;
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
	while (params->map[i / map_scale])
	{
		j = 0;
		while (params->map[i / map_scale][j]
				&& params->map[i / map_scale][j] != '\n')
		{
			if (params->map[i / map_scale][j] == '1')
				put_pixels(&dst, 25 << 24 | 44 << 16 | 49 << 8 | 47, map_scale);
			else
				dst += map_scale;
			j++;
		}
		dst = (unsigned int *)params->img.addr + i * WINDOW_W;
		i++;
	}
	print_player_minimap(params);
}
