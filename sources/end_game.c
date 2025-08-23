/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:53:13 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/23 01:23:58 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameOfLife.h"

int	handle_exit(t_game	*game)
{
	end_game(game, SUCCESS, "Window closed");
	return (0);
}

void free_tab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void freeall(t_game *game)
{
	if (!game)
		return ;
	if (game->board)
	{
		free_tab(game->board);
	}
	if (game->frame_image)
	{
		mlx_destroy_image(game->mlx, game->frame_image);
	}
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void end_game(t_game *game, int code, char *msg)
{
	freeall(game);
	if (code != 0)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	else
	{
		printf("%s\n", msg);
	}
	exit(code);
}
