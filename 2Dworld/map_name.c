/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:59:33 by vpechinn          #+#    #+#             */
/*   Updated: 2024/03/24 14:54:33 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_name_map(char *argv)
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
		exit (0);
	}
	return (1);
}

void	ft_load_img(t_game *game)
{
	game->size = 64;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->game_map.width * game->size, 
					game->game_map.height * game->size, "so_long");
	game->images.player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &game->size, &game->size);
	game->images.chrono = mlx_xpm_file_to_image(game->mlx, "img/chrono.xpm", &game->size, &game->size);
	game->images.wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &game->size, &game->size);
	game->images.exit = mlx_xpm_file_to_image(game->mlx, "img/coin.xpm", &game->size, &game->size);
	
}

