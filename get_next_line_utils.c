#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

char *ft_strchr(const char *s, int c)
{
    unsigned int i;

    i = 0;
    while (i <= ft_strlen(s))
    {
        if (s[i] == (unsigned char)c)
            return ((char *) s + i + 1);
        i++;
    }
    return (NULL);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;
    char *ptr1;
    char const *ptr2;

    if (!dst && !src)
        return (NULL);
    ptr1 = (char *)dst;
    ptr2 = (char *)src;
    i = 0;
    while (i < n)
    {
        ptr1[i] = ptr2[i];
        i++;
    }
    return (dst);
}