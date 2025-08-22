/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:50:21 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/22 19:22:42 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

void print_board(t_game *game)
{
	int i = 0;
	while (game->board[i])
	{
		write(1, game->board[i], game->data.board_length);
		write(1, "\n", 1);
		i++;
	}
}
