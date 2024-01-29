#include <stdio.h>

int main()
{
    int greater_number;
    int a = 4;
    int b = 8;
    greater_number = a > b ? a : b;
    printf("%d", greater_number);

    return 0;
}
