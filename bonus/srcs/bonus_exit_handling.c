/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exit_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:46:12 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/15 10:23:38 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static void	free_player_images(t_data *d)
{
	if (d->player_l)
		mlx_destroy_image(d->mlx_ptr, d->player_l);
	if (d->player_ll)
		mlx_destroy_image(d->mlx_ptr, d->player_ll);
	if (d->player_r)
		mlx_destroy_image(d->mlx_ptr, d->player_r);
	if (d->player_rr)
		mlx_destroy_image(d->mlx_ptr, d->player_rr);
	if (d->player_b)
		mlx_destroy_image(d->mlx_ptr, d->player_b);
	if (d->player_bb)
		mlx_destroy_image(d->mlx_ptr, d->player_bb);
	if (d->player_f)
		mlx_destroy_image(d->mlx_ptr, d->player_f);
	if (d->player_ff)
		mlx_destroy_image(d->mlx_ptr, d->player_ff);
}

void	free_mlx_images(t_data *d)
{
	if (d->backg)
		mlx_destroy_image(d->mlx_ptr, d->backg);
	if (d->score_backg)
		mlx_destroy_image(d->mlx_ptr, d->score_backg);
	if (d->item)
		mlx_destroy_image(d->mlx_ptr, d->item);
	if (d->wall)
		mlx_destroy_image(d->mlx_ptr, d->wall);
	if (d->exit_o)
		mlx_destroy_image(d->mlx_ptr, d->exit_o);
	if (d->exit_c)
		mlx_destroy_image(d->mlx_ptr, d->exit_c);
	free_player_images(d);
}

void	basic_error_message(char *err, void *free_this)
{
	if (free_this)
		free(free_this);
	ft_putendl_fd(ERR, 2);
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	error_exit(t_data *d, char *err, void *free_this)
{
	if (d->map->map)
		free_strs(d->map->map);
	if (d->map->tmp_map)
		free_strs(d->map->tmp_map);
	if (d->mlx_ptr)
	{
		if (d->window)
		{
			free_mlx_images(d);
			mlx_destroy_window(d->mlx_ptr, d->window);
		}
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
	}
	free(d->map);
	free(d);
	basic_error_message(err, free_this);
}

void	free_n_exit_safe(t_data *d)
{
	if (d->map->map)
		free_strs(d->map->map);
	if (d->map->tmp_map)
		free_strs(d->map->tmp_map);
	if (d->mlx_ptr)
	{
		if (d->window)
		{
			free_mlx_images(d);
			mlx_destroy_window(d->mlx_ptr, d->window);
		}
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
	}
	free(d->map);
	free(d);
	exit(EXIT_SUCCESS);
}
