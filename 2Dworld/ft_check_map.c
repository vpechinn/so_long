/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:36:42 by vpechinn          #+#    #+#             */
/*   Updated: 2024/03/23 19:59:45 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangle(char **map, int	height)
{
	int		i;
	size_t	width;

	i = 0;
	width = ft_strlen(map[0]);
	while (i < height)
	{
		if (ft_strlen(map[i]) != width)
		{
			write(2, "Error\n wrong rectangle", 23);
			exit(0);
		}
		i++;
	}
}

void	ft_check_wall(char **map, int height)
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
				exit(0);
			}
			else if (map[i][j] != '1' &&  (j == 0  || j == (width - 1)))
			{
				write(2, "Error \n missed wall", 20);
				exit(0);
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
				game->game_map.player++;
			else if (game->game_map.array[i][j] == 'C')
				game->game_map.coin++;
			else if (game->game_map.array[i][j] == 'E')
				game->game_map.exit++;
			j++;
		}
		i++;
	}
	ft_check_charact(game);
}

void	ft_check_charact(t_game *game)
{
	if (game->game_map.coin < 1 || game->game_map.player != 1 || game->game_map.exit != 1)
	{
		write(2, "Error \n wrong character", 24);
		exit(0);
	}
}