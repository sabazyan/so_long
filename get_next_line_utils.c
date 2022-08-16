/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:32:57 by sabazyan          #+#    #+#             */
/*   Updated: 2022/07/30 16:00:26 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char	*s1)
{
	char	*s;
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(s1) + 1;
	s = malloc(size * sizeof(char));
	if (!s || !s1)
		return (NULL);
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!p)
		return (NULL);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	if (s1)
		free(s1);
	return (p);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	sym;

	i = 0;
	sym = c;
	if (!str || !*str)
		return (NULL);
	while (str && str[i] && str[i] != sym)
		i++;
	if (str[i] == sym)
		return ((char *)(str + i));
	return (NULL);
}

size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size;
	size_t	mlen;

	if (!s || !*s)
		return (NULL);
	size = ft_strlen(s);
	if (len == 0 || start > size)
		mlen = 0;
	else if (size - start + 1 > len)
		mlen = len;
	else
		mlen = size - start;
	ptr = malloc((mlen + 1) * sizeof(char));
	i = 0;
	if (!ptr)
		return (NULL);
	while (s && s[i] && len && size > start)
	{
		ptr[i++] = s[start++];
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
