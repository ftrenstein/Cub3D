/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:44:37 by renstein          #+#    #+#             */
/*   Updated: 2023/04/03 18:35:13 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	ft_search(t_params *all, char **used, int i, int j)
{
	if (i > all->map_height || i < 0 || j > all->map_width || j < 0)
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
	used = malloc(all->map_height * sizeof(char *));
	while (k < all->map_height)
		used[k++] = (char *)malloc((sizeof(char *) * all->map_width));
	ft_memset(used, 0, sizeof(used));
	if (ft_search(all, used, i, j) == 1)
		ft_error(11, NULL);
}
