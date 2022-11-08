/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:56:08 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/08 20:30:46 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_col(char *line, char wall)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	if (line[0] != wall || line[i - 1] != wall)
		return (0);
	return (1);
}

static int	check_line(char *line, char wall)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != wall)
			return (0);
		i++;
	}
	return (1);
}

int is_walled(t_data *m)
{
  int i;
  
  if (!check_line(m->map->map[0], m->map->wall)
      || !check_line(m->map->map[m->map->height - 1], m->map->wall))
    return (0);
  i = 0;
  while (m->map->map[i])
  {
    if (!check_col(m->map->map[i], m->map->wall))
      return (0);
    i++;
  }
  return (1);
}