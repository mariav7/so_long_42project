/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:06:01 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/03 18:41:09 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int key_code, t_data *d)
{
	if (key_code == ROTATE_LEFT)
		d->left -= 5;
	else if (key_code == ROTATE_RIGTH)
		d->right += 5;
	else if (key_code == ROTATE_UP)
		d->up -= 2;
	else if (key_code == ROTATE_DOWN)
		d->down += 2;
	else if (key_code == ESCAPE)
		ft_safe_exit_free(fdf);
	ft_render(fdf);
	return (0);
}

void	ft_control_keys(t_fdf *fdf)
{
	mlx_key_hook(fdf->window, &key_hook, fdf);
}
