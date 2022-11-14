/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_key_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:06:01 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 15:20:35 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static void	go_up(t_data *d)
{
	if ((check_move(d, d->map->play_x, d->map->play_y - 1)) == 1)
	{
		d->map->map[d->map->play_y][d->map->play_x] = '0';
		d->map->play_y -= 1;
		d->map->map[d->map->play_y][d->map->play_x] = 'P';
		d->map->map[d->map->ex_y][d->map->ex_x] = 'E';
		d->map->current_pos = 'B';
		render_after_move(d);
	}
	else if ((check_move(d, d->map->play_x, d->map->play_y - 1)) == 2)
	{
		d->map->map[d->map->play_y][d->map->play_x] = '0';
		d->map->play_y -= 1;
		d->map->map[d->map->play_y][d->map->play_x] = 'P';
		d->map->current_pos = 'F';
		render_after_move(d);
	}
}

static void	go_down(t_data *d)
{
	if ((check_move(d, d->map->play_x, d->map->play_y + 1)) == 1)
	{
		d->map->map[d->map->play_y][d->map->play_x] = '0';
		d->map->play_y += 1;
		d->map->map[d->map->play_y][d->map->play_x] = 'P';
		d->map->map[d->map->ex_y][d->map->ex_x] = 'E';
		d->map->current_pos = 'F';
		render_after_move(d);
	}
	else if ((check_move(d, d->map->play_x, d->map->play_y + 1)) == 2)
	{
		d->map->map[d->map->play_y][d->map->play_x] = '0';
		d->map->play_y += 1;
		d->map->map[d->map->play_y][d->map->play_x] = 'P';
		d->map->current_pos = 'F';
		render_after_move(d);
	}
}

static void	go_left(t_data *d)
{
	if ((check_move(d, d->map->play_x - 1, d->map->play_y)) == 1)
	{
		d->map->map[d->map->play_y][d->map->play_x] = '0';
		d->map->play_x -= 1;
		d->map->map[d->map->play_y][d->map->play_x] = 'P';
		d->map->map[d->map->ex_y][d->map->ex_x] = 'E';
		d->map->current_pos = 'L';
		render_after_move(d);
	}
	else if ((check_move(d, d->map->play_x - 1, d->map->play_y)) == 2)
	{
		d->map->map[d->map->play_y][d->map->play_x] = '0';
		d->map->play_x -= 1;
		d->map->map[d->map->play_y][d->map->play_x] = 'P';
		d->map->current_pos = 'L';
		render_after_move(d);
	}
}

static void	go_right(t_data *d)
{
	if ((check_move(d, d->map->play_x + 1, d->map->play_y)) == 1)
	{
		d->map->map[d->map->play_y][d->map->play_x] = '0';
		d->map->play_x += 1;
		d->map->map[d->map->play_y][d->map->play_x] = 'P';
		d->map->map[d->map->ex_y][d->map->ex_x] = 'E';
		d->map->current_pos = 'R';
		render_after_move(d);
	}
	else if ((check_move(d, d->map->play_x + 1, d->map->play_y)) == 2)
	{
		d->map->map[d->map->play_y][d->map->play_x] = '0';
		d->map->play_x += 1;
		d->map->map[d->map->play_y][d->map->play_x] = 'P';
		d->map->current_pos = 'R';
		render_after_move(d);
	}
}

int	key_event(int key_code, t_data *d)
{
	if (key_code == LEFT)
		go_left(d);
	else if (key_code == RIGTH)
		go_right(d);
	else if (key_code == UP)
		go_up(d);
	else if (key_code == DOWN)
		go_down(d);
	else if (key_code == ESCAPE)
		free_n_exit_safe(d);
	return (0);
}
