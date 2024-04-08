/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:36:42 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/05 18:43:40 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_rectangle(char **map, int height, t_game *g)
{
	int		i;
	size_t	width;

	i = 0;
	g->images.step = 0;
	width = ft_strlen(map[0]);
	while (i < height)
	{
		if (ft_strlen(map[i]) != width)
		{
			write(2, "Error\n wrong rectangle", 23);
			ft_free_game(g);
		}
		i++;
	}
}

void	ft_check_wall(char **map, int height, t_game *game)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = ft_strlen(map[i]);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != '1' && (i == 0 || i == (height - 1)))
			{
				write(2, "Error \n missed wall", 20);
				ft_free_game(game);
			}
			else if (map[i][j] != '1' && (j == 0 || j == (width - 1)))
			{
				write(2, "Error \n missed wall", 20);
				ft_free_game(game);
			}
			j++;
		}
		i++;
	}
}

void	ft_count_charect(t_game *game)
{
	int	i;
	int	j;
	int	width;

	i = 1;
	j = 0;
	width = ft_strlen(game->game_map.array[0]);
	game->game_map.player = 0;
	game->game_map.coin = 0;
	game->game_map.exit = 0;
	while (i < game->game_map.height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (game->game_map.array[i][j] == 'P')
				ft_check_position(game, i, j);
			else if (game->game_map.array[i][j] == 'C')
				game->game_map.coin++;
			else if (game->game_map.array[i][j] == 'E')
				game->game_map.exit++;
			j++;
		}
		i++;
	}
}

void	ft_check_charact(t_game *game)
{
	game->score = game->game_map.coin;
	if (game->game_map.coin < 1 || game->game_map.player != 1
		|| game->game_map.exit != 1)
	{
		write(2, "Error \n wrong character", 24);
		ft_free_game(game);
	}
	ft_check_field(game);
}

int	ft_food_fill(t_game *game, int y, int x)
{
	if (game->game_map.array[y][x] == 'c' || game->game_map.array[y][x] == 'e'
		|| game->game_map.array[y][x] == '1' ||
			game->game_map.array[y][x] == '9')
		return (0);
	else if (game->game_map.array[y][x] == '0')
		game->game_map.array[y][x] = '9';
	else if (game->game_map.array[y][x] == 'E')
	{
		game->game_map.exit -= 1;
		game->game_map.array[y][x] = 'e';
		return (0);
	}
	else if (game->game_map.array[y][x] == 'C')
	{
		game->game_map.coin -= 1;
		game->game_map.array[y][x] = 'c';
	}
	ft_food_fill(game, y - 1, x);
	ft_food_fill(game, y + 1, x);
	ft_food_fill(game, y, x - 1);
	ft_food_fill(game, y, x + 1);
	if (game->game_map.coin != 0 || game->game_map.exit != 0)
		return (1);
	else
		return (0);
}
