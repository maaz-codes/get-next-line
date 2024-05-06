#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char c[3];

    fd = open("read.txt", O_RDONLY, 0);
    printf("FD = %d \n", fd);
    read(fd, &c, 1);
    printf("First char of File = %s \n", c);
}