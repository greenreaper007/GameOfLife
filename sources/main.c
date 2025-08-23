/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:38:12 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 02:46:42 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "Please input 2 numbers on the command line\n", 43);
		return (ARGUMENT_ERROR);
	}
	t_game *game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		end_game(game, MALLOC_ERROR, "Malloc failed: t_game");
	}
	initialise_values(game);
	create_board(game, argv);
	create_mlx(game);
	//print_board(game);
	mlx_loop(game->mlx);
	end_game(game, SUCCESS, "Main function finished");
}
