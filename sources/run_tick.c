/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:45:42 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 04:34:09 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

int check_cell(int x, int y, t_game *game)
{
	if (x < 0)
	{
		x = game->data.board_length - 1;
	}
	if (y < 0)
	{
		y = game->data.board_height - 1;
	}
	if (x >= game->data.board_length)
	{
		x = 0;
	}
	if (y >= game->data.board_height)
	{
		y = 0;
	}
	if (game->board_copy[y][x] == ALIVE)
		return (1);
	return (0);
}

char calculate_cell(int x, int y, t_game *game)
{
	int count = 0;
	int i = -1;
	int j;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			count += check_cell(x + j, y + i, game);
			j++;
		}
		i++;
	}
	if (game->board_copy[y][x] == ALIVE)
	{
		count--;
		if (count == 2 || count == 3)
			return (ALIVE);
		return (DEAD);
	}
	if (count == 3)
		return (ALIVE);
	return (DEAD);
}

void calculate_tick(t_game *game)
{
	int x;
	int y = 0;
	while (y < game->data.board_height)
	{
		x = 0;
		while (x < game->data.board_length)
		{
			game->board[y][x] = calculate_cell(x, y, game);
			x++;
		}
		y++;
	}
}

void run_tick(t_game *game)
{
	printf("tick : %d\n", game->data.tick);
	game->data.tick++;
	swap_boards(game);
	reset_board(game);
	calculate_tick(game);
}
