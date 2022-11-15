/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:05:38 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/15 10:38:52 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	init_structs(t_data **d, t_map **m)
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
	(*d)->anim = 0;
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

void	count_exit(t_data *m, int y, int x)
{
	m->map->exit++;
	m->map->ex_y = y;
	m->map->ex_x = x;
}

void	reg_player_images(t_data *d)
{
	d->player_f = mlx_xpm_file_to_image(d->mlx_ptr, PL_F,
			&d->img_x, &d->img_y);
	d->player_ff = mlx_xpm_file_to_image(d->mlx_ptr, PL_FF,
			&d->img_x, &d->img_y);
	d->player_b = mlx_xpm_file_to_image(d->mlx_ptr, PL_B,
			&d->img_x, &d->img_y);
	d->player_bb = mlx_xpm_file_to_image(d->mlx_ptr, PL_BB,
			&d->img_x, &d->img_y);
	d->player_l = mlx_xpm_file_to_image(d->mlx_ptr, PL_L,
			&d->img_x, &d->img_y);
	d->player_ll = mlx_xpm_file_to_image(d->mlx_ptr, PL_LL,
			&d->img_x, &d->img_y);
	d->player_r = mlx_xpm_file_to_image(d->mlx_ptr, PL_R,
			&d->img_x, &d->img_y);
	d->player_rr = mlx_xpm_file_to_image(d->mlx_ptr, PL_RR,
			&d->img_x, &d->img_y);
	if (!d->player_f || !d->player_ff || !d->player_b || !d->player_bb
		|| !d->player_l || !d->player_ll || !d->player_r || !d->player_rr)
	{
		free_mlx_images(d);
		error_exit(d, ERR_MLX_FILE2IMG, NULL);
	}
}

void	error_message_n_exit(char *err, t_data *d)
{
	if (d)
	{
		free(d->map);
		free(d);
	}
	ft_putendl_fd(ERR, 2);
	perror(err);
	exit(EXIT_FAILURE);
}
