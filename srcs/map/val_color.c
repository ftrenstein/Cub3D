/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:21:36 by renstein          #+#    #+#             */
/*   Updated: 2023/04/04 16:16:57 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	add_color(char *col, int shift, int *rgb)
{
	if (!col || col[0] < 48 || col[0] > 57)
		return (0);
	if (ft_atoi(col) >= 0 && ft_atoi(col) < 256)
		*rgb |= atoi(col) << shift;
	else
		return (0);
	return (1);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	add_colors(char **arr, t_params *all)
{
	int	rgb;

	rgb = 0;
	if (!add_color(arr[0], 16, &rgb))
	{
		free_array(arr);
		ft_error(10, NULL, all);
	}
	if (!add_color(arr[1], 8, &rgb))
	{
		free_array(arr);
		ft_error(10, NULL, all);
	}
	if (!add_color(arr[2], 0, &rgb))
	{
		free_array(arr);
		ft_error(10, NULL, all);
	}
	return (rgb);
}

int	valid_color(char *color_str, t_params *all)
{
	int		i;
	int		rgb;
	char	**arr;

	i = 0;
	while (color_str && ft_isspace(*color_str))
		color_str++;
	arr = ft_split(color_str, ',');
	while (arr[i])
		i++;
	if (i != 3)
	{
		free_array(arr);
		ft_error(10, NULL, all);
	}
	rgb = add_colors(arr, all);
	free_array(arr);
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
