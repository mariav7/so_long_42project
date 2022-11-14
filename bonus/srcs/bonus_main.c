/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:50 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 15:20:37 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

int	main(int argc, char **argv)
{
	t_data	*mlx;
	t_map	*fmap;

	if (argc != 2)
		basic_error_message(ERR_USAGE, NULL);
	check_file(argv[1]);
	init_structs(&mlx, &fmap);
	get_map(mlx, argv[1]);
	if (mlx->map->map != NULL && mlx->map->tmp_map != NULL)
	{
		is_map_valid(mlx);
		mlx->mlx_ptr = mlx_init();
		if (mlx->mlx_ptr == NULL)
			error_exit(mlx, ERR_MLX, NULL);
		info_usage();
		start_game(mlx);
		mlx_hook(mlx->window, 2, 1L << 0, key_event, mlx);
		mlx_hook(mlx->window, 17, 1L << 2, close_window, mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		error_exit(mlx, ERR_PARS, NULL);
}
