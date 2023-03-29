/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:25:15 by renstein          #+#    #+#             */
/*   Updated: 2023/03/29 00:28:39 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	ft_key_down(int key, t_params *params)
{
	if (key == KEY_RIGHT)
		params->move.rot_right = 1;
	else if (key == KEY_LEFT)
		params->move.rot_left = 1;
	else if (key == KEY_W || key == KEY_UP)
		params->move.up += 1;
	else if (key == KEY_A)
		params->move.left = 1;
	else if (key == KEY_S || key == KEY_DOWN)
		params->move.down = 1;
	else if (key == KEY_D)
		params->move.right = 1;
	else if (key == 113)
		params->move.rot_up = 1;
	else if (key == 101)
		params->move.rot_down = 1;
	return (0);
}

int	ft_key_up(int key, t_params *params)
{
	if (key == KEY_RIGHT)
		params->move.rot_right = 0;
	else if (key == KEY_LEFT)
		params->move.rot_left = 0;
	else if (key == KEY_W || key == KEY_UP)
		params->move.up -= 1;
	else if (key == KEY_A)
		params->move.left = 0;
	else if (key == KEY_S || key == KEY_DOWN)
		params->move.down = 0;
	else if (key == KEY_D)
		params->move.right = 0;
	else if (key == 113)
		params->move.rot_up = 0;
	else if (key == 101)
		params->move.rot_down = 0;
	else if (key == KEY_M)
		params->show_map = (params->show_map - 1) * -1;
	else if (key == KEY_ESC)
		ft_exit(params);
	return (0);
}

int	main_loop(t_params *params)
{
	if (params->move.rot_right)
		rotate(params, 1);
	if (params->move.rot_left)
		rotate(params, -1);
	if (params->move.up || params->move.down
		|| params->move.left || params->move.right)
		move(params, get_dir(params));
	if (params->move.rot_up)
		if (params->player->dir_z > -WINDOW_H)
			params->player->dir_z -= ROTATION_SPEED * 400;
	if (params->move.rot_down)
		if (params->player->dir_z < WINDOW_H)
			params->player->dir_z += ROTATION_SPEED * 400;
	ft_draw(params);
	return (0);
}
