#include <stdio.h>

int increase_value(){
    static int number = 0;
    number++;
    return number;
}

int main()
{
    /* The program prints 1 2 because static variables are only initialized once and live till the end of the program. 
       That is why they can retain their value between multiple function calls.
       A static int variable remains in memory while the program is running. 
       A normal or auto variable is destroyed when a function call where the variable was declared is over.*/
    printf("Number value: %d\n", increase_value());
    printf("Number value: %d\n", increase_value());

    return 0;
}
