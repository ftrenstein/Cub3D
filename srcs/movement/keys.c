/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:25:15 by renstein          #+#    #+#             */
/*   Updated: 2023/02/07 09:28:00 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	rotate(t_params *params, int dir)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = params->player->dir_x;
	params->player->dir_x = params->player->dir_x
		* cos(ROTATION_SPEED * dir) - params->player->dir_y
		* sin(ROTATION_SPEED * dir);
	params->player->dir_y = old_dir_x
		* sin(ROTATION_SPEED * dir) + params->player->dir_y
		* cos(ROTATION_SPEED * dir);
	old_plane_x = params->player->plane_x;
	params->player->plane_x = params->player->plane_x
		* cos(ROTATION_SPEED * dir) - params->player->plane_y
		* sin(ROTATION_SPEED * dir);
	params->player->plane_y = old_plane_x
		* sin(ROTATION_SPEED * dir) + params->player->plane_y
		* cos(ROTATION_SPEED * dir);
}

static void	move(t_params *params, int dir)
{
	double	dir_x;
	double	dir_y;
	double	dx;
	double	dy;
	double	dist;
	double	pl_pos_x;
	double	pl_pos_y;

	pl_pos_x = params->player->pos_x;
	pl_pos_y = params->player->pos_y;



	dir_x = params->player->dir_x * cos(M_PI / 2 * dir)
		- params->player->dir_y * sin(M_PI / 2 * dir);
	dir_y = params->player->dir_x * sin(M_PI / 2 * dir)
		+ params->player->dir_y * cos(M_PI / 2 * dir);

	params->player->pos_x *= 0.45f ;
	params->player->pos_y *= 0.45f;

	dx = dir_x * MOVE_SPEED;
	dy = dir_y * MOVE_SPEED;


	if (dir_x > 0)
		dist = ray(params, (WINDOW_W - 1) / 2, 1, 0);
	else
		dist = ray(params, (WINDOW_W - 1) / 2, -1, 0);
	// if (dx > 0 && dist < 0.2f)
	// 	dx = dist - 0.2f;
	// if (dx < 0 && dist + dx < 0.2f)
	// 	dx = -dist + 0.2f;
	if (dist < fabs(dx))
		dx = 0;

	if (dir_y > 0)
		dist = ray(params, (WINDOW_W - 1) / 2, 0, 1);
	else
		dist = ray(params, (WINDOW_W - 1) / 2, 0, -1);
	// if (dy > 0 && dist - dy < 0.2f)
	// 	dy = dist - 0.2f;
	// if (dy < 0 && dist + dy < 0.2f)
	// 	dy = -dist + 0.2f;
	if (dist < fabs(dy))
		dy = 0;

	dist = ray(params, (WINDOW_W - 1) / 2, dir_x, dir_y);
	if (dist * dist < 0.16f && dx * dy != 0.0f)
		dy = 0.0f;

	params->player->pos_x = pl_pos_x + dx;
	params->player->pos_y = pl_pos_y + dy;
}

int	ft_key_down(int key, t_params *params)
{
	if (key == KEY_RIGHT)
		params->move.rot_right = 1;
	else if (key == KEY_LEFT)
		params->move.rot_left = 1;
	else if (key == KEY_W || key == KEY_UP)
		params->move.up = 1;
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
		params->move.up = 0;
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
	if (params->move.up)
		move(params, 0);
	if (params->move.right)
		move(params, 1);
	if (params->move.down)
		move(params, 2);
	if (params->move.left)
		move(params, 3);
	if (params->move.rot_up)
		if (params->player->dir_z > -WINDOW_H)
			params->player->dir_z -= ROTATION_SPEED * 400;
	if (params->move.rot_down)
		if (params->player->dir_z < WINDOW_H)
			params->player->dir_z += ROTATION_SPEED * 400;
	ft_draw(params);
	return (0);
}
