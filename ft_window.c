/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:28:00 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/06 14:52:49 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_window(t_data *param, char **av)
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
void    set_image(t_data *param, char **av)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (param->map[y] != NULL)
    {
        while (param->map[y][x] != NULL)
        {
            mlx_put_image_to_window(param->mlx, param->win, );
            x++;
        }
        y++;
    }
}