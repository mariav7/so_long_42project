/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:56:08 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 15:20:28 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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

int	is_walled(t_data *m)
{
	int	i;

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

static void	check_path(t_data *m, int x, int y)
{
	char	*p;

	p = &m->map->tmp_map[y][x];
	if (*p == 'E')
		m->map->tmp_exit = 1;
	if (*p != '1')
	{
		if (*p == 'C')
			m->map->tmp_items--;
		*p = 'V';
		if (m->map->tmp_map[y][x + 1] != '1' &&
			m->map->tmp_map[y][x + 1] != 'V')
			check_path(m, x + 1, y);
		if (m->map->tmp_map[y][x - 1] != '1' &&
			m->map->tmp_map[y][x - 1] != 'V')
			check_path(m, x - 1, y);
		if (m->map->tmp_map[y - 1][x] != '1' &&
			m->map->tmp_map[y - 1][x] != 'V')
			check_path(m, x, y - 1);
		if (m->map->tmp_map[y + 1][x] != '1' &&
			m->map->tmp_map[y + 1][x] != 'V')
			check_path(m, x, y + 1);
	}
}

int	valid_path(t_data *m)
{
	check_path(m, m->map->play_x, m->map->play_y);
	free_strs(m->map->tmp_map);
	m->map->tmp_map = NULL;
	if (m->map->tmp_items != 0 || m->map->tmp_exit != 1)
		return (0);
	return (1);
}
