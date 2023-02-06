/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:25:15 by renstein          #+#    #+#             */
/*   Updated: 2022/12/25 01:20:02 by renstein         ###   ########.fr       */
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
	double	plPosX;
	double	plPosY;

	dirX = params->player->dirX * cos(M_PI / 2 * dir) - params->player->dirY * sin(M_PI / 2 * dir);
	dirY = params->player->dirX * sin(M_PI / 2 * dir) + params->player->dirY * cos(M_PI / 2 * dir);

	dx = dirX * MOVE_SPEED;
	dy = dirY * MOVE_SPEED;
	if (dirX > 0)
		dist = ray(params, 0, 1, 0);
	else
		dist = ray(params, 0, -1, 0);
	if (dx > 0 && dist - dx < 0.2f)
		dx = dist - 0.2f;
	if (dx < 0 && dist + dx < 0.2f)
		dx = -dist + 0.2f;
	if (dirY > 0)
		dist = ray(params, 0, 0, 1);
	else
		dist = ray(params, 0, 0, -1);
	if (dy > 0 && dist - dy < 0.2f)
		dy = dist - 0.2f;
	if (dy < 0 && dist + dy < 0.2f)
		dy = -dist + 0.2f;
	dist = ray(params, 0, dirX, dirY);
	if (dist * dist < 0.16f)
		if (dx * dy != 0.0f)
			dy = 0.0f;


	plPosX = params->player->posX;
	plPosY = params->player->posY;
	params->player->posX += dx;
	params->player->posY += dy;
	if (dx != 0)
	{
		printf("\nCurr pos: %f %f", plPosX, plPosY);
		printf("\nNext pos: %f %f", params->player->posX, params->player->posY);
		printf("\n-----------------------------");
		if (ray(params, 0, 0, -1) < 0.2f
			|| ray(params, 0, 0, 1) < 0.2f)
			dx = 0;
	}
	if (dy != 0)
	{
		if (ray(params, 0, -1, 0) < 0.2f
			|| ray(params, 0, 1, 0) < 0.2f)
			dy = 0;
	}

	params->player->posX = plPosX + dx;
	params->player->posY = plPosY + dy;
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
		if (params->player->dirZ > -WINDOW_H)
			params->player->dirZ -= ROTATION_SPEED * 400;
	if (params->move.rot_down)
		if (params->player->dirZ < WINDOW_H)
			params->player->dirZ += ROTATION_SPEED * 400;
	ft_draw(params);
	return (0);
}
