/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:03:14 by renstein          #+#    #+#             */
/*   Updated: 2023/03/29 00:28:49 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	ray_casting(t_params *params)
{
	int	i;

	i = 0;
	while (i < WINDOW_W)
	{
		ft_line(params, i, ray(params, i, 0, 0));
		i++;
	}
}
