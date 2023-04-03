/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:23:25 by renstein          #+#    #+#             */
/*   Updated: 2023/04/03 18:23:52 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	my_free(t_params *all)
{
	int	i;

	free(all->nord);
	free(all->south);
	free(all->west);
	free(all->east);
	i = 0;
	while (all->all_file[i])
		free(all->all_file[i++]);
	free(all->all_file);
	i = 0;
	while (i < all->map_height)
		free(all->map[i++]);
	free(all->map);
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

void	ft_error(int num, char *s)
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
	else if (num == 7)
		printf("Error: map can not contain empty lines!\n");
	else if (num == 8)
		printf("Error: two players on the map!\n");
	else if (num == 9)
		printf("Error: wrong texture path: %s!\n", s);
	else if (num == 10)
		printf("Error: wrong floor or ceiling colour!\n");
	else if (num == 12)
		printf("Error: map has to be surrounded by walls!\n");
	else
		printf("ERROR %d\n", num);
	exit(0);
}
