/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:21:36 by renstein          #+#    #+#             */
/*   Updated: 2023/04/03 22:04:36 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_color(char *col, int shift, int *rgb, t_params *all)
{
	if (!col || col[0] < 48 || col[0] > 57)
		ft_error(10, NULL, all);
	if (ft_atoi(col, all) >= 0 && ft_atoi(col, all) < 256)
		*rgb |= atoi(col) << shift;
	else
		ft_error(10, NULL, all);
}

int	valid_color(char *color_str, t_params *all)
{
	int		i;
	int		rgb;
	char	**arr;

	i = 0;
	rgb = 0;
	while (color_str && ft_isspace(*color_str))
		color_str++;
	arr = ft_split(color_str, ',');
	while (arr[i])
		i++;
	if (i != 3)
		ft_error(10, NULL, all);
	add_color(arr[0], 16, &rgb, all);
	add_color(arr[1], 8, &rgb, all);
	add_color(arr[2], 0, &rgb, all);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (rgb);
}

int	ft_alloc_memory_color(t_params *all, char *color_str)
{
	int	rgb;

	rgb = valid_color(color_str, all);
	if (rgb)
		all->count_par++;
	return (rgb);
}
