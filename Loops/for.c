#include <stdio.h>

int main()
{
    char *name = "Hi, my name is Peter Juhasz!";

    for (int i = 0; name[i] != '\0'; i++){
	printf("%c", name[i]);
    }

    return 0;
}
