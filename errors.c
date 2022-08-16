/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:52:08 by sabazyan          #+#    #+#             */
/*   Updated: 2022/07/30 13:06:22 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	first_last(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_error(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	if (!first_last(map[0]))
		handle_error(4);
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	if (!first_last(map[i - 1]))
		handle_error(4);
	return (1);
}

int	p_c_e_error(char **map, int c)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] && map[j][i] != '\n')
		{
			if (map[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

void	is_ber(char *path)
{
	int	len;

	len = ft_strlen(path) - 1;
	if (path[len] != 'r' || path[len - 1] != 'e' || path[len - 2] != 'b')
		handle_error(1);
}

int	is_error(char **map)
{
	if (wall_error(map) == 0 || p_c_e_error(map, 'P') != 1)
		return (1);
	else if (p_c_e_error(map, 'C') < 1 || p_c_e_error(map, 'E') < 1)
		return (1);
	else
		return (0);
}
