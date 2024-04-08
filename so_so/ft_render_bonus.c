/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:00:11 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/03 20:48:21 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player_anime(t_game *game)
{
	if (game->images.frame == 5500)
	{
		ft_draw_dynamic(game, game->images.player_action,
			game->player_y, game->player_x);
		game->images.frame = 0;
	}
	else if (game->images.frame == 2000)
		ft_draw_dynamic(game, game->images.player,
			game->player_y, game->player_x);
	game->images.frame += 1;
}

int	ft_render(t_game *game)
{
	ft_player_anime(game);
	return (0);
}

static size_t	get_digits(int n)
{
	size_t	i;

	i = 1;
	while (n >= 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str_num)
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}
