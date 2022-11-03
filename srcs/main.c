/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:50 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/03 18:42:55 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ftputchar(char c)
{
	write(1, &c, 1);
}

//mlx_pixel_put(mlx_ptr, win1, 250, 250, 0xFFFFFF);
int	deal_key(int key, void *param)
{
	putchar('X');
	return (0);
}

static void	ft_display_usage(void)
{
	ft_printf("SO_LONG - Usage\n");
	ft_printf("For quit, you can use 'Q' or 'ESC key'\n");
}

int	main(void)
{
	t_data	mlx;

	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		exit(1);
	mlx.win1 = mlx_new_window(mlx.mlx_ptr, WIN1_SX, WIN1_SY, "SO_LONG");
	if (mlx.win1 == NULL)
	{
		free(mlx.mlx_ptr);
		exit(1);
	}
	ft_display_usage();
	mlx_pixel_put(mlx.mlx_ptr, mlx.win1, 250, 250, 0xFFFFFF);
	mlx_key_hook(mlx.win1, deal_key, (void *)0);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win1);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
