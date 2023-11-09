/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_render_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:59:48 by mflores-          #+#    #+#             */
/*   Updated: 2023/11/09 16:03:09 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	init_game(t_data *d)
{
	int	length;
	int	width;

	reg_images(d);
	mlx_get_screen_size(d->mlx_ptr, &length, &width);
	if (d->map->width * SIZE > length || d->map->height * SIZE > width)
	{
		free_mlx_images(d);
		error_exit(d, ERR_MAP6, NULL);
	}
	d->window = mlx_new_window(d->mlx_ptr, d->map->width * SIZE,
			d->map->height * SIZE, TITLE);
	if (d->window == NULL)
	{
		free_mlx_images(d);
		error_exit(d, ERR_MLX_WIN, NULL);
	}
	d->map->current_pos = 'F';
	put_images(d);
}

int	check_move(t_data *d, int y, int x)
{
	if (d->map->map[y][x] != '1')
	{
		if (d->map->map[y][x] == 'C')
			d->map->items--;
		else if (d->map->items == 0 && d->map->map[y][x] == 'E')
		{
			++(d->map->move_count);
			d->map->map[d->map->play_y][d->map->play_x] = '0';
			render_after_move(d);
			ft_putendl_fd(WIN, 1);
			free_n_exit_safe(d);
		}
		else if (d->map->map[y][x] == 'E' && d->map->items != 0)
			return (2);
		++(d->map->move_count);
		return (1);
	}
	return (0);
}

void display_map(t_map *map)
{
	int x;
	int y = 0;
    system("clear"); // Clear the terminal
	info_usage();
	ft_printf("Map:");
	while (map->map[y] && y < map->height)
	{
		x = 0;
		ft_printf("\t");
		while (map->map[y][x] && x < map->width)
		{
			ft_printf("%c", map->map[y][x]);
			x++;			
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n");
}

void	render_after_move(t_data *d)
{
	mlx_clear_window(d->mlx_ptr, d->window);
	put_images(d);
	display_map(d->map);
}
