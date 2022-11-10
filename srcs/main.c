/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:50 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/10 22:00:32 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	ft_error(char *msg, t_data *data)
{
	ft_printf("%s", msg);
	ft_free_all(data);
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_data *data)
{
	ft_free_mlx(data);
	ft_free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->map1)
		free(data->map1);
	if (data->map2)
	{
		while (data->map2[i])
		{
			free(data->map2[i]);
			i++;
		}
		free(data->map2);
	}
}

void	ft_free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->bgrnd);
	mlx_destroy_image(data->mlx, data->food);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player_l);
	mlx_destroy_image(data->mlx, data->player_r);
	mlx_destroy_image(data->mlx, data->player_b);
	mlx_destroy_image(data->mlx, data->player_f);
	mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
}*/

static void	info_usage(void)
{
	ft_printf("\n\033[1;92mSO_LONG - INFO\033[0m\n\n");
	ft_printf("To move, use:\t");
	ft_printf("    \033[1;96m'W'\033[0m\n");
	ft_printf("\t\t\033[1;93m'A'\033[0m");
	ft_printf(" \033[1;94m'S'\033[0m");
	ft_printf(" \033[1;95m'D'\033[0m\n");
	ft_printf("\nTo quit, use:\t\033[1;91m'ESC'\033[0m\n\n");
}

static int	handle_no_event(void *data)
{
	(void)data;
	//This function needs to exist, but it is useless for the moment
	return (0);
}

static void	init_vars(t_data *d, t_map *m)
{
	d->mlx_ptr = NULL;
	d->window = NULL;
	d->map = m;
	d->map->map = NULL;
	d->map->tmp_map = NULL;
	d->map->c = 'C';
	d->map->e = 'E';
	d->map->p = 'P';
	d->map->wall = '1';
	d->map->space = '0';
	d->map->items = 0;
	d->map->tmp_items = 0;
	d->map->exit = 0;
	d->map->tmp_exit = 0;
	d->map->player = 0;
	d->map->play_y = 0;
	d->map->play_x = 0;
	d->map->height = 0;
	d->map->width = 0;
}

int	main(int argc, char **argv)
{
	t_data	mlx;
	t_map	fmap;

	if (argc <= 1 || argc >= 3)
		basic_error_message(ERR_USAGE, NULL);
	check_file(argv[1]);
	init_vars(&mlx, &fmap);
	get_map(&mlx, argv[1]);
	if (mlx.map->map != NULL && mlx.map->tmp_map != NULL)
	{
		is_map_valid(&mlx);
		mlx.mlx_ptr = mlx_init();
/* 		ft_in_image(data);
		mlx_hook(mlx.window, 2, 1L << 0, ft_key_event, mlx);
		mlx_hook(mlx.window, 17, 1L << 2, ft_close_window, mlx);
		mlx_loop(mlx.mlx_ptr); */
		if (mlx.mlx_ptr == NULL)
			error_exit(&mlx, ERR_MLX);
		mlx.window = mlx_new_window(mlx.mlx_ptr, WIN_X, WIN_Y, TITLE);
		if (mlx.window == NULL)
			error_exit(&mlx, ERR_MLX);
		info_usage();
		mlx_pixel_put(mlx.mlx_ptr, mlx.window, 250, 250, 0xFFFFFF);
		mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
		ft_control_keys(&mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		error_exit(&mlx, ERR_PARS);
}
