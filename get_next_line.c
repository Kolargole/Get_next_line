/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:55:07 by vimercie          #+#    #+#             */
/*   Updated: 2021/12/02 17:16:38 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE];
	static char	*tmp;
	char		*res;
	size_t		i;
	int			gnl_status;

	res = "";
	if (tmp)
	{
		res = tmp;
		free(tmp);
	}
	while (res[ft_strlen(res) - 1] != '\n')
	{
		i = 0;
		gnl_status = read(fd, str, BUFFER_SIZE);
		// printf("gnl_status = %d\n", gnl_status);
		while (str[i] && str[i] != '\n')
			i++;
		// printf("i = %zu\n", i);
		tmp = ft_substr(str, 0, i + 1);
		res = ft_strjoin(res, tmp);
		free(tmp);
		if (res[ft_strlen(res) - 1] == '\n')
			tmp = ft_substr(str, i + 1, BUFFER_SIZE - i);
	}
	if (gnl_status > 0)
		return (res);
	free(res);
	return (NULL);
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
