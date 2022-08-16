/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:24:33 by sabazyan          #+#    #+#             */
/*   Updated: 2022/07/31 12:45:01 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	handle_error(int err_code)
{
	if (err_code == 1)
		ft_printf("File path not correct or file is not readable!");
	else if (err_code == 2)
		ft_printf("Map is not correct!");
	else if (err_code == 3)
		ft_printf("There is no map!");
	else if (err_code == 4)
		ft_printf("Wall errors!");
	exit(0);
}

int	sym_err(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
					&& map[i][j] != 'C' && map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	nline_err(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			free(line);
			return (1);
		}
		i++;
	}
	free(line);
	return (0);
}	

char	*line(char *path)
{
	int		fd;
	char	*line_map;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_error(1);
	line_map = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (!line_map)
			line_map = ft_strdup(tmp);
		else
			line_map = ft_strjoin(line_map, tmp);
		free(tmp);
	}
	return (line_map);
}

char	**matrix(char *line)
{
	char	**splited_map;

	if (line)
	{
		splited_map = ft_split(line, '\n');
		free(line);
		return (splited_map);
	}
	return (NULL);
}
