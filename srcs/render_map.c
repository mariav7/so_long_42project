/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:59:48 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/15 14:16:39 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_data *d)
{
	reg_images(d);
	d->window = mlx_new_window(d->mlx_ptr, d->map->width * SIZE,
			d->map->height * SIZE, TITLE);
	if (d->window == NULL)
		error_exit(d, ERR_MLX_WIN, NULL);
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
			ft_putstr_fd("Move: ", 1);
			ft_putnbr_fd(++(d->map->move_count), 1);
			ft_putstr_fd("\n", 1);
			ft_putendl_fd(WIN, 1);
			free_n_exit_safe(d);
		}
		else if (d->map->map[y][x] == 'E' && d->map->items != 0)
			return (2);
		ft_putstr_fd("Move: ", 1);
		ft_putnbr_fd(++(d->map->move_count), 1);
		ft_putstr_fd("\n", 1);
		return (1);
	}
	return (0);
}

void	render_after_move(t_data *d)
{
	mlx_clear_window(d->mlx_ptr, d->window);
	put_images(d);
}
