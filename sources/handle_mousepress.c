/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mousepress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:49:03 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 03:01:57 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

void mouse_position(t_game *game)
{
	mlx_mouse_get_pos(game->mlx, game->win, &game->data.mouse_x, &game->data.mouse_y);
}

void update_mouse(t_game *game)
{
	mouse_position(game);
	if (game->states.is_left_clicking)
	{
		game->board[game->data.mouse_y / game->data.cell_size][game->data.mouse_x / game->data.cell_size] = ALIVE;
	}
	if (game->states.is_right_clicking)
	{
		game->board[game->data.mouse_y / game->data.cell_size][game->data.mouse_x / game->data.cell_size] = DEAD;
	}
}

int	handle_mouserelease(int keycode, int x, int y, t_game *game)
{
	if (keycode == LEFT_CLICK)
	{
		game->states.is_left_clicking = 0;
	}
	if (keycode == RIGHT_CLICK)
	{
		game->states.is_right_clicking = 0;
	}
	(void)x;
	(void)y;
	return (0);
}

int	handle_mousepress(int keycode, int x, int y, t_game *game)
{
	if (keycode == LEFT_CLICK && !game->states.is_right_clicking)
	{
		game->states.is_left_clicking = 1;
	}
	if (keycode == RIGHT_CLICK && !game->states.is_left_clicking)
	{
		game->states.is_right_clicking = 1;
	}
	(void)x;
	(void)y;
	return (0);
}
