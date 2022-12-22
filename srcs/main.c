/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:02:07 by renstein          #+#    #+#             */
/*   Updated: 2022/12/22 08:30:21 by renstein         ###   ########.fr       */
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
    read_map(argv[1], &all);

    pars_params(&all);

    int i = 0;
    printf("...\n.....\n.......\nThe MAP is:\n\n");
    
    while (all.map[i])
    {
        printf("%s", all.map[i]);
        i++;
    }

    
    printf("\n\ncheck part1, count term = %d\n", all.part1);
    // valid_map(&all);

    // Vova tut nasral
    all.move.up = 0;
    all.move.down = 0;
    all.move.left = 0;
    all.move.right = 0;
    all.move.rot_left = 0;
    all.move.rot_right = 0;
    all.player = (t_player *)malloc(sizeof(t_player));
    start_game(&all);
    printf("\n\nPlayer pos: %f, %f", all.player->posX, all.player->posY);
    
    return 0;    
}