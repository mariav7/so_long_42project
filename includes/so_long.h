/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:41 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/03 18:35:25 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* My libs */
# include <libft.h>

/* Other libs */
# include <mlx.h>

# define WIN1_SX  800
# define WIN1_SY 550

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define ROTATE_LEFT 65361
# define ROTATE_RIGTH 65363
# define ROTATE_UP 65362
# define ROTATE_DOWN 65364
# define ESCAPE 65307

/* STRUCTURES */
typedef struct s_data
{
    void	*mlx_ptr;
	void	*win1;
}   t_data;

/* main.c */

#endif
