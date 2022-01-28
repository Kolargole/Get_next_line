/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:55:07 by vimercie          #+#    #+#             */
/*   Updated: 2022/01/28 03:36:24 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE];
	static char	*tmp;
	static int	gnl_status;
	char		*res;
	size_t		i;

	gnl_status = read(fd, str, BUFFER_SIZE);
	res = "";
	i = 0;
	if (tmp)
	{
		res = malloc(sizeof(char) * ft_strlen(tmp));
		ft_memcpy(res, tmp, ft_strlen(tmp));
		free(tmp);
	}
	while (gnl_status > 0)
	{
		if (ft_strchr(str, '\n') == NULL)
			res = ft_strjoin(res, str);
		else
		{
			while (str[i] != '\n')
				i++;
			tmp = ft_substr(str, 0, i + 1);
			res = ft_strjoin(res, tmp);
			free(tmp);
			tmp = ft_substr(str, i + 1, ft_strlen(str) - (i + 1));
			return (res);
		}
		gnl_status = read(fd, str, BUFFER_SIZE);
		if (gnl_status == 0)
			free(tmp);
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("phrase 1 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 2 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 3 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 4 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 5 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 6 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 7 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 8 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 9 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 10 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 11 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 12 = \nres : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("phrase 13 = \nres : %s\n", str);
	free(str);
}
