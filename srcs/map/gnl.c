/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:03:54 by renstein          #+#    #+#             */
/*   Updated: 2023/02/18 12:26:34 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	if (s1[0] != 0)
		free(s1);
	return (res);
}

char	*get_last_line(char *s, int i, char *res)
{
	if (s[0] != 0 && BUFFER_SIZE > 0)
	{
		s[i] = 0;
		res = ft_strjoin(res, s);
		s[0] = 0;
		return (res);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	s[BUFFER_SIZE + 1];
	char		*res;
	int			i;

	i = 0;
	res = "";
	s[0] = 0;
	if (read(fd, &s[i], 0) < 0)
	{
		printf("It is directory\n");
		exit (1);
	}
	while (read(fd, &s[i], 1) > 0 && i <= BUFFER_SIZE && BUFFER_SIZE > 0 && fd >= 0
		&& (fd < 100 || BUFFER_SIZE < 1000) && s[i] != 0)
	{
		if ((i + 1) == BUFFER_SIZE && s[i] != '\n' && s[i] != 0)
		{
			s[i + 1] = 0;
			res = ft_strjoin(res, s);
			i = -1;
		}
		if (s[i] == '\n')
		{
			s[i + 1] = 0;
			res = ft_strjoin(res, s);
			return (res);
		}
		i++;
	}
	return (get_last_line(s, i, res));
}
