/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:45 by renstein          #+#    #+#             */
/*   Updated: 2023/02/18 18:27:40 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/cub3d.h"


void	check_wall(t_all *all)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < all->lenstr - 1)
		if (all->str[0][j++] != '1')
			ft_error(all);
	while (i < all->countlines)
		if (all->str[i++][0] != '1')
			ft_error(all);


	j = 0;
	i = 0;
	while (j < all->lenstr - 1)
		if (all->str[all->countlines - 1][j++] != '1')
			ft_error(all);
	while (i < all->countlines - 1)
		if (all->str[i++][all->lenstr - 2] != '1')
			ft_error(all);
}

void	check_form(t_all *all)
{
	int	i;

	i = 1;
	while (all->str[i] && i < all->countlines - 1)
	{
		if (ft_strlen(all->str[i]) != all->lenstr)
			ft_error(all);
		i++;
	}
	if ((i == all->countlines - 1) \
				&& (ft_strlen(all->str[i]) + 1 != all->lenstr))
		ft_error(all);
}

int	ft_check_znak(t_all *all, int i, int j)
{

	return (all->str[i][j] != 'E' && all->str[i][j] != 'C'
						&& all->str[i][j] != 'P' \
						&& all->str[i][j] != '1' && all->str[i][j] != '0');
}

void	check_main(t_all *all)
{
	t_counters	bam;

	bam.exit = 0;
	bam.player = 0;
	bam.i = 0;
	all->apple = 0;
	while (bam.i++ < all->countlines)
	{
		bam.j = 0;
		while (bam.j++ < all->lenstr - 1)
		{
			if (all->str[bam.i][bam.j] == 'E')
				bam.exit++;
			if (all->str[bam.i][bam.j] == 'C')
				all->apple++;
			if (all->str[bam.i][bam.j] == 'P')
				bam.player++;
			if (ft_check_znak(all, bam.i, bam.j))
				ft_error(all);
		}
	}
	if (bam.exit != 1 || all->apple < 1 || bam.player != 1)
		ft_error(all);
}

void	valid_map(t_all *all)
{
	check_main(all);
	check_form(all);
	check_wall(all);
}
