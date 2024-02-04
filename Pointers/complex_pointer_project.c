#include <stdio.h>
#include <stdlib.h>

void allocate(double ***old, int height, int width){
    double **new = (double**) malloc(height * sizeof(double*));
    for (int y = 0; y < height; y++)
        new[y] = (double*) malloc(width * sizeof(double));
        
    *old = new;
}

int main()
{
    double **arr;
    int height = 4, width = 4;
    
    allocate(&arr, height, width);
    
    return 0;
}
