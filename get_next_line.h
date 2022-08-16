/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:25:44 by sabazyan          #+#    #+#             */
/*   Updated: 2022/08/16 16:45:34 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef SIZE
#  define SIZE 150
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		exit_x;
	int		exit_y;
}	t_vars;

char	*get_next_line(int fd);
char	*ft_strdup(char	*s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char	*s);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		first_last(char	*str);
int		wall_error(char **map);
int		p_c_e_error(char **map, int c);
int		is_error(char **map);
void	start(char **map, char *path);
int		ft_close(t_vars *vars);
int		key_hook(int keycode, t_vars	*vars);
void	to_exit(void);
void	put_img(int x, int y, t_vars vars, int ch);
void	creating_map(int fd, t_vars vars, char **map);
char	*line(char *path);
char	**matrix(char *line);
char	**ft_split(char *s, char c);
void	handle_error(int err_code);
int		sym_err(char **map);
int		nline_err(char *line);
void	is_ber(char *path);
void	ft_putchar(int c);
void	ft_putnbr(int nb);
void	ft_printf(char *str);
int		find_coord(char **map, int c);
int		player_cord(char **map, int c);
int		exit_cord(char **map, int c);
int		left(char **map, t_vars vars, int scores);
int		right(char **map, t_vars vars, int scores);
int		up(char **map, t_vars vars, int scores);
int		down(char **map, t_vars vars, int scores);
void	steps(void);

#endif
