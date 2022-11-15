/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:41 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/15 10:36:57 by mflores-         ###   ########.fr       */
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
# define ERR_CALLOC "Calloc: structures"
# define ERR_USAGE "Usage: ./so_long [file.ber]"
# define ERR_FILE "File: invalid file type, [.ber] needed"
# define ERR_FILE2 "File"
# define ERR_FILE3 "File: empty file"
# define ERR_PARS "Parsing: failed"
# define ERR_MAP "Map: invalid"
# define ERR_MAP2 "Map: must contain 1 exit, 1 player and at least 1 item"
# define ERR_MAP3 "Map: not rectangular"
# define ERR_MAP4 "Map: not surrounded by walls"
# define ERR_MAP5 "Map: invalid path"
# define ERR_MLX "Minilibx: initialization failed"
# define ERR_MLX_FILE2IMG "Minilibx: file to image failed"
# define ERR_MLX_WIN "Minilibx: new window failed"

/* Other messages */
# define WIN "Winner, winner chicken dinner!"

/* Other macros */
# define FILE_TYPE ".ber"
# define TITLE "SO_LONG"

/* Textures */
# define BACKG "./textures/backg.xpm"
# define PL_F "./textures/player_f.xpm"
# define PL_B "./textures/player_b.xpm"
# define PL_L "./textures/player_l.xpm"
# define PL_R "./textures/player_r.xpm"
# define EXIT "./textures/door-closed.xpm"
# define WALL "./textures/wall.xpm"
# define ITEM "./textures/item.xpm"

/* Key codes */
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
	char	current_pos;
	int		ex_y;
	int		ex_x;
	int		items;
	int		tmp_items;
	int		exit;
	int		tmp_exit;
	int		player;
	int		play_y;
	int		play_x;
	int		height;
	int		width;
	int		move_count;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window;
	void	*backg;
	void	*player_f;
	void	*player_b;
	void	*player_r;
	void	*player_l;
	void	*item;
	void	*exit;
	void	*wall;
	int		img_y;
	int		img_x;
	t_map	*map;
}	t_data;

/* check_file.c */
void	check_file(char *file_line);

/* get_map.c */
void	get_map(t_data *m, char *fmap);

/* check_map.c */
void	is_map_valid(t_data *m);

/* check_map2.c */
int		is_walled(t_data *m);
int		valid_path(t_data *m);

/* render_map.c */
void	init_game(t_data *d);
int		check_move(t_data *d, int x, int y);
void	render_after_move(t_data *d);

/* screen.c */
void	reg_images(t_data *d);
void	put_images(t_data *d);

/* key_hooks.c */
int		key_event(int key_code, t_data *d);

/* exit_handling.c */
void	free_mlx_images(t_data *d);
void	basic_error_message(char *err, void *free_this);
void	error_message_n_exit(char *err, t_data *d);
void	error_exit(t_data *d, char *err, void *free_this);
void	free_n_exit_safe(t_data *d);

/* utils.c */
void	init_structs(t_data **d, t_map **m);
int		close_window(t_data *d);
void	free_strs(char	**strs);
void	count_exit(t_data *m, int y, int x);

#endif
