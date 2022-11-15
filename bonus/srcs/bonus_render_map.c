/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_render_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:59:48 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/15 10:33:17 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	init_game(t_data *d)
{
	reg_images(d);
	d->window = mlx_new_window(d->mlx_ptr, d->map->width * 64,
			d->map->height * 64, TITLE);
	if (d->window == NULL)
		error_exit(d, ERR_MLX_WIN, NULL);
	d->map->current_pos = 'F';
	put_images(d);
}

int	check_move(t_data *d, int x, int y)
{
	if (d->map->map[y][x] != '1')
	{
		if (d->map->map[y][x] == 'C')
			d->map->items--;
		else if (d->map->items == 0 && d->map->map[y][x] == 'E')
		{
			++(d->map->move_count);
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

void	render_after_move(t_data *d)
{
	mlx_clear_window(d->mlx_ptr, d->window);
	put_images(d);
}
