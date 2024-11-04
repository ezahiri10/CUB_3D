/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:02:01 by sel-hasn          #+#    #+#             */
/*   Updated: 2024/11/04 14:26:29 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)ft_malloc(sizeof(char) * (i + 1), 1);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*rest_of_str(char *s)
{
	int		i;
	int		j;
	char	*rst;

	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (NULL);
	if (s[i] == '\n')
		i++;
	while (s[i + j] != '\0')
		j++;
	rst = ft_substr(s, i, j);
	if (!rst)
		return (NULL);
	return (rst);
}

char	*read_line(char *s, int fd)
{
	char	*buffer;
	ssize_t	y;

	if (!s)
	{
		s = ft_strdup("");
		if (!s)
			return (NULL);
	}
	buffer = (char *)ft_malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1), 1);
	y = 1;
	while (ft_newline(s) == 0 && y != 0)
	{
		y = read(fd, buffer, BUFFER_SIZE);
		if (y == -1)
			return (NULL);
		buffer[y] = '\0';
		s = ft_strjoin(s, buffer);
		if (!s)
			return (NULL);
	}
	return (s);
}

char	*get_line(int fd)
{
	static char		*s;
	char			*str;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	s = read_line(s, fd);
	if (!s)
		return (NULL);
	str = line(s);
	s = rest_of_str(s);
	return (str);
}
