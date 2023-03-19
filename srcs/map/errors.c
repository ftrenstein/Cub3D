/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:23:25 by renstein          #+#    #+#             */
/*   Updated: 2023/03/19 17:48:05 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_free(t_params *all)
{
	free(all->mlx);
	free(all->mlx_win);
	free(all->nord);
	free(all->south);
	free(all->west);
	free(all->east);
	free(all->textures);
	// free(all->color_floor);
	// free(all->color_sky);
	while (*all->all_file)
		free(all->all_file);
	while (*all->map)
		free(all->map);
	free(all->player);
	ft_memset(&all, 0, sizeof(all));
}

void ft_error(int num)
{
	printf("ERROR %d\n", num);
	exit(0);
}
