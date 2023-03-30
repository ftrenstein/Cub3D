/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:19:11 by mlakenya          #+#    #+#             */
/*   Updated: 2023/03/30 00:36:21 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate(t_params *params, int dir)
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

static double	get_dir2(t_params *params, int up)
{
	if (up == 1)
	{
		if (params->move.left && !params->move.right)
			return (M_PI / 4 * 7);
		else if (params->move.right && !params->move.left)
			return (M_PI / 4);
		else
			return (0);
	}
	else
	{
		if (params->move.left && !params->move.right)
			return (M_PI / 4 * 5);
		else if (params->move.right && !params->move.left)
			return (M_PI / 4 * 3);
		else
			return (M_PI);
	}
}

double	*get_dir(t_params *params)
{
	double	*dir;
	double	angle;

	dir = (double *)malloc(sizeof(double) * 2);
	if (params->move.up && !params->move.down)
		angle = get_dir2(params, 1);
	else if (!params->move.up && params->move.down)
		angle = get_dir2(params, 0);
	else if (params->move.right && !params->move.left)
		angle = M_PI / 2;
	else if (params->move.left && !params->move.right)
		angle = M_PI / 2 * 3;
	else
	{
		dir[0] = 0;
		dir[1] = 0;
		return (dir);
	}
	dir[0] = params->player->dir_x * cos(angle)
		- params->player->dir_y * sin(angle);
	dir[1] = (params->player->dir_x * sin(angle)
			+ params->player->dir_y * cos(angle));
	return (dir);
}

void	move(t_params *params, double *vec)
{
	double	dx;
	double	dy;

	dx = vec[0] * MOVE_SPEED;
	dy = vec[1] * MOVE_SPEED;
	free(vec);
	if (params->player->pos_x + dx < 0
		|| params->player->pos_x + dx >= params->map_width)
		dx = 0;
	if (params->player->pos_y + dy < 0
		|| params->player->pos_y + dy >= params->map_height)
		dy = 0;
	params->player->pos_x += dx;
	params->player->pos_y += dy;
}
