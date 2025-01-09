/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:28:57 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/09 14:43:07 by mdegache         ###   ########.fr       */
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

void character_move(int keycode, t_data *param)
{
    param->count_move++;
    ft_printf("Number of moves : %d\n", param->count_move);
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
