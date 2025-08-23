/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:29:36 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 03:05:21 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

void initialise_states(t_game *game)
{
	game->states.is_running = 0;
	game->states.is_left_clicking = 0;
	game->states.is_right_clicking = 0;
}

void initialise_values(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->board = NULL;
	game->frame_image = NULL;
	game->data.tick = 0;
	initialise_states(game);
}
