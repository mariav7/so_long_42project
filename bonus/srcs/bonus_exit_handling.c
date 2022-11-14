/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exit_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:46:12 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 15:20:30 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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
	if (d->exit)
		mlx_destroy_image(d->mlx_ptr, d->exit);
	if (d->player_l)
		mlx_destroy_image(d->mlx_ptr, d->player_l);
	if (d->player_r)
		mlx_destroy_image(d->mlx_ptr, d->player_r);
	if (d->player_b)
		mlx_destroy_image(d->mlx_ptr, d->player_b);
	if (d->player_f)
		mlx_destroy_image(d->mlx_ptr, d->player_f);
}

void	basic_error_message(char *err, void *free_this)
{
	if (free_this)
		free(free_this);
	ft_putendl_fd(ERR, 2);
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	error_message_n_exit(char *err, t_data *d)
{
	if (d)
	{
		free(d->map);
		free(d);
	}
	ft_putendl_fd(ERR, 2);
	perror(err);
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
