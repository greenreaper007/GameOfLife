/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameOfLife.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:29:29 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/22 19:24:34 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOFLIFE_HPP
# define GAMEOFLIFE_HPP

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
#define MAX_WINDOW_LENGTH 1920
#define MAX_WINDOW_HEIGHT 1080
#define MAX_CELL_SIZE 50
#define MINIMUM_BOARD_LENGTH 3
#define MAXIMUM_BOARD_LENGTH 100
#define MINIMUM_BOARD_HEIGHT 3
#define MAXIMUM_BOARD_HEIGHT 100

/* Board Data */
#define DEAD '0'
#define ALIVE '1'

/* Color Data */
#define CELL_DEAD_COLOR 0xDEDEDE
#define CELL_ALIVE_COLOR 0xFF0000

/* Keypress Data*/

/* Error code Data */
#define SUCCESS 0
#define ARGUMENT_ERROR 1
#define MALLOC_ERROR 2

typedef struct s_data
{
	int	board_length;
	int	board_height;
	int	cell_size;
	int	window_length;
	int	window_height;
	int	alive_color;
	int	dead_color;

}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**board;
	t_data	data;
	
}	t_game;

/* end_game.c */
void end_game(t_game *game, int code, char *msg);

/* initialise_valus.c */
void initialise_values(t_game *game);

/* create_board.c */
void create_board(t_game *game, char **argv);

/* print_board.c */
void print_board(t_game *game);

#endif