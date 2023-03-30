/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:51:13 by renstein          #+#    #+#             */
/*   Updated: 2023/03/30 14:16:57 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	ft_exit(t_params *params)
{
	my_free(params);
	exit(0);
}

void	start_game(t_params *params)
{
	mlx_loop_hook(params->mlx, &main_loop, params);
	mlx_hook(params->mlx_win, 2, 1L << 0, &ft_key_down, params);
	mlx_hook(params->mlx_win, 3, 2L << 0, &ft_key_up, params);
	mlx_hook(params->mlx_win, 17, 0L, ft_exit, params);
	mlx_loop(params->mlx);
}
