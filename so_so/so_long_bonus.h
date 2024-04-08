/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:50:43 by vpechinn          #+#    #+#             */
/*   Updated: 2024/04/05 18:35:24 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# define BUFFER_SIZE 42

typedef struct s_map
{
	int		height;
	int		width;
	int		player;
	int		coin;
	int		exit;
	int		wall;
	int		chrono;
	int		enemy;
	char	**array;
}	t_map;

typedef struct s_img
{
	void	*(player);
	void	*(coin);
	void	*(exit);
	void	*(chrono);
	void	*(wall);
	void	*(enemy);
	int		frame;
	int		step;
	void	*(player_action);
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		size;
	int		flag;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		score;
	t_map	game_map;
	t_img	images;
}	t_game;

char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_remainder(char	*str);
char	*ft_substr(char *s, unsigned int start, size_t len);

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_load_img(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_draw_dynamic(t_game *game, void *cell, int x, int y);
void	ft_draw_static(t_game *game, void *cell, int x, int y);
void	ft_print_steps(t_game *game);
void	ft_check_enemy_position(t_game *game, int y, int x);
void	ft_display_step(t_game *game);

size_t	ft_strlen(const char *s);

int		ft_hooks(int key, t_game *game);
int		ft_name_map(char *argv, t_game *game);
int		ft_count_height(char *argv);
int		ft_food_fill(t_game *game, int y, int x);
int		ft_close(t_game *game);

void	ft_check_wall(char **map, int height, t_game *game);
void	ft_count_charect(t_game *game);
void	ft_check_rectangle(char **game, int height, t_game *g);
void	ft_check_charact(t_game *game);
void	ft_check_position(t_game *game, int y, int x);
void	ft_free_game(t_game *game);
void	ft_check_field(t_game *game);

int		ft_render(t_game *game);

#endif
