/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:22:14 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/08 21:19:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *buff, size_t bytes, char *str, int chars_read)
{
	while ((!ft_strchr(str, '\n')) && chars_read > 0)
	{
		chars_read = read(fd, buff, bytes);
		if (chars_read == -1)
		{
			if (buff)
				free(buff);
			if (str)
				free(str);
			return (NULL);
		}
		if (chars_read == 0)
		{
			if (!str)
				return (NULL);
			free(buff);
			return (str);
		}
		buff[chars_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

static char	*fetch_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;
	char		*line;
	int 		chars_read;
	// int			last;

	chars_read = 1;
	// last = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	str = reader(fd, buff, BUFFER_SIZE, str, chars_read);
	if (!str)
		return (NULL);
	line = fetch_line(str);
	str = ft_strchr(str, '\n') + 1;
	// if (last == 1)
		// free(str);
	return (line);
}

// int	main(void)
// {
//     int fd;
//     char *line;
// 	int i;

// 	i = 0;
//     fd = open("text.txt", O_RDONLY);
// 	while (i < 4)
// 	{
// 		line = get_next_line(fd);
// 		printf("Line = %s\n", line);
// 		i++;
// 	}
// }
