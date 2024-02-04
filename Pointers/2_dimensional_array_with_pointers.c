#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **numbers;
    
    int height = 4, width = 4;
    
    numbers = (int**) malloc(height * sizeof(int*));
    
    for (int j = 0; j < width; j++)
        numbers[j] = (int*) malloc(width * sizeof(int));
    
    // However, the values in the allocated memory are not initialized, so the content of the numbers array is indeterminate.
    // The output will be unpredictable. To ensure that the elements are initialized to zero, initialize the array explicitly.
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            numbers[i][j] = 0;
        
    numbers[1][2] = 15;
    numbers[0][0] = 34;
    numbers[2][1] = 7;
    numbers[3][3] = 88;
    
    printf("%p\n", numbers);
    printf("%p\n", numbers[0]);
    printf("%p\n", numbers[1]);
    printf("%p\n", numbers[2]);
    printf("%p\n", numbers[3]);
    printf("%p\n", numbers[4]);
    printf("%d\n", numbers[1][1]);
    
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            printf("%d ", numbers[i][j]);
            
    for (int j = 0; j < width; j++)
        free(numbers[j]);
    free(numbers);
    
    return 0;
}
