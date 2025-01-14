/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:39:12 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 10:21:02 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
	{
		ft_printf("Error\nFirst or last caracter is invalid\n");
		return (0);
	}
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P')
		{
			ft_printf("Error\nInvalid characters in map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_start_last(char **map, char **av)
{
	int	i;
	int	last;

	last = count_line(av);
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[last - 1][i])
	{
		if (map[last - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_len(char **map)
{
	size_t	original_len;
	int		j;

	j = 1;
	original_len = ft_strlen(map[0]);
	while (map[j])
	{
		if (ft_strlen(map[j]) != original_len)
			return (0);
		j++;
	}
	return (1);
}

int	check_map_ann(char **map, char **av)
{
	if (check_len(map) == 0)
	{
		ft_printf("Error\nInconsistent line length\n");
		return (0);
	}
	if (ft_strlen(map[0]) + 1 > 60 || count_line(av) > 30)
	{
		ft_printf("Error\nMap size exceeds limit\n");
		return (0);
	}
	if (check_start_last(map, av) == 0)
	{
		ft_printf("Error\nFirst or last line is invalid\n");
		return (0);
	}
	return (1);
}

char	**check_map(char **map, char **av)
{
	int	i;
	int	total_lines;

	total_lines = count_line(av);
	i = 1;
	if (check_map_ann(map, av) == 0)
		return (free_map(map));
	while (map[i] && i < total_lines)
	{
		if (!check_line(map[i]))
			return (free_map(map));
		i++;
	}
	return (map);
}
