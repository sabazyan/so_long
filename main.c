/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:22:40 by sabazyan          #+#    #+#             */
/*   Updated: 2022/07/31 13:47:15 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	steps(void)
{
	static int	count;

	count++;
	ft_putnbr(count);
	ft_printf("\n");
}

int	exit_cord(char **map, int c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (c == 'x')
					res = j;
				else if (c == 'y')
					res = i;
			}
			j++;
		}
		i++;
	}
	return (res);
}

int	player_cord(char **map, int c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (c == 'x')
					res = j;
				else if (c == 'y')
					res = i;
			}
			j++;
		}
		i++;
	}
	return (res);
}

int	find_coord(char **map, int c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	if (c == 'w')
		res = j;
	else
		res = i;
	return (res);
}

int	main(int ac, char **av)
{
	char	**map;
	char	*map_line;

	if (ac != 2)
		handle_error(2);
	is_ber(av[1]);
	map_line = line(av[1]);
	map = matrix(map_line);
	if (!map)
		handle_error(3);
	if (is_error(map) == 1 || sym_err(map) == 1 || nline_err(line(av[1])) == 1)
		handle_error(2);
	else
		start(map, av[1]);
	return (0);
}
