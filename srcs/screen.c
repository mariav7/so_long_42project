/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:47:55 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/15 11:01:00 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	xy_counter(int *x, int *y, t_data *d)
{
	if (*x == d->map->width * SIZE)
	{
		*x = -SIZE;
		*y += SIZE;
	}
	*x += SIZE;
}

static void	put_images_player(t_data *d, int x, int y)
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

void	put_images(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < d->map->height * SIZE)
	{
		if (d->map->map[y / SIZE][x / SIZE] != '1'
			&& d->map->map[y / SIZE][x / SIZE] != '0')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->backg, x, y);
		if (d->map->map[y / SIZE][x / SIZE] == '1')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->wall, x, y);
		else if (d->map->map[y / SIZE][x / SIZE] == '0')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->backg, x, y);
		else if (d->map->map[y / SIZE][x / SIZE] == 'E')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->exit, x, y);
		else if (d->map->map[y / SIZE][x / SIZE] == 'C')
			mlx_put_image_to_window(d->mlx_ptr, d->window, d->item, x, y);
		else if (d->map->map[y / SIZE][x / SIZE] == 'P')
			put_images_player(d, x, y);
		xy_counter(&x, &y, d);
	}
}

void	reg_images(t_data *d)
{
	d->player_f = mlx_xpm_file_to_image(d->mlx_ptr, PL_F,
			&d->img_x, &d->img_y);
	d->player_b = mlx_xpm_file_to_image(d->mlx_ptr, PL_B,
			&d->img_x, &d->img_y);
	d->player_l = mlx_xpm_file_to_image(d->mlx_ptr, PL_L,
			&d->img_x, &d->img_y);
	d->player_r = mlx_xpm_file_to_image(d->mlx_ptr, PL_R,
			&d->img_x, &d->img_y);
	d->backg = mlx_xpm_file_to_image(d->mlx_ptr, BACKG,
			&d->img_x, &d->img_y);
	d->item = mlx_xpm_file_to_image(d->mlx_ptr, ITEM,
			&d->img_x, &d->img_y);
	d->exit = mlx_xpm_file_to_image(d->mlx_ptr, EXIT,
			&d->img_x, &d->img_y);
	d->wall = mlx_xpm_file_to_image(d->mlx_ptr, WALL,
			&d->img_x, &d->img_y);
	if (!d->player_f || !d->player_b || !d->player_l || !d->player_r
		|| !d->backg || !d->item || !d->exit || !d->wall)
	{
		free_mlx_images(d);
		error_exit(d, ERR_MLX_FILE2IMG, NULL);
	}
}
