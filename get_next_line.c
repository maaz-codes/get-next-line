#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

#define BUFFER_SIZE 15

int find_next_line(char *buff, int count, int chars_read)
{
    int i;

    i = 0;
    while (i < count)
    {
        if (buff[i] == '\n')
            return (1);
        i++;
    }
    if (chars_read == 0)
    {
        return (1);
    }
    return (0);
}

char *get_next_line(int fd)
{
    static char buff[BUFFER_SIZE + 1u];
    int count;
    int chars_read;
    char **temp_split;
    char *line;
    int i = 1;

    // printf("Original Buff = %s\n", buff);
    count = ft_strlen(buff);
    chars_read = 0; 
    // printf("count = %d\n", count);

    while (chars_read != -1)
    {
        printf("Buff = %s\n", buff);
        if (find_next_line(buff, count, chars_read))
        {
            if (chars_read == 0) // EOF
                return (buff);
            line = ft_strchr(buff, '\n');
            printf("line = %s\n", line);
            temp_split = ft_split(buff, '\n');
            // printf("OLD Buff = %s\n", buff);
            printf("word_count = %d\n", ft_word_count(buff, '\n'));
            if (ft_word_count(buff, '\n') <= 1)
            {
                strcpy(buff, "\0");
            }
            else
                strcpy(buff, line);
            // memmove(buff, temp_split[1], ft_strlen(temp_split[1]));
            // free(temp);
            // free(temp_split);
            // printf("NEW Buff = %s\n", buff);
            break;
        }
        chars_read = read(fd, buff + count, BUFFER_SIZE);
        count += chars_read;
        buff[count] = '\0';
    }
    // printf("Charsread = %d\n", chars_read);
    return (temp_split[0]);
}

int main(void)
{
    int fd;
    char *line1;
    char *line2;
    char *line3;
    char *line4;
    char *line5;

    fd = open("read.txt", O_RDONLY);

    line1 = get_next_line(fd);
    printf("Line1 = %s\n", line1);
    printf("\n");

    line2 = get_next_line(fd);
    printf("Line2 = %s\n", line2);
    printf("\n");

    line3 = get_next_line(fd);
    printf("Line3 = %s\n", line3);
    printf("\n");

    line4 = get_next_line(fd);
    printf("Line4 = %s\n", line4);
    printf("\n");

    line5 = get_next_line(fd);
    printf("Line5 = %s\n", line5);
    printf("\n");
}