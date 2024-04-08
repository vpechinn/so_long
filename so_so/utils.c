/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:21:56 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/05 18:31:55 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->game_map.height)
	{
		free(game->game_map.array[i]);
		i++;
	}
	free(game->game_map.array);
	free(game);
	exit(0);
}

int	ft_close(t_game *game)
{
	ft_free_game(game);
	exit (0);
	return (0);
}

void	ft_check_field(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->game_map.height - 1)
	{
		j = 1;
		while (j < game->game_map.width - 1)
		{
			if (game->game_map.array[i][j] != '1'
			&& game->game_map.array[i][j] != '0'
				&& game->game_map.array[i][j] != 'P'
				&& game->game_map.array[i][j] != 'E'
				&& game->game_map.array[i][j] != 'C')
			{
				write(2, "Error \n wrong character", 24);
				ft_free_game(game);
			}
			j++;
		}
		i++;
	}
}
