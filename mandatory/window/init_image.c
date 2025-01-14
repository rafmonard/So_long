/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:40:49 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 10:21:31 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_empty(t_data *param, int x)
{
	param->empty = mlx_xpm_file_to_image(param->mlx, "sprites/grass.xpm",
			&x, &x);
	if (!param->empty)
	{
		free_map(param->map);
		mlx_clear_window(param->mlx, param->win);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
}

void	init_player(t_data *param, int x)
{
	param->player = mlx_xpm_file_to_image(param->mlx, "sprites/player.xpm",
			&x, &x);
	if (!param->player)
	{
		free_map(param->map);
		mlx_destroy_image(param->mlx, param->empty);
		mlx_clear_window(param->mlx, param->win);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
}

void	init_wall(t_data *param, int x)
{
	param->wall = mlx_xpm_file_to_image(param->mlx, "sprites/tree.xpm",
			&x, &x);
	if (!param->wall)
	{
		free_map(param->map);
		mlx_destroy_image(param->mlx, param->empty);
		mlx_destroy_image(param->mlx, param->player);
		mlx_clear_window(param->mlx, param->win);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
}

void	init_object(t_data *param, int x)
{
	param->object = mlx_xpm_file_to_image(param->mlx, "sprites/chest.xpm",
			&x, &x);
	if (!param->object)
	{
		free_map(param->map);
		mlx_destroy_image(param->mlx, param->empty);
		mlx_destroy_image(param->mlx, param->player);
		mlx_destroy_image(param->mlx, param->wall);
		mlx_clear_window(param->mlx, param->win);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
}

void	init_exit(t_data *param, int x)
{
	param->exit = mlx_xpm_file_to_image(param->mlx, "sprites/house.xpm",
			&x, &x);
	if (!param->exit)
	{
		free_map(param->map);
		mlx_destroy_image(param->mlx, param->empty);
		mlx_destroy_image(param->mlx, param->player);
		mlx_destroy_image(param->mlx, param->wall);
		mlx_destroy_image(param->mlx, param->object);
		mlx_clear_window(param->mlx, param->win);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
}
