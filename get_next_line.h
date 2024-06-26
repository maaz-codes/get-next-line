#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42
# endif

#include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char*	ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void*	ft_memcpy(void *dst, const void *src, size_t n);
char*	get_next_line(int fd);

#endif