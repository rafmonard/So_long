/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:49:55 by mdegache          #+#    #+#             */
/*   Updated: 2024/12/28 12:48:26 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point ft_locate(char **map, char c)
{
    t_point	position;
	int		x;
	int		y;

	position.x = -1;
	position.y = -1;
	x = 0;
	y = 0;
	while (map[x] && map[x][y] != '\0')
	{
		if (map[x][y] == c)
		{
			position.x = x;
			position.y = y;
			return (position);
		}
		y++;
		if (map[x][y] == '\0')
		{
			x++;
			y = 0;
		}
	}
	return (position);
}

int count_char(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
