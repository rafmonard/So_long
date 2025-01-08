/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:28:00 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/08 10:06:55 by mdegache         ###   ########.fr       */
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

void    init_image(t_data *param)
{
    int x;
    
    x = 32;
    param->empty = mlx_xpm_file_to_image(param->mlx, "sprites/grass.xpm", &x, &x);
    param->player = mlx_xpm_file_to_image(param->mlx, "sprites/player.xpm", &x, &x);
    param->wall = mlx_xpm_file_to_image(param->mlx, "sprites/tree.xpm", &x, &x);
    param->object = mlx_xpm_file_to_image(param->mlx, "sprites/chest.xpm", &x, &x);
    param->exit = mlx_xpm_file_to_image(param->mlx, "sprites/house.xpm", &x, &x);
}

void    set_image(t_data *param, char **av)
{
    int x;
    int y;
    int nb_line;
    int len_line;
    
    y = 0;
    nb_line = count_line(av);
    len_line = ft_strlen(param->map[0]);
    while (y < nb_line)
    {
        x = 0;
        while (x < len_line)
        {
            if (param->map[y][x] == 'P')
                mlx_put_image_to_window(param->mlx, param->win, param->player, x * 32, y * 32);
            else if (param->map[y][x] == '1')
                mlx_put_image_to_window(param->mlx, param->win, param->wall, x * 32, y * 32);
            else if (param->map[y][x] == 'C')
                mlx_put_image_to_window(param->mlx, param->win, param->object, x * 32, y * 32);
            else if (param->map[y][x] == 'E')
                mlx_put_image_to_window(param->mlx, param->win, param->exit, x * 32, y * 32);
            else
                mlx_put_image_to_window(param->mlx, param->win, param->empty, x * 32, y * 32);
            x++;
        }
        y++;
    }
}
