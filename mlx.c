/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:00:08 by sabazyan          #+#    #+#             */
/*   Updated: 2022/08/08 15:33:17 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_close(t_vars *vars)
{
	(void)vars;
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	char	**map;
	int		scores;

	map = vars->map;
	scores = p_c_e_error(map, 'C');
	if (keycode == 53)
		exit(0);
	else if (keycode == 0 || keycode == 123)
		left(map, *vars, scores);
	else if (keycode == 2 || keycode == 124)
		right(map, *vars, scores);
	else if (keycode == 13 || keycode == 126)
		up(map, *vars, scores);
	else if (keycode == 1 || keycode == 125)
		down(map, *vars, scores);
	return (0);
}

void	creating_map(int fd, t_vars vars, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(void)fd;
	y = 0;
	i = 0;
	while (y < SIZE * find_coord(map, 'h'))
	{
		x = 0;
		j = 0;
		while (x < SIZE * find_coord(map, 'w'))
		{
			put_img(x, y, vars, '0');
			put_img(x, y, vars, map[i][j]);
			x += SIZE;
			j++;
		}
		y += SIZE;
		i++;
	}
}

void	start(char **map, char *path)
{
	int		fd;
	t_vars	vars;
	int		x;
	int		y;

	x = find_coord(map, 'w') * SIZE;
	y = find_coord(map, 'h') * SIZE;
	fd = open(path, O_RDONLY);
	vars.map = map;
	vars.exit_x = exit_cord(vars.map, 'x');
	vars.exit_y = exit_cord(vars.map, 'y');
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "Hello from Jerry!");
	creating_map(fd, vars, vars.map);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
