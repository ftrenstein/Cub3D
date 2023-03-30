/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:21:36 by renstein          #+#    #+#             */
/*   Updated: 2023/03/30 13:00:57 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_color(char *col, int shift, int *rgb)
{
	if (atoi(col) >= 0 && atoi(col) < 256)
		*rgb |= atoi(col) << shift;
	else
		ft_error(10, NULL);
}

int	valid_color(char *color_str)
{
	int		i;
	int		rgb;
	char	**arr;

	i = 0;
	rgb = 0;
	arr = ft_split(color_str, ',');
	while (arr[i])
		i++;
	if (i != 3)
		ft_error(10, NULL);
	add_color(arr[0], 16, &rgb);
	add_color(arr[1], 8, &rgb);
	add_color(arr[2], 0, &rgb);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (rgb);
}

int	ft_alloc_memory_color(t_params *all, char *color_str)
{
	if (valid_color(color_str))
		all->count_par++;
	return (valid_color(color_str));
}
