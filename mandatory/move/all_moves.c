/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:49:13 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 10:21:18 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *param)
{
	int	x;
	int	y;
	int	i;
	int	nb_line;
	int	len_line;

	y = 0;
	i = 0;
	nb_line = count_line(param->av);
	len_line = ft_strlen(param->map[0]);
	while (y < nb_line && i == 0)
	{
		x = 0;
		while (x < len_line && i == 0)
		{
			if (param->map[y][x] == 'P')
			{
				i = move_up_bis(param, x, y, i);
			}
			x++;
		}
		y++;
	}
}

void	move_down(t_data *param)
{
	int	x;
	int	y;
	int	i;
	int	nb_line;
	int	len_line;

	y = 0;
	i = 0;
	nb_line = count_line(param->av);
	len_line = ft_strlen(param->map[0]);
	while (y < nb_line && i == 0)
	{
		x = 0;
		while (x < len_line && i == 0)
		{
			if (param->map[y][x] == 'P')
			{
				i = move_down_bis(param, x, y, i);
			}
			x++;
		}
		y++;
	}
}

void	move_left(t_data *param)
{
	int	x;
	int	y;
	int	i;
	int	nb_line;
	int	len_line;

	y = 0;
	i = 0;
	nb_line = count_line(param->av);
	len_line = ft_strlen(param->map[0]);
	while (y < nb_line && i == 0)
	{
		x = 0;
		while (x < len_line && i == 0)
		{
			if (param->map[y][x] == 'P')
			{
				i = move_left_bis(param, x, y, i);
			}
			x++;
		}
		y++;
	}
}

void	move_right(t_data *param)
{
	int	x;
	int	y;
	int	i;
	int	nb_line;
	int	len_line;

	y = 0;
	i = 0;
	nb_line = count_line(param->av);
	len_line = ft_strlen(param->map[0]);
	while (y < nb_line && i == 0)
	{
		x = 0;
		while (x < len_line && i == 0)
		{
			if (param->map[y][x] == 'P')
			{
				i = move_right_bis(param, x, y, i);
			}
			x++;
		}
		y++;
	}
}
