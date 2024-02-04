#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[10];
    numbers[0] = 5;
    
    printf("%p\n", numbers);
    
    int *p1 = numbers;
    p1[1] = 8;
    
    int **p2 = &p1;
    
    (*p2)[2] = 17;
    
    for (int i = 0; i < 10; i++)
        printf("%d\n", numbers[i]);
    
    return 0;
}
