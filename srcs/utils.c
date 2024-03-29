/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:05:38 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 15:46:51 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

int	close_window(t_data *d)
{
	free_n_exit_safe(d);
	return (0);
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
