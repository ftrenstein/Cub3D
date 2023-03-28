/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:21:36 by renstein          #+#    #+#             */
/*   Updated: 2023/03/25 20:05:03 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <ctype.h>



int		valid_color(char *color_str)
{
	int i = 0;
	int		rgb;

	rgb = 0;
	char **arr;
	arr = ft_split(color_str, ',');
	while (arr[i])
	{
		if(atoi(arr[i]) >= 0 && atoi(arr[i]) < 256)
		{
			rgb |= atoi(arr[i]) << 16;
			i++;
		}
		if(atoi(arr[i]) >= 0 && atoi(arr[i]) < 256)
		{
			rgb |= atoi(arr[i]) << 8;
			i++;
		}
		if(atoi(arr[i]) >= 0 && atoi(arr[i]) < 256)
		{
			rgb |= atoi(arr[i]);
			i++;
		}
		else
			return(0);
	}
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return(rgb);
}

int		ft_alloc_memory_color(t_params *all, char *color_str)
{
	// printf("COLOR: %s\n", color_str);
	if (valid_color(color_str))
		all->count_par++;
	return(valid_color(color_str));
}