/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:41 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/07 19:55:17 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* My libs */
# include <libft.h>

/* Other libs */
# include <mlx.h>

/* Error messages */
# define ERR "\033[1;31mError \033[0m"
# define ERR2 "Usage: ./so_long [file.ber]"
# define ERR_FILE "File: invalid file type, [.ber] needed"
# define ERR_FILE2 "File: "
# define ERR_FILE3 "File: empty file"
# define MLX "Minilibx"

/* Defines */
# define TITLE "SO_LONG"
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
    char    **map;
}   t_data;

/* main.c */

/* key_hooks.c */
void	ft_control_keys(t_data *d);

/* exit_handling.c */
void    basic_error_message(char *err);
void    error_message_n_exit(char *err);
void	error_exit(t_data *d, char *err);
void	free_strs(char	**strs);
void	free_n_exit_safe(t_data *d);

/* check_input.c */
void	check_input(char *file_line);

/* get_map.c */
char	**get_map(char *map);
int	    get_height(char **map);

#endif
