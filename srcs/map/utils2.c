/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:06:32 by renstein          #+#    #+#             */
/*   Updated: 2023/02/16 22:03:21 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

// ******************Part II******************//


// Разбитие строки *s на
// Массивы по символу c

// Отлавливаем утечки памяти

void	*leak_hunter(char **arr, int words_len)
{
	int	i;

	i = 0;
	if (words_len > 0)
	{
		while (i < words_len)
		{
			free(arr[i]);
			i++;
		}
	}
	free(arr);
	return (NULL);
}

// Подсчитываем общую длинну символов

int	sym_len(char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

// Подсчитываем количество слов

int	words_counter(char const *str, char c)
{
	int		i;
	int		counter;

	if (!str)
		return (0);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !(str[i + 1])))
			counter++;
		i++;
	}
	return (counter);
}

// Создаём слова и заполняем ими массив

char	**words_maker(char const *str, char **arr, char c, int words)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < words)
	{
		while (*str == c)
			str++;
		len = sym_len(str, c);
		arr[i] = NULL;
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (arr[i] == NULL)
			return (leak_hunter(arr, i));
		j = 0;
		while (j < len)
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char	const *s, char c)
{
	char	**arr;
	int		words;

	if (!s && !c)
		return (NULL);
	words = 0;
	if (c == '\0' && !s)
		return (0);
	words = words_counter(s, c);
	printf("count words %d\n", words);
	arr = NULL;
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	return (words_maker(s, arr, c, words));
}

// int				main(void)
// {
// 	char	**arr;
// 	unsigned int	i;

// 	i = 0;
// 	arr = ft_split("200,  100,0", ',');
// 	while (arr[i] != NULL)
// 	{

// 		printf("%s", arr[i]);
//         printf("%c", '\n');
// 		i++;
// 	}
// 	i = 0;
// 	// arr = ft_split("\0aa\0bbb", '\0');
// 	// if (arr == 0)
// 	// 	printf("%s\n", "null");
// 	// while (arr[i] != NULL)
// 	// {
// 	// 	printf("%s", arr[i]);
//     //     printf("%c", '\n');
// 	// 	i++;
// 	// }
// }