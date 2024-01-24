#include <stdio.h>

int main()
{
    char *name = "Hi, my name is Peter Juhasz!";

    int i = 0;

    while (name[i] != '\0'){
	printf("%c", name[i]);
        i++;
    }

    return 0;
}
