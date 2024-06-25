#include "get_next_line.h"
#include <stdio.h>

static char *fetch_line(char *buff)
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

static int find_next_line(char *buff, int chars_read)
{
    int i;

    i = 0;
    if (chars_read == 0 || chars_read < BUFFER_SIZE)
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
    static int first_time_open = 1;
    char *line;
    // int chars_read;
    int count;
    char *updated_buff;
    static int i = 1;

    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
    count = ft_strlen(buff);
    int chars_read = BUFFER_SIZE;
    line = "\0";
    while (chars_read > 0 && first_time_open)
    {
        if (chars_read == BUFFER_SIZE)
            first_time_open = 1;
        else if (chars_read == 0)
            first_time_open = 0;
        printf(" - - Loop = %d - - \n", i++);
        // printf("CHR_RD = %d || Buff = %s \n", chars_read, buff);
        if(find_next_line(buff, chars_read))
        {
            line = fetch_line(buff);
            printf("LINE = %s \n", line);
            updated_buff = ft_strchr(buff, '\n');
            if (updated_buff == NULL)
                buff[0] = '\0';
            else
                ft_memcpy(buff, updated_buff, ft_strlen(updated_buff) + 1);
            return (line);
        }
        chars_read = read(fd, buff + count, BUFFER_SIZE);
        if (chars_read == 0 && first_time_open)
            return (NULL);
        if (chars_read == -1)
            return (NULL);
        count += chars_read;
        buff[count] = '\0';
        printf("NEW CHR_RD = %d || NEW Buff = %s \n", chars_read, buff);
    }
    return (NULL);
}

int main(void)
{
    char **lines;
    int i;
    int fd;
    int num_lines = 6;

    i = 0;
    fd = open("read.txt", O_RDONLY);
    lines = malloc(sizeof(char *) * num_lines);
    while (i < num_lines)
    {
        lines[i] = get_next_line(fd);
        printf("Line %d = %s\n", (i + 1), lines[i]);
        i++;
    }
}