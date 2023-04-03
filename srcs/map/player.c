/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:46:55 by mlakenya          #+#    #+#             */
/*   Updated: 2023/04/03 22:03:47 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	set_player_direction(t_params *params, double dirX, double dirY)
{
	params->player->dir_y = dirY;
	params->player->dir_x = dirX;
	params->player->plane_x = -(int)dirY * 0.66f;
	params->player->plane_y = (int)dirX * 0.66f;
}

void	set_player_position(t_params *params, int i, int j)
{
	if (params->player->pos_x != -1)
		ft_error(8, NULL, params);
	else
	{
		params->player->pos_x = j + 0.5f;
		params->player->pos_y = i + 0.5f;
		if (params->map_start[i][j] == 'N')
			set_player_direction(params, 0.0f, -1.0f);
		if (params->map_start[i][j] == 'S')
			set_player_direction(params, 0.0f, 1.0f);
		if (params->map_start[i][j] == 'E')
			set_player_direction(params, 1.0f, 0.0f);
		if (params->map_start[i][j] == 'W')
			set_player_direction(params, -1.0f, 0.0f);
	}
}
