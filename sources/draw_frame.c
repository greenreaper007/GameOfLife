/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 01:29:14 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 02:33:41 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

void draw_cell(int x, int y, int color, t_game *game)
{
	x = x * game->data.cell_size;
	y = y * game->data.cell_size * game->data.window_length;
	int i = 0;
	int j;
	while (i < game->data.cell_size)
	{
		j = 0;
		while (j < game->data.cell_size)
		{
			game->frame_data[x + j + y] = color;
			j++;
		}
		y += game->data.window_length;
		i++;
	}
}

int get_back_color(int x, int y, t_game *game)
{
	if ((y % 2 == 0 && x % 2 == 0) || (y % 2 == 1 && x % 2 == 1))
		return (game->data.dead_color_1);
	return (game->data.dead_color_2);
}

void draw_frame(t_game *game)
{
	int y = 0;
	int x;
	while (y < game->data.board_height)
	{
		x = 0;
		while (x < game->data.board_length)
		{
			if (game->board[y][x] == ALIVE)
				draw_cell(x, y, game->data.alive_color, game);
			else
				draw_cell(x, y, get_back_color(x, y, game), game);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->frame_image, 0, 0);
}
