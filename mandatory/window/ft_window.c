/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:28:00 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 10:21:28 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_window(t_data *param, char **av)
{
	param->mlx = mlx_init();
	if (!param->mlx)
	{
		ft_printf("Error\nMlx failed\n");
		free_map(param->map);
		return ;
	}
	param->win = mlx_new_window(param->mlx, (ft_strlen(param->map[0]) * 32),
			(count_line(av) * 32), "so_long");
	if (!param->win)
	{
		ft_printf("Error\nWindow failed\n");
		free(param->mlx);
		free_map(param->map);
		return ;
	}
}

void	init_image(t_data *param)
{
	int	x;

	x = 32;
	init_empty(param, x);
	init_player(param, x);
	init_wall(param, x);
	init_object(param, x);
	init_exit(param, x);
}

void	set_image_to_map(t_data *param, int y, int len_line)
{
	int	x;

	x = 0;
	while (x < len_line)
	{
		if (param->map[y][x] == 'P')
			mlx_put_image_to_window(param->mlx, param->win, param->player,
				x * 32, y * 32);
		else if (param->map[y][x] == '1')
			mlx_put_image_to_window(param->mlx, param->win, param->wall,
				x * 32, y * 32);
		else if (param->map[y][x] == 'C')
			mlx_put_image_to_window(param->mlx, param->win, param->object,
				x * 32, y * 32);
		else if (param->map[y][x] == 'E')
			mlx_put_image_to_window(param->mlx, param->win, param->exit,
				x * 32, y * 32);
		else
			mlx_put_image_to_window(param->mlx, param->win, param->empty,
				x * 32, y * 32);
		x++;
	}
}

void	set_image(t_data *param, char **av)
{
	int	y;
	int	nb_line;
	int	len_line;

	y = 0;
	nb_line = count_line(av);
	len_line = ft_strlen(param->map[0]);
	while (y < nb_line)
	{
		set_image_to_map(param, y, len_line);
		y++;
	}
}
