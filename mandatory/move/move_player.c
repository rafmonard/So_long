/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:28:57 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 11:15:41 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(t_data *param)
{
	mlx_loop_end(param->mlx);
	return (0);
}

void	character_move(int keycode, t_data *param)
{
	if (keycode == 119)
	{
		move_up(param);
		set_image(param, param->av);
	}
	if (keycode == 97)
	{
		move_left(param);
		set_image(param, param->av);
	}
	if (keycode == 115)
	{
		move_down(param);
		set_image(param, param->av);
	}
	if (keycode == 100)
	{
		move_right(param);
		set_image(param, param->av);
	}
}

int	key_press(int keycode, t_data *param)
{
	if (keycode == 65307)
		mlx_loop_end(param->mlx);
	character_move(keycode, param);
	print_win(param);
	return (0);
}

void	print_move(t_data *param)
{
	param->count_move++;
	ft_printf("Number of moves : %d\n", param->count_move);
}

void	print_win(t_data *param)
{
	char	*nb_move;

	nb_move = ft_itoa(param->count_move);
	mlx_string_put(param->mlx, param->win, 75, 18, 0xFFFFFF, nb_move);
	mlx_string_put(param->mlx, param->win, 20, 16, 0xFFFFFF, "nb move :");
	free (nb_move);
}
