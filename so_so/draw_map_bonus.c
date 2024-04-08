/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:57:27 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/05 17:43:28 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_player(t_game *game, int y, int x)
{
	if (game->game_map.array[game->player_y - y][game->player_x - x] == '1')
		return ;
	if (game->game_map.array[game->player_y - y][game->player_x - x] == 'c')
	{
		game->game_map.array[game->player_y - y][game->player_x - x] = '9';
		game->score--;
	}
	if (game->game_map.array[game->player_y - y][game->player_x - x] == 'e')
	{
		if (game->score == game->game_map.coin)
		{
			ft_free_game(game);
			exit (0);
		}
		else
			return ;
	}
	if (game->game_map.array[game->player_y - y][game->player_x - x] == 'S')
		ft_free_game(game);
	ft_print_steps(game);
	ft_draw_dynamic(game, game->images.chrono, game->player_y, game->player_x);
	game->player_x -= x;
	game->player_y -= y;
	ft_draw_dynamic(game, game->images.player, game->player_y, game->player_x);
}

int	ft_hooks(int key, t_game *game)
{
	if (key == 13)
		ft_move_player(game, 1, 0);
	if (key == 1)
		ft_move_player(game, -1, 0);
	if (key == 0)
		ft_move_player(game, 0, 1);
	if (key == 2)
		ft_move_player(game, 0, -1);
	if (key == 53)
		ft_free_game(game);
	ft_display_step(game);
	return (0);
}

void	ft_draw_static(t_game *game, void *cell, int y, int x)
{
	x = x * game->size;
	y = y * game->size;
	mlx_put_image_to_window(game->mlx, game->mlx_win, cell, x, y);
}

void	ft_draw_dynamic(t_game *game, void *cell, int y, int x)
{
	x = x * game->size;
	y = y * game->size;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->images.chrono, x, y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, cell, x, y);
}

void	ft_draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->game_map.height)
	{
		x = 0;
		while (x < game->game_map.width)
		{
			if (game->game_map.array[y][x] == '1')
				ft_draw_static(game, game->images.wall, y, x);
			else if (game->game_map.array[y][x] == '9')
				ft_draw_static(game, game->images.chrono, y, x);
			else if (game->game_map.array[y][x] == 'e')
				ft_draw_static(game, game->images.exit, y, x);
			else if (game->game_map.array[y][x] == 'P')
				ft_draw_dynamic(game, game->images.player, y, x);
			else if (game->game_map.array[y][x] == 'c')
				ft_draw_dynamic(game, game->images.coin, y, x);
			else if (game->game_map.array[y][x] == 'S')
				ft_draw_dynamic(game, game->images.enemy, y, x);
			x++;
		}
		y++;
	}
}
