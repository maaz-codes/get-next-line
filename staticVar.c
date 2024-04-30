#include <stdio.h>

// int count; // global variable

int increment()
{
    static int count;

    count = count + 1;
    return (count);
}

int main(void)
{
    int a;

    a = increment();
    a = increment();
    a = increment();

    printf("a = %d \n", a);
}