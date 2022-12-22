/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:13 by renstein          #+#    #+#             */
/*   Updated: 2022/12/22 08:27:32 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

static void	find_player(t_params *params)
{
	int	i = 0;
	while (params->map[i])
	{
		int j = 0;
		while (params->map[i][j] && params->map[i][j] != '\n')
		{
			if (params->map[i][j] == 'N' || params->map[i][j] == 'S' || params->map[i][j] == 'E' || params->map[i][j] == 'W')
			{
				params->player->posX = j + 0.5f;
				params->player->posY = i + 0.5f;
				if (params->map[i][j] == 'N')
				{
					params->player->dirY = -1.0f;
					params->player->dirX = 0.0f;
					params->player->planeX = 0.66f;
					params->player->planeY = 0.0f;
				}
				if (params->map[i][j] == 'S')
				{
					params->player->dirY = 1.0f;
					params->player->dirX = 0.0f;
					params->player->planeX = -0.66f;
					params->player->planeY = 0.0f;
				}
				if (params->map[i][j] == 'E')
				{
					params->player->dirY = 0.0f;
					params->player->dirX = 1.0f;
					params->player->planeX = 0.0f;
					params->player->planeY = 0.66f;
				}
				if (params->map[i][j] == 'W')
				{
					params->player->dirY = 0.0f;
					params->player->dirX = -1.0f;
					params->player->planeX = 0.0f;
					params->player->planeY = -0.66f;
				}
				return ;
			}
			j++;
		}
		i++;
	}
}

int ft_exit(t_params *params)
{
	exit(0);
}

void	start_game(t_params *params)
{	
	find_player(params);
	params->mlx = mlx_init();
	params->mlx_win = mlx_new_window(params->mlx, WINDOW_W, WINDOW_H, "cub3d");
	mlx_loop_hook(params->mlx, &main_loop, params);
	mlx_key_hook(params->mlx_win, &ft_key_up, params);
	mlx_hook(params->mlx_win, 2, 1L, &ft_key_down, params);
	mlx_hook(params->mlx_win, 17, 0L, ft_exit, params);
	mlx_loop(params->mlx);
}
