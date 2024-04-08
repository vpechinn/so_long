/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:59:33 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/03 20:49:43 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_display_step(t_game *game)
{
	char	*num;

	num = ft_itoa(game->images.step);
	ft_draw_static(game, game->images.wall, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 20, 20, 0xFFFFFFF, num);
	free(num);
}

void	ft_check_enemy_position(t_game *game, int y, int x)
{
	game->enemy_x = x;
	game->enemy_y = y;
}

void	ft_check_position(t_game *game, int y, int x)
{
	game->game_map.player++;
	game->player_x = x;
	game->player_y = y;
}

int	ft_name_map(char *argv, t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(argv) - 1;
	if (argv[k] == 'r')
		i++;
	if (argv[k - 1] == 'e')
		i++;
	if (argv[k - 2] == 'b')
		i++;
	if (argv[k - 3] == '.')
		i++;
	if (i != 4)
	{
		write(2, "Erorr'\n Wrong File\n", 18);
		free(game);
		exit (0);
	}
	return (1);
}

void	ft_load_img(t_game *game)
{
	game->game_map.width = ft_strlen(game->game_map.array[0]);
	game->size = 64;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->game_map.width * game->size,
			game->game_map.height * game->size, "so_long");
	game->images.wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
			&game->size, &game->size);
	game->images.chrono = mlx_xpm_file_to_image(game->mlx, "img/chrono.xpm",
			&game->size, &game->size);
	game->images.player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
			&game->size, &game->size);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
			&game->size, &game->size);
	game->images.coin = mlx_xpm_file_to_image(game->mlx, "img/coin.xpm",
			&game->size, &game->size);
	game->images.enemy = mlx_xpm_file_to_image(game->mlx, "img/enemy.xpm",
			&game->size, &game->size);
	game->images.player_action = mlx_xpm_file_to_image(game->mlx,
			"img/player1.xpm", &game->size, &game->size);
}
