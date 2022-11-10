/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:41 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/10 11:45:13 by mflores-         ###   ########.fr       */
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
# define ERR_USAGE "Usage: ./so_long [file.ber]"
# define ERR_FILE "File: invalid file type, [.ber] needed"
# define ERR_FILE2 "File"
# define ERR_FILE3 "File: empty file"
# define ERR_MAP "Map: not valid"
# define ERR_MAP2 "Map: must contain 1 exit, 1 player and at least 1 item"
# define ERR_MAP3 "Map: not rectangular"
# define ERR_MAP4 "Map: not surrounded by walls"
# define ERR_MAP5 "Map: path not valid"
# define MLX "Minilibx"

/* Other macros */
# define FILE_TYPE ".ber"
# define TITLE "SO_LONG"
# define WIN_X  800
# define WIN_Y 550

# define LEFT 97
# define RIGTH 100
# define UP 119
# define DOWN 115
# define ESCAPE 65307

/* STRUCTURES */
typedef struct s_map
{
	char	**map;
	char	**tmp_map;
	char	e;
	char	c;
	char	p;
	char	wall;
	char	space;
	int		items;
	int		tmp_items;
	int		exit;
	int		tmp_exit;
	int		player;
	int		play_y;
	int		play_x;
	int		height;
	int		width;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window;
	t_map	*map;
}	t_data;

/* main.c */

/* key_hooks.c */
void	ft_control_keys(t_data *d);

/* exit_handling.c */
void	basic_error_message(char *err, void *truc);
void	error_message_n_exit(char *err);
void	error_exit(t_data *d, char *err);
void	free_strs(char	**strs);
void	free_n_exit_safe(t_data *d);

/* check_file.c */
void	check_file(char *file_line);

/* get_map.c */
void	get_map(t_data *m, char *fmap);
//char	**get_map(char *map);

/* check_map.c */
void	is_map_valid(t_data *m);

/* check_map2.c */
int		is_walled(t_data *m);
int		valid_path(t_data *m);

#endif
