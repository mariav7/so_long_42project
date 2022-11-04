/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:50 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/04 19:05:18 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	info_usage(void)
{
	ft_printf("\n\033[1;92mSO_LONG - INFO\033[0m\n\n");
	ft_printf("To move, use:\t");
	ft_printf("    \033[1;96m'W'\033[0m\n");
	ft_printf("\t\t\033[1;93m'A'\033[0m \033[1;94m'S'\033[0m \033[1;95m'D'\033[0m\n");
	ft_printf("\nTo quit, use:\t\033[1;91m'ESC'\033[0m\n\n");
}

/* static int	handle_no_event(void *data)
{
	(void)data;
	//This function needs to exist, but it is useless for the moment
	return (0);
} */

int	main(int argc, char **argv)
{
	t_data	mlx;

	if (argc <= 1 || argc >= 3)
		basic_error_message(ERR2);
	(void)argc;
	(void)argv;
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		basic_error_message(MLX);
	mlx.window = mlx_new_window(mlx.mlx_ptr, WIN_X, WIN_Y, TITLE);
	if (mlx.window == NULL)
		error_exit(&mlx, MLX);
	ft_display_usage();
	//mlx_pixel_put(mlx.mlx_ptr, mlx.window, 250, 250, 0xFFFFFF);
	//mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	ft_control_keys(&mlx);
	mlx_loop(mlx.mlx_ptr);
	free_n_exit_safe(&mlx);
	return (0);
}
