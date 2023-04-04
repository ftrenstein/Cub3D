/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:44:37 by renstein          #+#    #+#             */
/*   Updated: 2023/04/04 16:17:17 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
