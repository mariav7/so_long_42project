/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:56:08 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/09 17:31:07 by mflores-         ###   ########.fr       */
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

static void	check_validmap(t_data *d, int x, int y)
{
	char	*p;

	p = &d->tmp_map2[y][x];
	if (*p == 'E')
		d->valid_ex = 1;
	if (*p != '1')
	{
		if (*p == 'C')
			d->tmp_food_count--;
		*p = '.';
		if (d->tmp_map2[y][x + 1] != '1' &&
			d->tmp_map2[y][x + 1] != '.')
			ft_check_validmap(d, x + 1, y);
		if (d->tmp_map2[y][x - 1] != '1' &&
			d->tmp_map2[y][x - 1] != '.')
			ft_check_validmap(d, x - 1, y);
		if (d->tmp_map2[y - 1][x] != '1' &&
			d->tmp_map2[y - 1][x] != '.')
			ft_check_validmap(d, x, y - 1);
		if (d->tmp_map2[y + 1][x] != '1' &&
			d->tmp_map2[y + 1][x] != '.')
			ft_check_validmap(d, x, y + 1);
	}
}

void	ft_check_path(t_data *d)
{
	int	i;

	check_validmap(d, d->ply_x, d->ply_y);
	i = 0;
	while (d->tmp_map2[i])
	{
		free(d->tmp_map2[i]);
		i++;
	}
	free(d->tmp_map2);
	if (d->tmp_food_count != 0 || d->valid_ex != 1)
		ft_error("Error!\nThere isn't valid way to go exit!!!\n", d);
}