/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:44:37 by renstein          #+#    #+#             */
/*   Updated: 2023/04/05 16:54:16 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	ft_search(t_params *all, char **used, int i, int j)
{
	if (i >= all->map_height || i < 0 || j >= all->map_width || j < 0)
		return (1);
	if (all->map[i][j] == '1')
		return (0);
	if (used[i][j] == '1')
		return (0);
	used[i][j] = '1';
	if (ft_search(all, used, i, j + 1) == 1)
		return (1);
	if (ft_search(all, used, i, j - 1) == 1)
		return (1);
	if (ft_search(all, used, i + 1, j) == 1)
		return (1);
	if (ft_search(all, used, i - 1, j) == 1)
		return (1);
	return (0);
}

int	ft_ending(char *path_map, char *end)
{
	int		len;

	len = ft_strlen(path_map);
	if (len <= 5)
		return (1);
	return (ft_strcmp(path_map + len - 4, end));
}

void	ft_check_wall(t_params *all, int i, int j)
{
	char	**used;
	int		k;

	k = 0;
	used = malloc((all->map_height + 1) * sizeof(char *));
	while (k < all->map_height)
	{
		used[k++] = (char *)malloc((sizeof(char *) * all->map_width));
		ft_memset(used[k - 1], 0, all->map_width);
	}
	if (ft_search(all, used, i, j) == 1)
	{
		k = 0;
		while (k < all->map_height)
			free(used[k++]);
		free(used);
		ft_error(11, NULL, all);
	}
	k = 0;
	while (k < all->map_height)
		free(used[k++]);
	free(used);
}
