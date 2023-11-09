/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:50 by mflores-          #+#    #+#             */
/*   Updated: 2023/11/09 16:09:27 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_usage(void)
{
	ft_printf("\n\033[1;93mSO_LONG - HOW TO PLAY\033[0m\n\n");
	ft_printf("To move, use:\t");
	ft_printf("  \033[1;96mW\t\033[0m\n");
	ft_printf("\t\t\033[1;93mA\033[0m");
	ft_printf(" \033[1;94mS\033[0m");
	ft_printf(" \033[1;95mD\033[0m");
	ft_printf("\n\nTo quit, use:\t\033[1;91mESC\033[0m" );
	ft_printf("  or click on \033[1;91mX\033[0m\n\n");
}

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
		init_game(mlx);
		mlx_hook(mlx->window, 2, 1L << 0, key_event, mlx);
		mlx_hook(mlx->window, 17, 1L << 17, close_window, mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		error_exit(mlx, ERR_PARS, NULL);
}
