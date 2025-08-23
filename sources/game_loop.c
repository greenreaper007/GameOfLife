/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:35:24 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 03:53:42 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * SECOND + time.tv_usec);
}

int game_loop(t_game *game)
{
	update_mouse(game);
	draw_frame(game);
	if (game->states.is_running && get_time() > game->data.tick_time + TICK_DELAY)
	{
		game->data.tick_time = get_time();
		run_tick(game);
	}
	return (SUCCESS);
}
