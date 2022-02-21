/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:10:52 by vimercie          #+#    #+#             */
/*   Updated: 2022/02/14 17:24:52 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*bis;

	bis = b;
	while (len)
	{
		((unsigned char *)b)[len - 1] = c;
		len--;
	}
	return (bis);
}

size_t	ft_gnllen(const char *s, int n)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (n == 0)
	{
		while (s[i])
			i++;
	}
	else if (n == 1)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (i);
			i++;
		}
		return (-1);
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s1_len;
	char	*cpy;

	i = 0;
	s1_len = ft_gnllen(s1, 0);
	cpy = malloc(sizeof(char) * (s1_len + 1));
	if (!s1)
		return (NULL);
	if (!cpy)
		return (NULL);
	while (i < s1_len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
