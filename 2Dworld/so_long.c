/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:50:38 by vpechinn          #+#    #+#             */
/*   Updated: 2024/03/23 20:14:04 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_height(t_game *game, char *argv)
{
	int		i;
	int		f;
	int		fd;
	char	*line;

	f = 1;
	i = 0;
	fd = open(argv, O_RDONLY);
	while (f)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		else
			f = 0;
		free(line);
	}
	return (i);
}

void	ft_read_map(char *argv, t_game *game)
{
	int	fd;
	int	i;

	i = 0;
	ft_name_map(argv);
	game->game_map.height = ft_count_height(game, argv);
	fd = open(argv, O_RDONLY);
	game->game_map.array = malloc(sizeof(char *) * game->game_map.height);
	if (game->game_map.array == NULL)
		return ;
	while (i < game->game_map.height)
	{
		game->game_map.array[i] = get_next_line(fd);
		// printf("str=%s\n", game->game_map.array[i]);
		i++;
	}
	ft_check_rectangle(game->game_map.array, game->game_map.height);
	ft_check_wall(game->game_map.array, game->game_map.height);
	ft_count_charect(game);
	ft_load_img(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (0);
	if (argc > 1)
		ft_read_map(argv[1], game);
	else
	{
		write(2, "Error\n No args", 15);
		exit (0);
	}
	//mlx_hook(game->mlx_win, 2, 1L << 0, ft_hooks, game);
	//game->images.frame = 0;
	return (0);
}