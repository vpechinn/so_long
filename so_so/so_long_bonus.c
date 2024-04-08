/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:50:38 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/05 18:42:54 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_food_fill(t_game *game)
{
	if (ft_food_fill(game, game->player_y, game->player_x) == 1)
	{
		write(2, "Error\n invalid path", 20);
		ft_free_game(game);
	}
}

void	ft_print_steps(t_game *game)
{
	game->images.step += 1;
	write(1, "step-", 5);
	ft_putnbr(game->images.step);
	write(1, "\n", 1);
}

int	ft_count_height(char *argv)
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
	close(fd);
	return (i);
}

void	ft_read_map(char *argv, t_game *game)
{
	int	fd;
	int	i;

	i = 0;
	ft_name_map(argv, game);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error \n Can`t open map", 23);
		ft_free_game(game);
	}
	game->game_map.height = ft_count_height(argv);
	game->game_map.array = malloc(sizeof(char *) * game->game_map.height);
	if (game->game_map.array == NULL)
		return ;
	while (i < game->game_map.height)
		game->game_map.array[i++] = get_next_line(fd);
	i = 0;
	ft_check_rectangle(game->game_map.array, game->game_map.height, game);
	ft_check_wall(game->game_map.array, game->game_map.height, game);
	ft_count_charect(game);
	ft_check_charact(game);
	ft_check_food_fill(game);
	ft_load_img(game);
	ft_draw_map(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc > 1)
	{
		game = malloc(sizeof(t_game));
		if (game == NULL)
			return (0);
		ft_read_map(argv[1], game);
	}
	else
	{
		write(2, "Error\n No args", 15);
		exit(0);
	}
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_hooks, game);
	mlx_hook(game->mlx_win, 17, 0, ft_close, game);
	mlx_loop_hook(game->mlx, ft_render, game);
	mlx_loop(game->mlx);
}
