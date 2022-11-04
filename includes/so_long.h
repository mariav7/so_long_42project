/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:41 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/04 17:14:02 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* My libs */
# include <libft.h>

/* Other libs */
# include <mlx.h>

/* Defines */
# define ERR "\033[1;31mError \033[0m"
# define ERR2 "Usage: ./so_long [map.ber]"
# define MLX "Minilibx"

# define WIN_X  800
# define WIN_Y 550

# define LEFT 97
# define RIGTH 100
# define UP 119
# define DOWN 115
# define ESCAPE 65307

/* STRUCTURES */
typedef struct s_data
{
    void	*mlx_ptr;
	void	*window;
}   t_data;

/* main.c */

/* key_hooks.c */
void	ft_control_keys(t_data *d);

/* exit_handling.c */
void    basic_error_message(char *err);
void    error_message_n_exit(char *err);
void	error_exit(t_data *d, char *err);
void	free_n_exit_safe(t_data *d);

#endif
