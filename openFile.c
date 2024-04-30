#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// opening a file using open() [system call]

int main(void)
{
    int fd;

    fd = open("read.txt", O_RDONLY | O_CREAT | O_EXCL);
    printf("FD = %d \n", fd);
    if (close(fd) < 0)
        printf("File exist!");
    else 
        printf("File closed...");
}