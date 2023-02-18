/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:03:14 by renstein          #+#    #+#             */
/*   Updated: 2023/02/18 11:41:03 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_ray	init_ray2(t_params *params, int i, double rayX, double rayY)
{
	t_ray	ray;

	if (rayX == rayY && rayX == 0)
	{
		ray.cam_x = 2 * i / (double)(WINDOW_W - 1) - 1;
		ray.dir_x = params->player->dir_x + params->player->plane_x * ray.cam_x;
		ray.dir_y = params->player->dir_y + params->player->plane_y * ray.cam_x;
	}
	else
	{
		ray.dir_x = rayX;
		ray.dir_y = rayY;
	}
	ray.map_x = (int)params->player->pos_x;
	ray.map_y = (int)params->player->pos_y;
	if (ray.dir_x == 0)
		ray.delta_x = 1e30;
	else
		ray.delta_x = 1 / ray.dir_x;
	if (ray.dir_y == 0)
		ray.delta_y = 1e30;
	else
		ray.delta_y = 1 / ray.dir_y;
	return (ray);
}

static t_ray	init_ray(t_params *params, int i, double rayX, double rayY)
{
	t_ray	ray;

	ray = init_ray2(params, i, rayX, rayY);
	if (ray.dir_x < 0)
	{
		ray.step_x = -1;
		ray.side_dist_x = (params->player->pos_x - ray.map_x) * ray.delta_x;
	}
	else
	{
		ray.step_x = 1;
		ray.side_dist_x = (ray.map_x + 1 - params->player->pos_x) * ray.delta_x;
	}
	if (ray.dir_y < 0)
	{
		ray.step_y = -1;
		ray.side_dist_y = (params->player->pos_y - ray.map_y) * ray.delta_y;
	}
	else
	{
		ray.step_y = 1;
		ray.side_dist_y = (ray.map_y + 1 - params->player->pos_y) * ray.delta_y;
	}
	return (ray);
}

static int	move_ray(t_ray *ray, t_params *params)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x
			* ray->side_dist_x < ray->side_dist_y * ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			side = 1;
		}
		if (params->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	return (side);
}

static double	get_distance(t_ray *ray, t_params *params, int side)
{
	double	dist;

	if (side == 0)
	{
		if (ray->delta_x > 0)
			params->txt_index = 0;
		else
			params->txt_index = 2;
		dist = fabs(ray->side_dist_x - ray->delta_x);
	}
	else
	{
		if (ray->dir_y > 0)
			params->txt_index = 3;
		else
			params->txt_index = 1;
		dist = fabs(ray->side_dist_y - ray->delta_y);
	}
	return (dist);
}

double	ray(t_params *params, int i, double rayX, double rayY)
{
	t_ray	ray;
	// double	block_w; unused variable
	double	perp_wall_dist;
	int		side;
	double	wall_x;

	ray = init_ray(params, i, rayX, rayY);
	side = move_ray(&ray, params);
	perp_wall_dist = get_distance(&ray, params, side);
	if (side == 0)
		wall_x = params->player->pos_y + perp_wall_dist * ray.dir_y;
	else
		wall_x = params->player->pos_x + perp_wall_dist * ray.dir_x;
	wall_x -= floor((wall_x));
	params->texture_w = wall_x;
	return (perp_wall_dist);
}

void	ray_casting(t_params *params)
{
	int	i;

	i = 0;
	while (i < WINDOW_W)
	{
		ft_line(params, i, ray(params, i, 0, 0));
		i++;
	}
}
