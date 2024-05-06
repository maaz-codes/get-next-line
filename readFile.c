#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    static char buff[200];
    char *str;
    int buff_size = 5;
    int chars_read;

    fd = open("read.txt", O_RDONLY);
    str = "\0";
    int count = 0;

    while ((chars_read = read(fd, buff + count, buff_size)))
    {
        count += chars_read;
    }
    return (buff);
}

int main(void)
{
    int fd;
    char *str;

    fd = open("read.txt", O_RDONLY);
    str = "\0";

    str = get_next_line(fd);
    
    printf("Str = %s\n", str);
}