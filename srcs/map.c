/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:32:14 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/08 17:25:08 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* static int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	printf("height: %d\n", i);
	return (i);
} */

static int valid_characters(t_data *m)
{
    int i;
    int x;

    i = 0;
    while (m->map->map[i])
    {
        x = 0;
        while(m->map->map[i][x])
        {
            if (m->map->map[i][x] != 'C' && m->map->map[i][x] != '1'
                && m->map->map[i][x] != 'E' && m->map->map[i][x] != 'P'
                && m->map->map[i][x] != '0')
                return (0);
            x++;
        }
        i++;
    }
    return (1);
}

static void count_characters(t_data *m)
{
    int y;
    int x;

    y = 0;
    while (m->map->map[y])
    {
        x = 0;
        while(m->map->map[y][x])
        {
            if (m->map->map[y][x] == 'C')
                m->map->items++;
            else if (m->map->map[y][x] == 'E')
                m->map->exit++;
            else if (m->map->map[y][x] == 'P')
                m->map->player++;
            x++;
        }
        y++;
        m->map->height++;
    }
}

static int min_characters(t_data *m)
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

static int is_rectangular(t_data *m)
{
    int y;
    int i;
    int *widths;

    y = 0;
    widths = (int *)ft_calloc(m->map->height, sizeof(int));
    while (m->map->map[y])
    {
        widths[y] = ft_strlen(m->map->map[y]);
        y++;
    }
    y = 0;
    while (y < m->map->height)
    {
        i = 1;
        while (i < m->map->height)
        {
            if (widths[y] > widths[i] || widths[y] < widths[i])
            {
                free(widths);
                return (0);
            }
            i++;
        }
        y++;
    }
    m->map->width = widths[0];
    free(widths);
    if (m->map->height >= m->map->width)
        return (0);
    return (1);
}

void is_map_valid(t_data *m)
{
    if (!valid_characters(m))
        error_exit(m, ERR_MAP);
    if (!min_characters(m))
        error_exit(m, ERR_MAP2);
    if (!is_rectangular(m))
        error_exit(m, ERR_MAP3);
}