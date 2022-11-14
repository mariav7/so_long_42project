/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:50 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 10:09:49 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	info_usage(void)
{
	ft_printf("\n\033[1;92mSO_LONG - INFO\033[0m\n\n");
	ft_printf("To move, use:\t");
	ft_printf("    \033[1;96m'W'\033[0m\n");
	ft_printf("\t\t\033[1;93m'A'\033[0m");
	ft_printf(" \033[1;94m'S'\033[0m");
	ft_printf(" \033[1;95m'D'\033[0m\n");
	ft_printf("\nTo quit, use:\t\033[1;91m'ESC'\033[0m" );
	ft_printf("  or click on \033[1;91m'X'\033[0m\n\n");
}

static void	init_structs(t_data **d, t_map **m)
{
	*d = ft_calloc(sizeof(t_data), 1);
	if (*d == NULL)
		basic_error_message(ERR_CALLOC, NULL);
	*m = ft_calloc(sizeof(t_map), 1);
	if (*m == NULL)
		basic_error_message(ERR_CALLOC, *d);
	(*d)->map = *m;
	(*d)->map->c = 'C';
	(*d)->map->e = 'E';
	(*d)->map->p = 'P';
	(*d)->map->wall = '1';
	(*d)->map->space = '0';
	(*d)->map->current_pos = 'F';
}

static int	close_window(t_data *d)
{
	free_n_exit_safe(d);
	return (0);
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
		in_image(mlx);
		mlx_hook(mlx->window, 2, 1L << 0, key_event, mlx);
		mlx_hook(mlx->window, 17, 1L << 2, close_window, mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		error_exit(mlx, ERR_PARS, NULL);
}
