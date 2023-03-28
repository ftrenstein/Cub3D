/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <mlakenya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:03:14 by renstein          #+#    #+#             */
/*   Updated: 2023/03/26 04:26:44 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
