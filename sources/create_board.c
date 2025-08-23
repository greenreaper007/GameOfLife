/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:37:41 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 03:15:03 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

void reset_board(t_game *game)
{
	int j;
	int i = 0;
	while (i < game->data.board_height)
	{
		j = 0;
		while (j < game->data.board_length)
		{
			game->board[i][j] = DEAD;
			j++;
		}
		game->board[i][j] = 0;
		i++;
	}
}

void get_cell_size(t_game *game)
{
	game->data.cell_size = MAX_WINDOW_LENGTH / game->data.board_length;
	if (MAX_WINDOW_HEIGHT / game->data.board_height < game->data.cell_size)
	{
		game->data.cell_size = MAX_WINDOW_HEIGHT / game->data.board_height;
	}
	if (game->data.cell_size > MAX_CELL_SIZE)
	{
		game->data.cell_size = MAX_CELL_SIZE;
	}
	game->data.window_length = game->data.cell_size * game->data.board_length;
	game->data.window_height = game->data.cell_size * game->data.board_height;
	game->data.alive_color = CELL_ALIVE_COLOR;
	game->data.dead_color_1 = CELL_DEAD_COLOR_1;
	game->data.dead_color_2 = CELL_DEAD_COLOR_2;
}

void get_board_data(t_game *game, char **argv)
{
	game->data.board_length = ft_atoi(argv[1]);
	if (game->data.board_length < MINIMUM_BOARD_LENGTH
		|| game->data.board_length > MAXIMUM_BOARD_LENGTH)
	{
		end_game(game, ARGUMENT_ERROR, "Board length must be a number between 3 and 100");
	}
	game->data.board_height = ft_atoi(argv[2]);
	if (game->data.board_height < MINIMUM_BOARD_HEIGHT
		|| game->data.board_height > MAXIMUM_BOARD_HEIGHT)
	{
		end_game(game, ARGUMENT_ERROR, "Board height must be a number between 3 and 100");
	}
	get_cell_size(game);
}

void create_board(t_game *game, char **argv)
{
	get_board_data(game, argv);
	game->board = (char **)malloc((game->data.board_height + 1) * sizeof(char *));
	if (!game->board)
	{
		end_game(game, MALLOC_ERROR, "Malloc failed: board");
	}
	game->board[0] = NULL;
	int i = 0;
	while (i < game->data.board_height)
	{
		game->board[i] = (char *)malloc((game->data.board_length + 1) * sizeof(char));
		if (!game->board[i])
		{
			end_game(game, MALLOC_ERROR, "Malloc failed: board");
		}
		game->board[i + 1] = NULL;
		i++;
	}
	reset_board(game);
}
