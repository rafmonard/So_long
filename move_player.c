/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:28:57 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/08 14:47:03 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win(void *param)
{
    (void)param;
    ft_printf("Window closed\n");
    exit(0);
    return (1);
}

void    check_exit(t_data *param)
{
    int x;
    int y;
    int nb_line;
    int len_line;
    
    y = 0;
    x = 0;
    nb_line = count_line(param->av);
    len_line = ft_strlen(param->map[0]);
    while (y < nb_line && param->map[y][x] != 'P')
    {
        x = 0;
        while (x < len_line && param->map[y][x] != 'P')
            x++;
        y++;
    }
    ft_printf("%d\n", x);
    ft_printf("%d\n", param->exit_position.x);
    ft_printf("%d\n", y);
    ft_printf("%d\n", param->exit_position.y);
    if (y == param->exit_position.x && x == param->exit_position.y)
    {
        ft_printf("You win !");
        exit(0);
    }
}

void character_move(int keycode, t_data *param)
{
    if (keycode == 119)
    {
        move_up(param);
        set_image(param, param->av);
        // check_exit(param);
        ft_printf("w\n");
    }
    if (keycode == 97)
    {
        move_left(param);
        set_image(param, param->av);
        // check_exit(param);
        ft_printf("a\n");
    }
    if (keycode == 115)
    {
        move_down(param);
        set_image(param, param->av);
        // check_exit(param);
        ft_printf("s\n");
    }
    if (keycode == 100)
    {
        move_right(param);
        set_image(param, param->av);
        // check_exit(param);
        ft_printf("d\n");
    }
}

int key_press(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307)
    {
        ft_printf("Window closed\n");
        exit(1);
    }
    character_move(keycode, param);
    return (0);
}
