/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:05:06 by mlakenya          #+#    #+#             */
/*   Updated: 2023/03/29 00:28:54 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

	h = WINDOW_H / dist;
	src = (unsigned int *)params->textures[params->txt_index].addr;
	src += (int)(params->texture_w * params->textures[params->txt_index].width);
	ft_line2(params, i, h, src);
}
