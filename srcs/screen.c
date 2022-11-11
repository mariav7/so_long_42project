/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:47:55 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/11 15:51:58 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	in_image(t_data *d)
{
	d->player_f = mlx_xpm_file_to_image(d->mlx_ptr, PL_FE,
			&d->imgx, &d->imgy);
	d->player_b = mlx_xpm_file_to_image(d->mlx_ptr, PL_BE,
			&d->imgx, &d->imgy);
	d->player_l = mlx_xpm_file_to_image(d->mlx_ptr, PL_LE,
			&d->imgx, &d->imgy);
	d->player_r = mlx_xpm_file_to_image(d->mlx_ptr, PL_RE,
			&d->imgx, &d->imgy);
	d->backg = mlx_xpm_file_to_image(d->mlx_ptr, BACKG,
			&d->imgx, &d->imgy);
	d->food = mlx_xpm_file_to_image(d->mlx_ptr, FOODS,
			&d->imgx, &d->imgy);
	d->exit = mlx_xpm_file_to_image(d->mlx_ptr, EXIT,
			&d->imgx, &d->imgy);
	d->wall = mlx_xpm_file_to_image(d->mlx_ptr, WAL,
			&d->imgx, &d->imgy);
	if (!d->player_f || !d->player_b || !d->player_l || !d->player_r
		|| !d->backg || !d->food || !d->exit || !d->wall)
		error_exit(d, ERR_MLX);
	d->window = mlx_new_window(d->mlx_ptr, d->map->width * 64, \
		d->map->height * 64, TITLE);
	if (d->window == NULL)
		error_exit(d, ERR_MLX);
	d->map->current_pos = 'F';
	put_image(d);
}

static void	xy_oper(int *x, int *y, t_data *d)
{
	if (*x == d->map->width * 64)
	{
		*x = -64;
		*y += 64;
	}
	*x += 64;
}

static void	put_image_player(t_data *d, int x, int y)
{
	if (d->map->current_pos == 'F')
		mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_f, x, y);
	else if (d->map->current_pos == 'R')
		mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_r, x, y);
	else if (d->map->current_pos == 'L')
		mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_l, x, y);
	else if (d->map->current_pos == 'B')
		mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_b, x, y);
}

static void	score(t_data *d)
{
	d->map->move_count_screen = ft_itoa(d->map->move_count);
	mlx_string_put(d->mlx_ptr, d->window, 30, 30, 0xFFFFFF, \
	"Move: ");
	mlx_string_put(d->mlx_ptr, d->window, 65, 30, 0xFFFFFF, \
		d->map->move_count_screen);
	free(d->map->move_count_screen);
}

void	put_image(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < d->map->height * 64)
	{
		if (d->map->map[y / 64][x / 64] != '1'
			&& d->map->map[y / 64][x / 64] != '0')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->backg, x, y);
		if (d->map->map[y / 64][x / 64] == '1')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->wall, x, y);
		else if (d->map->map[y / 64][x / 64] == '0')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->backg, x, y);
		else if (d->map->map[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->exit, x, y);
		else if (d->map->map[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->food, x, y);
		else if (d->map->map[y / 64][x / 64] == 'P')
			put_image_player(d, x, y);
		xy_oper(&x, &y, d);
	}
	score(d);
}
