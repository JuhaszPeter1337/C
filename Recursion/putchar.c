#include <stdio.h>

void printout(char *string) {
   if (*string == '\0')
      return;
   putchar(*string);
   printout(string + 1);
}

int main()
{

    char *my_str = "Hello World!";
    printout(my_str);

    return 0;
}
