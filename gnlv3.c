#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

#define BUFFER_SIZE 10

char *fetch_line(char *buff, int chars_read)
{
    int i;
    char *line;

    line = malloc(sizeof(char) * ft_strlen(buff) + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
    {
        line[i] = buff[i];
        i++;
    }
    line[i] = '\0'; 
    return (line);
}

int find_next_line2(char *buff, int chars_read)
{
    int i;

    i = 0;
    if (chars_read == 0)
        return (1);
    while (buff[i] != '\0')
    {
        if (buff[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE + 1u];
    char *line;
    int chars_read;
    int count;

    chars_read = -1;
    count = ft_strlen(buff);
    while (chars_read != 0)
    {
        if(find_next_line2(buff, chars_read))
        {
            line = fetch_line(buff, chars_read);
            memcpy(buff, ft_strchr(buff, '\n'), strlen(ft_strchr(buff, '\n')) + 1);
            return (line);
        }
        chars_read = read(fd, buff + count, BUFFER_SIZE);
        count += chars_read;
        buff[count] = '\0';
    }
    return (line);
}

int main(void)
{
    char **lines;
    int i;
    int fd;

    i = 0;
    fd = open("read.txt", O_RDONLY);
    printf("Line 1 = %s \n", get_next_line(fd));
    printf("Line 2 = %s \n", get_next_line(fd));
    printf("Line 3 = %s \n", get_next_line(fd));
    printf("Line 4 = %s \n", get_next_line(fd));
    printf("Line 5 = %s \n", get_next_line(fd));
    printf("Line 6 = %s \n", get_next_line(fd));
    // while (i < 1)
    // {
    //     lines[i] = get_next_line(fd);
    //     printf("Line %d = %s\n", (i + 1), lines[i]);
    //     i++;
    // }
}