/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:55:07 by vimercie          #+#    #+#             */
/*   Updated: 2022/02/14 17:48:15 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	*save_buf(char	buf[BUFFER_SIZE + 1])
{
	char	*tmp;
	int		i;
	int		j;

	i = ft_gnllen(buf, 1);
	j = 0;
	tmp = ft_strdup(buf);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	while (tmp[i])
		buf[j++] = tmp[i++];
	free(tmp);
}

static char	*ft_gnljoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_1;
	size_t	len_2;
	char	*str;

	i = 0;
	j = 0;
	len_1 = ft_gnllen(s1, 0);
	len_2 = ft_gnllen(s2, 1);
	if (len_2 == -1)
		len_2 = ft_gnllen(s2, 0);
	if (len_1 + len_2 <= 0)
		return (ft_strdup(s2));
	str = ft_calloc((len_1 + len_2) + 1, sizeof(char));
	if (s1 == NULL)
		return (ft_strdup(s2));
	while (s1[i])
		str[i] = s1[i++];
	while (s2[j] && s2[j] != '\n')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	if (s1 && s1[0] != '\0')
		free((char *)s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			read_return;

	line = NULL;
	read_return = 1;
	if (buffer[0] == '\0')
		read_return = read(fd, buffer, BUFFER_SIZE);
	while (read_return)
	{
		line = ft_gnljoin(line, buffer);
		dprintf(1, "----------buffer = %s\n", buffer);
		if (ft_gnllen(buffer, 1) >= 0)
		{
			save_buf(buffer);
			return (line);
		}
		read_return = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("phrase 1 = %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 2 = %s\n", str);
	free(str);
	// str = get_next_line(fd);
	// printf("phrase 3 = %s\n", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("phrase 4 = \nres : %s\n", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("phrase 5 = \nres : %s\n", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("phrase 6 = \nres : %s\n", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("phrase 7 = \nres : %s\n", str);
	// free(str);
}
