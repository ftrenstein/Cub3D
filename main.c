/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:02:07 by renstein          #+#    #+#             */
/*   Updated: 2022/12/20 22:05:44 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_params    all;
    if (argc == 2)
    {
        read_map(argv[1], &all);
	    valid_map(&all);
	    all.mlx = mlx_init();
	    // all.mlx_win = mlx_new_window(all.mlx, 1200, 900, "so_long");
        
    }
    
    
}