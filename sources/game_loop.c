/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:35:24 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 02:54:54 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

int game_loop(t_game *game)
{
	update_mouse(game);
	draw_frame(game);
	if (game->states.is_running)
	{
		printf("tick : %d\n", game->data.tick);
		game->data.tick++;
	}
	return (SUCCESS);
}
