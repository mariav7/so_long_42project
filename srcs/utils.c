/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:05:38 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 15:02:30 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_usage(void)
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
