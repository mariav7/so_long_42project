/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:47:55 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/15 10:39:10 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static void	xy_counter(int *x, int *y, t_data *d)
{
	if (*x == d->map->width * 64)
	{
		*x = -64;
		*y += 64;
	}
	*x += 64;
}

static void	put_images_player(t_data *d, int x, int y)
{
	if (d->anim)
	{
		if (d->map->current_pos == 'F')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_f, x, y);
		else if (d->map->current_pos == 'R')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_r, x, y);
		else if (d->map->current_pos == 'L')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_l, x, y);
		else if (d->map->current_pos == 'B')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_b, x, y);
		d->anim--;
	}
	else
	{
		if (d->map->current_pos == 'F')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_ff, x, y);
		else if (d->map->current_pos == 'R')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_rr, x, y);
		else if (d->map->current_pos == 'L')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_ll, x, y);
		else if (d->map->current_pos == 'B')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->player_bb, x, y);
		d->anim++;
	}
}

static void	score(t_data *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->window, d->score_backg, 0,
		(d->map->height * 64) - 35);
	d->map->move_count_screen = ft_itoa(d->map->move_count);
	mlx_string_put(d->mlx_ptr, d->window, 10, (d->map->height * 64) - 15,
		0xFFFFFF, "Move: ");
	mlx_string_put(d->mlx_ptr, d->window, 45, (d->map->height * 64) - 15,
		0xFFFFFF, d->map->move_count_screen);
	free(d->map->move_count_screen);
}

void	put_images(t_data *d)
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
		else if (d->map->items != 0 && d->map->map[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->exit_c, x, y);
		else if (d->map->items == 0 && d->map->map[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->exit_o, x, y);
		else if (d->map->map[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->item, x, y);
		else if (d->map->map[y / 64][x / 64] == 'P')
			put_images_player(d, x, y);
		xy_counter(&x, &y, d);
	}
	score(d);
}

void	reg_images(t_data *d)
{
	reg_player_images(d);
	d->backg = mlx_xpm_file_to_image(d->mlx_ptr, BACKG,
			&d->img_x, &d->img_y);
	d->score_backg = mlx_xpm_file_to_image(d->mlx_ptr, SCORE_BACKG,
			&d->img_x, &d->img_y);
	d->item = mlx_xpm_file_to_image(d->mlx_ptr, ITEM,
			&d->img_x, &d->img_y);
	d->exit_c = mlx_xpm_file_to_image(d->mlx_ptr, EXIT_C,
			&d->img_x, &d->img_y);
	d->exit_o = mlx_xpm_file_to_image(d->mlx_ptr, EXIT_O,
			&d->img_x, &d->img_y);
	d->wall = mlx_xpm_file_to_image(d->mlx_ptr, WALL,
			&d->img_x, &d->img_y);
	if (!d->backg || !d->score_backg || !d->item || !d->exit_o
		|| !d->exit_c || !d->wall)
	{
		free_mlx_images(d);
		error_exit(d, ERR_MLX_FILE2IMG, NULL);
	}
}
