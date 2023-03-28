/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:23:25 by renstein          #+#    #+#             */
/*   Updated: 2023/03/26 16:44:20 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_free(t_params *all)
{
	free(all->nord);
	free(all->south);
	free(all->west);
	free(all->east);
	int i = 0;
	while (all->all_file[i])
		free(all->all_file[i++]);
	free(all->all_file);
	i = 0;
	mlx_destroy_image(all->mlx, all->textures[0].img);
	mlx_destroy_image(all->mlx, all->textures[1].img);
	mlx_destroy_image(all->mlx, all->textures[2].img);
	mlx_destroy_image(all->mlx, all->textures[3].img);
	mlx_destroy_window(all->mlx, all->mlx_win);
	free(all->player);
	free(all->mlx);
	ft_memset(&all, 0, sizeof(all));
	free(all);
}

void ft_error(int num)
{
	printf("ERROR %d\n", num);
	exit(0);
}
