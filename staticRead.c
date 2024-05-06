#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static int ft_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

static char *ft_strjoin(char const *s1, char const *s2)
{
    char *ptr;
    int total_len;
    int i;
    int j;

    total_len = ft_strlen(s1) + ft_strlen(s2);
    // printf("Malloc = %d\n", (total_len + 1));
    ptr = (char *)malloc(sizeof(char) * (total_len + 1));
    if (!ptr)
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        ptr[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        ptr[i] = s2[j];
        i++;
        j++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char *read_file(int fd)
{
    static char buff[100];
    static int count = 0;

    count += read(fd, buff + count, 5);
    printf("count = %d\n", count);
    printf("Buff = %s\n", buff);
    return (buff);
}

int main(void)
{
    int fd;
    char *str;

    fd = open("read.txt", O_RDONLY);
    str = read_file(fd);
    str = read_file(fd);
    printf("Str = %s \n", str);
}