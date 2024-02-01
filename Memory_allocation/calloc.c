#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 3;
    int *ptr;
    
    ptr = (int*) calloc(n, sizeof(int));
    
    ptr[2] = 5;
    
    for (int i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    
    free(ptr);
    
    return 0;
}
