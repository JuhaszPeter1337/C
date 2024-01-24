#include <stdio.h>

int main()
{
    char *name = "Hi, my name is Peter Juhasz!";

    int i = 0;

    do {
        printf("%c", name[i]);
        i++;
    } while (name[i] != '\0');

    return 0;
}
