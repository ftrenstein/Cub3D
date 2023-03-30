/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:44:37 by renstein          #+#    #+#             */
/*   Updated: 2023/03/30 17:00:18 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void ft_check_wall(t_params *all, int i, int j)
{
	char **used;

	used = malloc(sizeoff(char *) * all->map_height)
	while( j< (i+1))
		used[j++] = ((char*)
	if(all->map[i][j] == '1')
		return(0);
	if(all->map[i][j+1] == '0' || all->map[i][j-1] all->map[i+1][j] all->map[i-1][j])

}