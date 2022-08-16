/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:20:36 by sabazyan          #+#    #+#             */
/*   Updated: 2022/08/08 15:36:41 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	put_img(int x, int y, t_vars vars, int ch)
{
	void	*img;
	int		width;
	int		height;

	if (ch == '1')
		img = mlx_xpm_file_to_image(vars.mlx, "./images/wall.xpm",
				&width, &height);
	else if (ch == '0')
		img = mlx_xpm_file_to_image(vars.mlx, "./images/space.xpm",
				&width, &height);
	else if (ch == 'P')
		img = mlx_xpm_file_to_image(vars.mlx, "./images/player.xpm",
				&width, &height);
	else if (ch == 'E')
		img = mlx_xpm_file_to_image(vars.mlx, "./images/exit.xpm",
				&width, &height);
	else if (ch == 'C')
		img = mlx_xpm_file_to_image(vars.mlx, "./images/collectible.xpm",
				&width, &height);
	else
		return ;
	mlx_put_image_to_window(vars.mlx, vars.win, img, x, y);
}
