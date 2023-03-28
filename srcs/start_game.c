/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:13 by renstein          #+#    #+#             */
/*   Updated: 2023/03/26 04:24:41 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_position(t_params *params, double dirX, double dirY)
{
	params->player->dir_y = dirY;
	params->player->dir_x = dirX;
	params->player->plane_x = -(int)dirY * 0.66f;
	params->player->plane_y = (int)dirX * 0.66f;
}

static int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	find_player(t_params *params, int i, int j)
{
	while (params->map[i])
	{
		j = 0;
		while (params->map[i][j] && params->map[i][j] != '\n')
		{
			if (is_player(params->map[i][j]))
			{
				params->player->pos_x = j + 0.5f;
				params->player->pos_y = i + 0.5f;
				if (params->map[i][j] == 'N')
					set_player_position(params, 0.0f, -1.0f);
				if (params->map[i][j] == 'S')
					set_player_position(params, 0.0f, 1.0f);
				if (params->map[i][j] == 'E')
					set_player_position(params, 1.0f, 0.0f);
				if (params->map[i][j] == 'W')
					set_player_position(params, -1.0f, 0.0f);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_exit(t_params *params)
{
	my_free(params);
	exit(0);
}

void	start_game(t_params *params)
{
	find_player(params, 0, 0);
	mlx_loop_hook(params->mlx, &main_loop, params);
	mlx_hook(params->mlx_win, 2, 1L << 0, &ft_key_down, params);
	mlx_hook(params->mlx_win, 3, 2L << 0, &ft_key_up, params);
	mlx_hook(params->mlx_win, 17, 0L, ft_exit, params);
	mlx_loop(params->mlx);
}
