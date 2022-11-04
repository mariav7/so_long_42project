/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:46:12 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/04 17:11:35 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    basic_error_message(char *err)
{
	ft_putendl_fd(ERR, 2);
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}

void    error_message_n_exit(char *err)
{
	ft_putendl_fd(ERR, 2);
	perror(err);
	exit(EXIT_FAILURE);
}

void	error_exit(t_data *d, char *err)
{
	if (d->window)
		mlx_destroy_window(d->mlx_ptr, d->window);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	error_message_n_exit(err);
}

void	free_n_exit_safe(t_data *d)
{
//	free(d->);
//	free(d->);
//	mlx_destroy_image(d->mlx, d->img.img);
	mlx_destroy_window(d->mlx_ptr, d->window);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	exit(EXIT_SUCCESS);
}
