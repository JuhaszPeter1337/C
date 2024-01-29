#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    double *arr;
    
    printf("How many numbers would you provide me? ");
    scanf("%d", &n);
    
    arr = (double*) malloc(n * sizeof(double));
    
    if (arr == NULL)
        printf("Memory allocation failed!\n");
        
    arr[4] = 12.4;
    
    printf("%.1f", arr[4]);
    
    free(arr);
    
    return 0;
}
