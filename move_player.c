/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:28:57 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/07 14:58:46 by mdegache         ###   ########.fr       */
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
int key_press(int keycode, void *param)
{
    (void)param;
    ft_printf("Touche pressée : %d\n", keycode);
    if (keycode == 65307)
    {
        ft_printf("Window closed\n");
        exit(1);
    }
    return (0);
}
