/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameOfLife.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:29:29 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 03:24:38 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOFLIFE_H
# define GAMEOFLIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include "../MyLibft/libft.h"
#include "../minilibx-linux/mlx.h"

/* Graphic Data */
#define WINDOW_NAME "Game Of Life"
#define MAX_WINDOW_LENGTH 1920
#define MAX_WINDOW_HEIGHT 1080
#define MAX_CELL_SIZE 150
#define MINIMUM_BOARD_LENGTH 3
#define MAXIMUM_BOARD_LENGTH 250
#define MINIMUM_BOARD_HEIGHT 3
#define MAXIMUM_BOARD_HEIGHT 250

/* Board Data */
#define DEAD '0'
#define ALIVE '1'

/* Color Data */
#define CELL_DEAD_COLOR_1 0xEEEEEE
#define CELL_DEAD_COLOR_2 0xDEDEDE
#define CELL_ALIVE_COLOR 0xFF0000

/* Keypress Data*/
#define LEFT_CLICK 1
#define RIGHT_CLICK 3
#define SPACE_BAR 32
#define R_KEY 114
#define ESCAPE_KEY 65307

/* Error code Data */
#define SUCCESS 0
#define ARGUMENT_ERROR 1
#define MALLOC_ERROR 2
#define MLX_ERROR 3

typedef struct s_data
{
	int	board_length;
	int	board_height;
	int	cell_size;
	int	window_length;
	int	window_height;
	int	alive_color;
	int	dead_color_1;
	int	dead_color_2;
	int	tick;
	int mouse_x;
	int mouse_y;

}	t_data;

typedef struct s_states
{
	char is_running;
	char is_left_clicking;
	char is_right_clicking;

}	t_states;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*frame_image;
	int			*frame_data;
	char		**board;
	t_data		data;
	t_states	states;
	
}	t_game;

/* end_game.c */
void end_game(t_game *game, int code, char *msg);
int handle_exit(t_game	*game);

/* initialise_valus.c */
void initialise_values(t_game *game);

/* create_board.c */
void create_board(t_game *game, char **argv);
void reset_board(t_game *game);

/* create_mlx.c */
void create_mlx(t_game *game);

/* game_loop */
int game_loop(t_game *game);

/* draw_frame.c */
void draw_frame(t_game *game);

/* handle_keypress.c */
int	handle_keypress(int keycode, t_game *game);
int	handle_keyrelease(int keycode, t_game *game);

/* handle_mousepress.c */
void update_mouse(t_game *game);
int	handle_mousepress(int keycode, int x, int y, t_game *game);
int	handle_mouserelease(int keycode, int x, int y, t_game *game);

/* print_board.c */
void print_board(t_game *game);

#endif