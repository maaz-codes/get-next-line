#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>

char**	ft_split(const char *s, char c);
char*	ft_strchr(const char *s, int c);
char*	ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char*	ft_strtrim(char const *s1, char const *set);
int		ft_word_count(const char *s, char sep);

#endif