/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:23:40 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/06 10:58:15 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "stdlib.h"
#include "fcntl.h"
#include "lib/libft/libft.h"
#include "lib/ft_printf/ft_printf.h"
#include "lib/GNL/get_next_line.h"
#include "lib/minilibx/mlx.h"

#define TS 32

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_data
{
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

void	ft_init(t_data *param);
int		check_extension(char *av);
t_point ft_locate(char **map, char c);
int 	count_char(char **map, char c);
char	**free_map(char **map);
char	**check_map(char **map, char **av);
int		check_map_ann(char **map, char **av);
int		check_len(char **map);
int		check_start_last(char **map, char **av);
int		check_line(char *line);
size_t  count_line(char **av);
int 	check_fd(int fd);
void	check_endl(char **av);
char    *map_line(int i, char *line, char **map);
char	**ft_map(char **av);
int 	verif_map(char **av);
int 	check_count_char(char **map);
int		flood_fill(char **map, t_point start);
void	flood_fill_recursive(char **map, t_point start);
void	ft_error_map_init(void);
void    get_window(t_data *param, char **av);
void	clean_all(t_data *param);

#endif