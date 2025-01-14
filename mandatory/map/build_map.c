/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:14:21 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 10:21:07 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	count_line(char **av)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(av[1], O_RDONLY);
	check_fd(fd);
	count = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nFile is empty\n");
		exit(0);
	}
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\nInvalid fd\n");
		exit(0);
	}
}

void	check_endl(char **av)
{
	int		fd;
	char	*line;
	int		i;
	size_t	count_endl;

	count_endl = 0;
	fd = open(av[1], O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n')
				count_endl++;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}

char	*map_line(int i, char *line, char **map)
{
	int	j;

	j = 0;
	map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!map[i])
	{
		while (i-- > 0)
			free(map[i]);
		free(map);
		return (NULL);
	}
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		map[i][j] = line[j];
		j++;
	}
	map[i][j] = '\0';
	free(line);
	return (map[i]);
}

char	**ft_map(char **av)
{
	int		i;
	int		len_map;
	int		fd;
	char	*line;
	char	**map;

	check_endl(av);
	fd = open(av[1], O_RDONLY);
	check_fd(fd);
	i = 0;
	len_map = count_line(av);
	map = malloc(sizeof(char *) * (len_map + 1));
	if (!map)
		return (NULL);
	while (i < len_map || get_next_line(fd))
	{
		line = get_next_line(fd);
		map[i] = map_line(i, line, map);
		if (!map[i++])
			return (NULL);
	}
	map[i] = NULL;
	close(fd);
	return (check_map(map, av));
}
