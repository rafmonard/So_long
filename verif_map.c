/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:49:55 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/06 11:22:04 by mdegache         ###   ########.fr       */
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

int verif_map(char **av)
{
    char    **map;
    int flood;
    t_point start;

    map = ft_map(av);
	if (!map)
		return (0);
	if (!check_count_char(map))
		return (0);
	start = ft_locate(map, 'P');
	flood = flood_fill(map, (t_point){start.x, start.y});
	if (flood == 0)
	{
		ft_printf("Error\nYou can't go through the wall\n");
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}
