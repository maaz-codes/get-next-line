#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *str = "\n123";
    char *ptr;

    ptr = malloc(sizeof(char) * strlen(str) + 1);

    strcpy(ptr, str);

    printf("StrCPY = %s\n", ptr);
}