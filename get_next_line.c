#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int fd;
    static char buff[100];
    int chars_read;

    fd = open("read.txt", O_RDONLY, 0);

    int i = 0;
    buff[i] = 'a';
    while (buff[i] != '!')
    {
        read(fd, &buff[i], 1);
        printf("buff = %c \n", buff[i]);
        i++;
    }

}