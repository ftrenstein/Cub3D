/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:25:15 by renstein          #+#    #+#             */
/*   Updated: 2022/12/22 09:01:23 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

static void	rotate(t_params *params, int dir)
{
	double oldDirX = params->player->dirX;
	params->player->dirX = params->player->dirX * cos(ROTATION_SPEED * dir) - params->player->dirY * sin(ROTATION_SPEED * dir);
	params->player->dirY = oldDirX * sin(ROTATION_SPEED * dir) + params->player->dirY * cos(ROTATION_SPEED * dir);
	double oldPlaneX = params->player->planeX;
	params->player->planeX = params->player->planeX * cos(ROTATION_SPEED * dir) - params->player->planeY * sin(ROTATION_SPEED * dir);
	params->player->planeY = oldPlaneX * sin(ROTATION_SPEED * dir) + params->player->planeY * cos(ROTATION_SPEED * dir);
}

static void move(t_params *params, int dir)
{
	double	dirX;
	double	dirY;
	double	dx;
	double	dy;
	double	dist;

	dirX = params->player->dirX * cos(M_PI / 2 * dir) - params->player->dirY * sin(M_PI / 2 * dir);
	dirY = params->player->dirX * sin(M_PI / 2 * dir) + params->player->dirY * cos(M_PI / 2 * dir);

	dx = dirX * MOVE_SPEED;
	dy = dirY * MOVE_SPEED;
	
	if (dirX > 0)
		dist = ray(params, 0, 1, 0);
	else
		dist = ray(params, 0, -1, 0);
	if (dist * dist < dx * dx)
		dx = 0.0f;
	if (dirY > 0)
		dist = ray(params, 0, 0, 1);
	else
		dist = ray(params, 0, 0, -1);
	if (dist * dist < dy * dy)
		dy = 0.0f;
	dist = ray(params, 0, dirX, dirY);
	if (dist * dist < dx * dx + dy * dy)
		if (dx * dy != 0.0f)
			dy = 0.0f;
	
	params->player->posX += dx;
	params->player->posY += dy;
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
	else if (key == KEY_ESC)
		ft_exit(params);
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
	ft_draw(params);
	return (0);
}
