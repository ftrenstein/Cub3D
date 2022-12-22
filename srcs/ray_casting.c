/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:03:14 by renstein          #+#    #+#             */
/*   Updated: 2022/12/22 08:40:54 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

static void	init_ray(t_ray *ray, t_params *params, int i, double rayX, double rayY)
{
	if (rayX == rayY && rayX == 0)
	{
		ray->cameraX = 2 * i / (double)(WINDOW_W - 1) - 1;
		ray->dirX = params->player->dirX + params->player->planeX * ray->cameraX;
		ray->dirY = params->player->dirY + params->player->planeY * ray->cameraX;
	}
	else
	{
		ray->dirX = rayX;
		ray->dirY = rayY;
	}
	ray->mapX = (int)params->player->posX;
	ray->mapY = (int)params->player->posY;
	if (ray->dirX == 0)
		ray->deltaX = 1e30;
	else
		ray->deltaX = 1/ray->dirX;
	if (ray->dirY == 0)
		ray->deltaY = 1e30;
	else
		ray->deltaY = 1/ray->dirY;
	if(ray->dirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (params->player->posX - ray->mapX) * ray->deltaX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - params->player->posX) * ray->deltaX;
	}
	if(ray->dirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (params->player->posY - ray->mapY) * ray->deltaY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - params->player->posY) * ray->deltaY;
	}
}

double	ray(t_params *params, int i, double rayX, double rayY)
{
	t_ray	ray;

	init_ray(&ray, params, i, rayX, rayY);
	int hit = 0;
	int side;
	while(hit == 0)
	{
		if(ray.sideDistX * ray.sideDistX < ray.sideDistY * ray.sideDistY)
		{
			ray.sideDistX += ray.deltaX;
			ray.mapX += ray.stepX;
			side = 0;
		}
		else
		{
			ray.sideDistY += ray.deltaY;
			ray.mapY += ray.stepY;
			side = 1;
		}
		if(params->map[ray.mapY][ray.mapX] == '1') 
			hit = 1;
	}
	double perpWallDist;
	
	if(side == 0)
		perpWallDist = ray.sideDistX - ray.deltaX;
	else
		perpWallDist = ray.sideDistY - ray.deltaY;

	if (side == 0)
	{
		if (ray.deltaX > 0)
			params->txt_index = 0;
		else
			params->txt_index = 2;
	}
	else
	{
		if (ray.deltaY > 0)
			params->txt_index = 3;
		else
			params->txt_index = 1;
	}
	
	if (perpWallDist < 0)
		perpWallDist = -perpWallDist;
	
	return (perpWallDist);
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