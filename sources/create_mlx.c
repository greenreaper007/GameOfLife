/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:37:33 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 01:20:30 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

void create_mlx_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, handle_keyrelease, game);
	mlx_hook(game->win, 4, 1L << 2, handle_mousepress, game);
	mlx_hook(game->win, 5, 1L << 3, handle_mouserelease, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_loop_hook(game->mlx, game_loop, game);
}

void create_mlx(t_game *game)
{
	int i = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		end_game(game, MLX_ERROR, "MLX intialisation failed");
	game->win = mlx_new_window(game->mlx, game->data.window_length, game->data.window_height, "cube");
	if (!game->win)
		end_game(game, MLX_ERROR, "Window intialisation failed");
	game->frame_image = mlx_new_image(game->mlx, game->data.window_length, game->data.window_height);
	if (!game->frame_image)
		end_game(game, MLX_ERROR, "Frame image cration failed");
	game->frame_data = (int *)mlx_get_data_addr(game->frame_image, &i, &i, &i);
	create_mlx_hooks(game);
}
