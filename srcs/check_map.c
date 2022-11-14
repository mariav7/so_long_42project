/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:32:14 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 13:07:16 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_characters(t_data *m)
{
	int	y;
	int	x;

	y = 0;
	while (m->map->map[y])
	{
		x = 0;
		while (m->map->map[y][x])
		{
			if (m->map->map[y][x] != m->map->c
				&& m->map->map[y][x] != m->map->wall
				&& m->map->map[y][x] != m->map->e
				&& m->map->map[y][x] != m->map->p
				&& m->map->map[y][x] != m->map->space)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static void	count_characters(t_data *m)
{
	int	y;
	int	x;

	y = 0;
	while (m->map->map[y])
	{
		x = 0;
		while (m->map->map[y][x])
		{
			if (m->map->map[y][x] == m->map->c)
				m->map->items++;
			else if (m->map->map[y][x] == m->map->e)
				count_exit(m, y, x);
			else if (m->map->map[y][x] == m->map->p)
			{
				m->map->player++;
				m->map->play_x = x;
				m->map->play_y = y;
			}
			x++;
		}
		y++;
		m->map->height++;
	}
	m->map->tmp_items = m->map->items;
}

static int	min_characters(t_data *m)
{
	count_characters(m);
	if (m->map->items < 1)
		return (0);
	if (m->map->exit < 1 || m->map->exit > 1)
		return (0);
	if (m->map->player < 1 || m->map->player > 1)
		return (0);
	return (1);
}

static int	is_rectangular(t_data *m)
{
	int	y;
	int	x;
	int	len_x;

	len_x = ft_strlen(m->map->map[0]);
	y = 0;
	while (m->map->map[y] != NULL)
	{
		x = 0;
		while (m->map->map[y][x])
			x++;
		if (x != len_x)
			return (0);
		y++;
	}
	m->map->width = len_x;
	return (1);
}

void	is_map_valid(t_data *m)
{
	if (!valid_characters(m))
		error_exit(m, ERR_MAP, NULL);
	if (!min_characters(m))
		error_exit(m, ERR_MAP2, NULL);
	if (!is_rectangular(m))
		error_exit(m, ERR_MAP3, NULL);
	if (!is_walled(m))
		error_exit(m, ERR_MAP4, NULL);
	if (!valid_path(m))
		error_exit(m, ERR_MAP5, NULL);
}
