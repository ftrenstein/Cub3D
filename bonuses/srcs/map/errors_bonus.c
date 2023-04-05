/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:23:25 by renstein          #+#    #+#             */
/*   Updated: 2023/04/05 16:40:06 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	my_free2(t_params *all)
{
	if (all->mlx)
	{
		if (all->textures[0].img)
			mlx_destroy_image(all->mlx, all->textures[0].img);
		if (all->textures[1].img)
			mlx_destroy_image(all->mlx, all->textures[1].img);
		if (all->textures[2].img)
			mlx_destroy_image(all->mlx, all->textures[2].img);
		if (all->textures[3].img)
			mlx_destroy_image(all->mlx, all->textures[3].img);
		mlx_destroy_window(all->mlx, all->mlx_win);
		mlx_destroy_display(all->mlx);
		free(all->mlx);
	}
	if (all->player)
		free(all->player);
	ft_memset(&all, 0, sizeof(all));
	free(all);
}

void	my_free(t_params *all)
{
	int	i;

	if (!all)
		return ;
	i = 0;
	if (all->all_file)
	{
		while (all->all_file[i])
			free(all->all_file[i++]);
		free(all->all_file);
	}
	i = 0;
	if (all->map)
	{
		while (i < all->map_height)
			free(all->map[i++]);
		free(all->map);
	}
	my_free2(all);
}

static void	ft_error2(int num, char *s)
{
	if (num == 7)
		printf("Error: map can not contain empty lines!\n");
	else if (num == 8)
		printf("Error: not one players on the map!\n");
	else if (num == 9)
		printf("Error: wrong texture path: %s!\n", s);
	else if (num == 10)
		printf("Error: wrong floor or ceiling colour!\n");
	else if (num == 11)
		printf("Error: the map is not limited by walls\n");
	else if (num == 12)
		printf("Error: wrong path for the map: %s!\n", s);
	else if (num == 13)
		printf("Error: bad texture file: %s!\n", s);
	else
		printf("ERROR %d\n", num);
}

void	ft_error(int num, char *s, t_params *all)
{
	if (num == 0)
		printf("Error: duplicate texture! Please check them\n");
	else if (num == 1)
		printf("Error: floor and ceiling must have different colours!\n");
	else if (num == 3)
		printf("Error: wrong config line: %s", s);
	else if (num == 4)
		printf("Error: wrong config file!\n");
	else if (num == 5)
		printf("Error: config file doesn't has a map!\n");
	else if (num == 6)
		printf("Error: map contains wrong symbols!\n");
	else
		ft_error2(num, s);
	my_free(all);
	exit (num + 1);
}
