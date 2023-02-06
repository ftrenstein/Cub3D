/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:02:07 by renstein          #+#    #+#             */
/*   Updated: 2022/12/24 16:28:25 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cud3d.h"

int main(int argc, char **argv)
{
    t_params    all;

    all.part1 = 0;
    if (argc != 2)
    {
        write(2, "Wrong number of arguments!\n", 27);
        return (1);
    }
    all.mlx = mlx_init();
	all.mlx_win = mlx_new_window(all.mlx, WINDOW_W, WINDOW_H, "cub3d");
    read_map(argv[1], &all);
    valid_main(&all);

    
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
    all.player->dirZ = 0;
    start_game(&all);
    printf("\n\nPlayer pos: %f, %f", all.player->posX, all.player->posY);
    
    return 0;    
}