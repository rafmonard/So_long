/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:23:40 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 10:58:23 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "stdlib.h"
# include "fcntl.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/GNL/get_next_line.h"
# include "lib/minilibx/mlx.h"

# define TS 32

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_data
{
	char	**av;
	char	**map;
	void	*wall;
	void	*empty;
	void	*object;
	void	*player;
	void	*exit;
	void	*mlx;
	void	*win;
	int		count_move;
	int		count_star;
	int		total_star;
	t_point	exit_position;
}			t_data;

typedef struct s_count
{
	int		c;
	int		e;
	int		p;
}			t_count;

/*
main.c
*/

void	ft_init(t_data *param, char **av);
int		check_extension(char *av);

/*
all_move_bis.c
*/

int		move_up_bis(t_data *param, int x, int y, int i);
int		move_down_bis(t_data *param, int x, int y, int i);
int		move_left_bis(t_data *param, int x, int y, int i);
int		move_right_bis(t_data *param, int x, int y, int i);

/*
all_move.c
*/

void	move_up(t_data *param);
void	move_down(t_data *param);
void	move_left(t_data *param);
void	move_right(t_data *param);

/*
build_map.c
*/

size_t	count_line(char **av);
void	check_fd(int fd);
void	check_endl(char **av);
char	*map_line(int i, char *line, char **map);
char	**ft_map(char **av);

/*
check_map.c
*/

char	**check_map(char **map, char **av);
int		check_map_ann(char **map, char **av);
int		check_len(char **map);
int		check_start_last(char **map, char **av);
int		check_line(char *line);

/*
flood_fill.c
*/

int		check_count_char(char **map);
int		flood_fill(char **map, t_point start);
void	flood_fill_recursive(char **map, t_point start);

/*
free_funct.c
*/

char	**free_map(char **map);
void	clean_all(t_data *param);

/*
ft_window.c
*/

void	set_image(t_data *param, char **av);
void	get_window(t_data *param, char **av);
void	init_image(t_data *param);
void	set_image_to_map(t_data *param, int y, int len_line);

/*
init_image.c
*/

void	init_exit(t_data *param, int x);
void	init_object(t_data *param, int x);
void	init_wall(t_data *param, int x);
void	init_player(t_data *param, int x);
void	init_empty(t_data *param, int x);

/*
move_player.c
*/

int		close_win(t_data *param);
int		key_press(int keycode, t_data *param);
void	character_move(int keycode, t_data *param);
void	print_move(t_data *param);
void	print_win(t_data *param);

/*
verif_map.c
*/

t_point	ft_locate(char **map, char c);
int		count_char(char **map, char c);
int		verif_map(char **av);

#endif