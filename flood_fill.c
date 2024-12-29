/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:18:39 by mdegache          #+#    #+#             */
/*   Updated: 2024/12/29 10:37:37 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_recursive(char **map, t_point start)
{
	if (map[start.x][start.y] == '1')
		return ;
	map[start.x][start.y] = '1';
	flood_fill_recursive(map, (t_point){start.x + 1, start.y});
	flood_fill_recursive(map, (t_point){start.x - 1, start.y});
	flood_fill_recursive(map, (t_point){start.x, start.y + 1});
	flood_fill_recursive(map, (t_point){start.x, start.y - 1});
	return ;
}

int	flood_fill(char **map, t_point start)
{
	int	i;
	int	j;

	flood_fill_recursive(map, start);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_count_char(char **map)
{
	t_count	count;

	count.c = count_char(map, 'C');
	count.e = count_char(map, 'E');
	count.p = count_char(map, 'P');
	if (count.c == 0 || count.e != 1 || count.p != 1)
	{
		ft_printf("Error\nToo much or not enough of one char\n");
		free_map(map);
		return (0);
	}
	return (1);
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
