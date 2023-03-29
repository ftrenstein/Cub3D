/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:02:07 by renstein          #+#    #+#             */
/*   Updated: 2023/03/29 21:46:28 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_params all;
	all.player = (t_player *)malloc(sizeof(t_player));
	all.player->pos_x = -1;

	ft_memset(&all, 0, sizeof(all));

	all.count_par = 0;
	if (argc != 2)
	{
		write(2, "Wrong number of arguments!\n", 27);
		return (1);
	}

	valid_main(argv[1], &all);
	int i = 0;
	// printf("...\n.....\n.......\nThe MAP is:\n\n");

	while (all.map && all.map[i])
	{
		// printf("%s", all.map[i]);
		i++;
	}
	// valid_map(&all);

	all.mlx = mlx_init();
	all.mlx_win = mlx_new_window(all.mlx, WINDOW_W, WINDOW_H, "cub3d");
	texture_xpm(&all);

	//Vova tut nasral
	all.move.up = 0;
	all.move.down = 0;
	all.move.left = 0;
	all.move.right = 0;
	all.move.rot_left = 0;
	all.move.rot_right = 0;
	all.move.rot_up = 0;
	all.move.rot_down = 0;
	all.show_map = 0;
	if (!all.player)
		ft_exit(&all);
	all.player->dir_z = 0;
	start_game(&all);

	return 0;
}