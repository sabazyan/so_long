/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:21:25 by sabazyan          #+#    #+#             */
/*   Updated: 2022/07/31 13:05:12 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	no_exit(char **map, t_vars vars, int x, int y)
{
	if (vars.exit_y == x && vars.exit_x == y)
	{
		map[x][y] = 'E';
		put_img(y * SIZE, x * SIZE, vars, 'E');
	}
	else
		map[x][y] = '0';
}

int	left(char **map, t_vars vars, int scores)
{
	int	x;
	int	y;

	y = player_cord(map, 'x');
	x = player_cord(map, 'y');
	if (map[x][y - 1] == '1')
		return (0);
	else if (map[x][y - 1] == 'E' && scores == 0)
	{
		ft_printf("You win !!");
		ft_close(&vars);
	}
	else
		steps();
	if (map[x][y - 1] == 'C')
	{
		scores--;
		put_img((y - 1) * SIZE, x * SIZE, vars, '0');
	}
	put_img((y - 1) * SIZE, x * SIZE, vars, 'P');
	put_img(y * SIZE, x * SIZE, vars, '0');
	map[x][y - 1] = 'P';
	no_exit(map, vars, x, y);
	return (0);
}

int	right(char **map, t_vars vars, int scores)
{
	int	x;
	int	y;

	y = player_cord(map, 'x');
	x = player_cord(map, 'y');
	if (map[x][y + 1] == '1')
		return (0);
	else if (map[x][y + 1] == 'E' && scores == 0)
	{
		ft_printf("You win !!");
		ft_close(&vars);
	}
	else
		steps();
	if (map[x][y + 1] == 'C')
	{
		scores--;
		put_img((y + 1) * SIZE, x * SIZE, vars, '0');
	}
	put_img((y + 1) * SIZE, x * SIZE, vars, 'P');
	put_img(y * SIZE, x * SIZE, vars, '0');
	map[x][y + 1] = 'P';
	no_exit(map, vars, x, y);
	return (0);
}

int	up(char **map, t_vars vars, int scores)
{
	int	x;
	int	y;

	y = player_cord(map, 'x');
	x = player_cord(map, 'y');
	if (map[x - 1][y] == '1')
		return (0);
	else if (map[x - 1][y] == 'E' && scores == 0)
	{
		ft_printf("You win !!");
		ft_close(&vars);
	}
	else
		steps();
	if (map[x - 1][y] == 'C')
	{
		scores--;
		put_img(y * SIZE, (x - 1) * SIZE, vars, '0');
	}
	put_img(y * SIZE, (x - 1) * SIZE, vars, 'P');
	put_img(y * SIZE, x * SIZE, vars, '0');
	map[x - 1][y] = 'P';
	no_exit(map, vars, x, y);
	return (0);
}

int	down(char **map, t_vars vars, int scores)
{
	int	x;
	int	y;

	y = player_cord(map, 'x');
	x = player_cord(map, 'y');
	if (map[x + 1][y] == '1')
		return (0);
	else if (map[x + 1][y] == 'E' && scores == 0)
	{
		ft_printf("You win !!");
		ft_close(&vars);
	}
	else
		steps();
	if (map[x + 1][y] == 'C')
	{
		scores--;
		put_img(y * SIZE, (x + 1) * SIZE, vars, '0');
	}
	put_img(y * SIZE, (x + 1) * SIZE, vars, 'P');
	put_img(y * SIZE, x * SIZE, vars, '0');
	map[x + 1][y] = 'P';
	no_exit(map, vars, x, y);
	return (0);
}
