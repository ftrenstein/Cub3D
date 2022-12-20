/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renstein <renstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:24:49 by renstein          #+#    #+#             */
/*   Updated: 2022/12/20 23:25:29 by renstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

char    *ft_strcpy(char *s1, char *s2)
  {
      int i;
 
      i = 0;
      while (s2[i])
      {
          s1[i] = s2[i]; // so this will make s1 = to whatever s2 is looping through the string
          i++;
      }
      s1[i] = s2[i];  // now that we are finsihing looping though s1[i] will equal s2[i]
      return (s1);
  }