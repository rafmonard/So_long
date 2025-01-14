/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_move_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:00:09 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 10:56:35 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_up_bis(t_data *param, int x, int y, int i)
{
	if (param->map[y - 1][x] == 'E' && count_char(param->map, 'C') == 0)
		mlx_loop_end(param->mlx);
	if (param->map[y - 1][x] != '1')
	{
		param->map[y - 1][x] = 'P';
		if (y == param->exit_position.x && x == param->exit_position.y)
			param->map[y][x] = 'E';
		else
			param->map[y][x] = '0';
		i = 1;
		print_move(param);
	}
	return (i);
}

int	move_down_bis(t_data *param, int x, int y, int i)
{
	if (param->map[y + 1][x] == 'E' && count_char(param->map, 'C') == 0)
		mlx_loop_end(param->mlx);
	if (param->map[y + 1][x] != '1')
	{
		param->map[y + 1][x] = 'P';
		if (y == param->exit_position.x && x == param->exit_position.y)
			param->map[y][x] = 'E';
		else
			param->map[y][x] = '0';
		i = 1;
		print_move(param);
	}
	return (i);
}

int	move_left_bis(t_data *param, int x, int y, int i)
{
	if (param->map[y][x - 1] == 'E' && count_char(param->map, 'C') == 0)
		mlx_loop_end(param->mlx);
	if (param->map[y][x - 1] != '1')
	{
		param->map[y][x - 1] = 'P';
		if (y == param->exit_position.x && x == param->exit_position.y)
			param->map[y][x] = 'E';
		else
			param->map[y][x] = '0';
		i = 1;
		print_move(param);
	}
	return (i);
}

int	move_right_bis(t_data *param, int x, int y, int i)
{
	if (param->map[y][x + 1] == 'E' && count_char(param->map, 'C') == 0)
		mlx_loop_end(param->mlx);
	if (param->map[y][x + 1] != '1')
	{
		param->map[y][x + 1] = 'P';
		if (y == param->exit_position.x && x == param->exit_position.y)
			param->map[y][x] = 'E';
		else
			param->map[y][x] = '0';
		print_move(param);
		i = 1;
	}
	return (i);
}
