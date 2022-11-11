/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:46:12 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/11 11:57:49 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	basic_error_message(char *err, void *truc)
{
	if (truc)
		free(truc);
	ft_putendl_fd(ERR, 2);
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	error_message_n_exit(char *err)
{
	ft_putendl_fd(ERR, 2);
	perror(err);
	exit(EXIT_FAILURE);
}

//error_message_n_exit(err);
void	error_exit(t_data *d, char *err)
{
	if (d->map->map)
		free_strs(d->map->map);
	if (d->map->tmp_map)
		free_strs(d->map->tmp_map);
	if (d->mlx_ptr)
	{
		if (d->window)
			mlx_destroy_window(d->mlx_ptr, d->window);
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
	}
	basic_error_message(err, NULL);
}

void	free_strs(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	strs = NULL;
}

void	ft_free_mlx(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->backg);
	mlx_destroy_image(d->mlx_ptr, d->food);
	mlx_destroy_image(d->mlx_ptr, d->wall);
	mlx_destroy_image(d->mlx_ptr, d->exit);
	mlx_destroy_image(d->mlx_ptr, d->player_l);
	mlx_destroy_image(d->mlx_ptr, d->player_r);
	mlx_destroy_image(d->mlx_ptr, d->player_b);
	mlx_destroy_image(d->mlx_ptr, d->player_f);
	mlx_destroy_window(d->mlx_ptr, d->window);
	free(d->mlx_ptr);
}

//	mlx_destroy_image(d->mlx, d->img.img);
void	free_n_exit_safe(t_data *d)
{
	if (d->map->map)
		free_strs(d->map->map);
	if (d->map->tmp_map)
		free_strs(d->map->tmp_map);
	if (d->mlx_ptr)
	{
		if (d->window)
			mlx_destroy_window(d->mlx_ptr, d->window);
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}
