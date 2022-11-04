/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:06:01 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/04 15:47:04 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int key_code, t_data *d)
{
	if (key_code == LEFT)
		ft_printf("coucou\n");
	else if (key_code == RIGTH)
		ft_printf("coucou\n");
	else if (key_code == UP)
		ft_printf("coucou\n");
	else if (key_code == DOWN)
		ft_printf("coucou\n");
	else if (key_code == ESCAPE)
		free_n_exit_safe(d);
	return (0);
}

void	ft_control_keys(t_data *d)
{
	mlx_key_hook(d->window, &key_hook, d);
}
