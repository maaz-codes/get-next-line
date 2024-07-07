/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:22:14 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/07 23:22:24 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *buff, int bytes, char *str)
{
	int	chars_read;

	chars_read = 1;
	while ((!ft_strchr(str, '\n')) && chars_read > 0)
	{
		chars_read = read(fd, buff, bytes);
		if (chars_read == -1)
		{
			free(buff);
			free(str);
			return (NULL);
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
	line = (char *)malloc(sizeof(char) * i);
	line = ft_substr(str, 0, i);
	return (line);
}

static char	*update(char *str)
{
	char	*ptr;

	ptr = ft_strdup(ft_strchr(str, '\n'));
	if (!ptr)
		return (NULL);
	return (ptr + 1);
}

char	*get_next_line(int fd)
{
	void		*buff;
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	str = reader(fd, buff, BUFFER_SIZE, str);
	line = fetch_line(str);
	str = update(str);
	return (line);
}

// int	main(void)
// {
//     int fd;
//     char *line;

//     fd = open("text.txt", O_RDONLY);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
//     line = get_next_line(fd);
//     printf("Line = %s\n", line);
// }
