#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int ft_strlen(const char *str)
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

char *ft_strjoin(char const *s1, char const *s2)
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

int ft_word_count(const char *s, char sep)
{
    int i;
    int word;
    
    i = 0;
    word = 0;
    while (s[i]) 
    {
        if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			word++;
		i++;
    }
    return (word);
}

static char *ft_get_word(const char *s, int start, int end)
{
    char *word;
    int i;

    i = 0;
    word = (char *) malloc(sizeof(char) * ((end - start + 1) + 1));
	if (!word)
		return (NULL);
    // printf("Malloc of word = %d \n", ((end - start + 1) + 1));
    while (start <= end)
        word[i++] = s[start++];
	word[i] = '\0';
    return (word);
}

static char **get_array(const char *s, char c, int i, int j)
{
    char **ptr;
    int k;

    ptr = (char **) malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
    // printf("Malloc double array = %d \n", (ft_word_count(s, c) + 1));
    if (!ptr)
        return (NULL);
    k = 0;
    while (i <= ft_strlen(s))
    {
        j = i;
        while (s[i] && s[i] != c)
        {
            if (s[i + 1] == c || s[i + 1] == '\0')
                ptr[k++] = ft_get_word(s, j, i);
            i++;
        }
        if (s[i] == '\0')
            break;
        i++;
    }  
	ptr[k] = NULL; 
    return (ptr);
}

char **ft_split(const char *s, char c)
{
    char **ptr;

	if (!s)
		return (NULL);
    ptr = get_array(s, c, 0, 0);
    return (ptr);
}


static char *ft_strdup(const char *s1)
{
    char *ptr;
    int i;
    
    i = 0;
    ptr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (!ptr)
        return (NULL);
    while (s1[i] != '\0')
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

static char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substring;
    size_t i;

    if (!s || !len || start >= ft_strlen(s))
        return (ft_strdup(""));
    if (start + len > ft_strlen(s))
        substring = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
    else 
        substring = malloc(sizeof(char) * len + 1);
    if (!substring)
        return (NULL);
    i = 0;
    while (i < len && s[start] != '\0')
    {
        substring[i] = s[start];
        i++;
        start++;
    }
    substring[i] = '\0';
    return (substring);
}

char *ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = ft_strlen(s1) - 1;

	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j]))
		j--;
	if (i == ft_strlen(s1))
		return (NULL);
	str = ft_substr(s1, i, (j - i + 1));
	return (str);
}