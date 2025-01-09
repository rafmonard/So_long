/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:49:13 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/09 15:51:14 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_data  *param)
{
    int x;
    int y;
    int i;
    int nb_line;
    int len_line;
    
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
                if (param->map[y - 1][x] == 'E' && count_char(param->map, 'C') == 0)
                {
                    ft_printf("You win !\n");
                    exit(0);
                }
                if (param->map[y - 1][x] != '1')
                {
                    param->map[y - 1][x] = 'P';
                    if (y == param->exit_position.x && x == param->exit_position.y)
                        param->map[y][x] = 'E';
                    else
                        param->map[y][x] = '0';
                    i = 1;
                }
            }
            x++;
        }
        y++;
    }
}

void    move_down(t_data *param)
{
    int x;
    int y;
    int i;
    int nb_line;
    int len_line;
    
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
                if (param->map[y + 1][x] == 'E' && count_char(param->map, 'C') == 0)
                {
                    ft_printf("You win !\n");
                    exit(0);
                }
                if (param->map[y + 1][x] != '1')
                {
                    param->map[y + 1][x] = 'P';
                    if (y == param->exit_position.x && x == param->exit_position.y)
                        param->map[y][x] = 'E';
                    else
                        param->map[y][x] = '0';
                    i = 1;
                }
            }
            x++;
        }
        y++;
    }
}

void    move_left(t_data *param)
{
    int x;
    int y;
    int i;
    int nb_line;
    int len_line;
    
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
                if (param->map[y][x - 1] == 'E' && count_char(param->map, 'C') == 0)
                {
                    ft_printf("You win !\n");
                    exit(0);
                }
                if (param->map[y][x - 1] != '1')
                {
                    param->map[y][x - 1] = 'P';
                    if (y == param->exit_position.x && x == param->exit_position.y)
                        param->map[y][x] = 'E';
                    else
                        param->map[y][x] = '0';
                    i = 1;
                }
            }
            x++;
        }
        y++;
    }
}

void    move_right(t_data *param)
{
    int x;
    int y;
    int i;
    int nb_line;
    int len_line;
    
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
                if (param->map[y][x + 1] == 'E' && count_char(param->map, 'C') == 0)
                {
                    ft_printf("You win !\n");
                    exit(0);
                }
                if (param->map[y][x + 1] != '1')
                {
                    param->map[y][x + 1] = 'P';
                    if (y == param->exit_position.x && x == param->exit_position.y)
                        param->map[y][x] = 'E';
                    else
                        param->map[y][x] = '0';
                    i = 1;
                }
            }
            x++;
        }
        y++;
    }
}
