#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    
    printf("How many numbers?\n");
    scanf("%d", &n);
    
    double *arr = (double*) malloc(n * sizeof(double));
    
    if (arr == NULL){
        printf("The memory allocation failed!");
        return 1;
    }
    
    printf("Give me these %d numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &arr[i]);
    
    printf("The numbers you provided backwards: ");
    for (int i = n; i > 0; i--)
        printf("%lf ", arr[i - 1]);
        
    free(arr);

    return 0;
}
