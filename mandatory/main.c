/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:23:09 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/14 10:25:38 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *av)
{
	int		i;
	int		j;
	char	*ext;

	i = ft_strlen(av) - 4;
	j = 0;
	ext = ".ber";
	while (av[i] == ext[j])
	{
		if (ext[j + 1] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}

void	ft_init(t_data *param, char **av)
{
	param->av = av;
	param->count_move = 0;
	param->count_star = 0;
	param->total_star = count_char(param->map, 'C');
	param->exit_position = ft_locate(param->map, 'E');
}

int	main(int ac, char **av)
{
	t_data	param;

	if (ac != 2 || !check_extension(av[1]))
	{
		ft_printf("Error\nThe arg is not valid\n");
		return (0);
	}
	if (verif_map(av) == 0)
		return (0);
	param.map = ft_map(av);
	if (!param.map)
	{
		ft_printf("Error\nInvalid map\n");
		return (0);
	}
	ft_init(&param, av);
	get_window(&param, param.av);
	init_image(&param);
	set_image(&param, param.av);
	mlx_hook(param.win, 17, 0, close_win, &param);
	mlx_key_hook(param.win, key_press, &param);
	mlx_loop(param.mlx);
	free_map(param.map);
	clean_all(&param);
	ft_printf("The end...\n");
}
