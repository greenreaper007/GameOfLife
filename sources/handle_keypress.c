/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:54:17 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 01:14:49 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == ESCAPE_KEY)
	{
		end_game(game, SUCCESS, "Escape key closed");
	}
	if (keycode == SPACE_BAR)
	{
		game->states.is_running = !game->states.is_running;
	}
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}