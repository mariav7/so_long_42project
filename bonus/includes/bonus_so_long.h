/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:41 by mflores-          #+#    #+#             */
/*   Updated: 2023/11/09 15:59:14 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_SO_LONG_H
# define BONUS_SO_LONG_H

/* My libs */
# include <libft.h>

/* Other libs */
# include "../../mlx/mlx.h"
//# include <mlx.h>

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
# define ERR_MAP6 "Map: is too big for the current screen"
# define ERR_MLX "Minilibx: initialization failed"
# define ERR_MLX_FILE2IMG "Minilibx: file to image failed"
# define ERR_MLX_WIN "Minilibx: new window failed"

/* Other messages */
# define WIN "Winner, winner chicken dinner!"

/* Other macros */
# define FILE_TYPE ".ber"
# define TITLE "SO_LONG"

/* Textures */
# define SIZE 64
# define BACKG "./sprites/backg.xpm"
# define SCORE_BACKG "./sprites/score-backg.xpm"
# define PL_F "./sprites/player_f.xpm"
# define PL_FF "./sprites/player_ff.xpm"
# define PL_B "./sprites/player_b.xpm"
# define PL_BB "./sprites/player_bb.xpm"
# define PL_L "./sprites/player_l.xpm"
# define PL_LL "./sprites/player_ll.xpm"
# define PL_R "./sprites/player_r.xpm"
# define PL_RR "./sprites/player_rr.xpm"
# define EXIT_O "./sprites/door-open.xpm"
# define EXIT_C "./sprites/door-closed.xpm"
# define WALL "./sprites/wall.xpm"
# define ITEM "./sprites/item.xpm"

/* Key codes */
# define LEFT 97
# define LEFT2 65361
# define RIGHT 100
# define RIGHT2 65363
# define UP 119
# define UP2 65362
# define DOWN 115
# define DOWN2 65364
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
	char	*move_count_screen;
	int		move_count;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window;
	void	*backg;
	void	*score_backg;
	void	*player_f;
	void	*player_ff;
	void	*player_b;
	void	*player_bb;
	void	*player_r;
	void	*player_rr;
	void	*player_l;
	void	*player_ll;
	void	*item;
	void	*exit_c;
	void	*exit_o;
	void	*wall;
	int		anim;
	int		img_y;
	int		img_x;
	t_map	*map;
}	t_data;

/* bonus_main.c */
void	info_usage(void);
int		close_window(t_data *d);

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
int		check_move(t_data *d, int y, int x);
void	display_map(t_map *map);
void	render_after_move(t_data *d);

/* screen.c */
void	reg_images(t_data *d);
void	put_images(t_data *d);

/* key_hooks.c */
int		key_event(int key_code, t_data *d);

/* exit_handling.c */
void	free_mlx_images(t_data *d);
void	basic_error_message(char *err, void *free_this);
void	error_exit(t_data *d, char *err, void *free_this);
void	free_n_exit_safe(t_data *d);

/* utils.c */
void	init_structs(t_data **d, t_map **m);
void	free_strs(char	**strs);
void	count_exit(t_data *m, int y, int x);
void	reg_player_images(t_data *d);
void	error_message_n_exit(char *err, t_data *d);

#endif
