/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:47:35 by mdegache          #+#    #+#             */
/*   Updated: 2024/12/29 10:15:16 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_all(t_data *param)
{
	if (param->wall)
		mlx_destroy_image(param->mlx, param->wall);
	if (param->exit)
		mlx_destroy_image(param->mlx, param->exit);
	if (param->object)
		mlx_destroy_image(param->mlx, param->object);
	if (param->player)
		mlx_destroy_image(param->mlx, param->player);
	if (param->empty)
		mlx_destroy_image(param->mlx, param->empty);
	if (param->win)
		mlx_destroy_window(param->mlx, param->win);
	if (param->mlx)
	{
		mlx_destroy_display(param->mlx);
		free(param->mlx);
	}
	free_map(param->map);
}

char	**free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	ft_error_map_init(void)
{
	ft_printf("Error\nMap ends with an empty line\n");
	exit(0);
}