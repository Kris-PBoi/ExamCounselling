#include<stdio.h>
int main()
{
    char *a = "abcd";
    char *b = "fghjk";
    char *c = "9867}{}";
    const char *whole_string = a, b, c;
    printf("%s\n", whole_string);
}