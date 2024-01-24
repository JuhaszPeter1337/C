/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
