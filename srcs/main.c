/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:02:07 by renstein          #+#    #+#             */
/*   Updated: 2023/02/14 16:11:32 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_free(t_params *all)
{
	free(all->mlx);
	free(all->mlx_win);
	free(all->nord);
	free(all->south);
	free(all->west);
	free(all->east);
	free(all->textures);
	free(all->color_floor);
	free(all->color_sky);
	while (*all->all_file)
		free(all->all_file);
	while (*all->map)
		free(all->map);
	free(all->player);
	ft_memset(&all, 0, sizeof(all));
}

int main(int argc, char **argv)
{
	t_params all;

	ft_memset(&all, 0, sizeof(all));

	all.count_par = 0;
	if (argc != 2)
	{
		write(2, "Wrong number of arguments!\n", 27);
		return (1);
	}
	all.mlx = mlx_init();
	all.mlx_win = mlx_new_window(all.mlx, WINDOW_W, WINDOW_H, "cub3d");

	valid_main(argv[1], &all);

	int i = 0;
	printf("...\n.....\n.......\nThe MAP is:\n\n");

	while (all.map && all.map[i])
	{
		printf("%s", all.map[i]);
		i++;
	}

	// valid_map(&all);

	// Vova tut nasral
	all.move.up = 0;
	all.move.down = 0;
	all.move.left = 0;
	all.move.right = 0;
	all.move.rot_left = 0;
	all.move.rot_right = 0;
	all.move.rot_up = 0;
	all.move.rot_down = 0;
	all.player = (t_player *)malloc(sizeof(t_player));
	if (!all.player)
		ft_exit(&all);
	all.player->dir_z = 0;
	start_game(&all);
	printf("\n\nPlayer pos: %f, %f", all.player->pos_x, all.player->pos_y);

	return 0;
}