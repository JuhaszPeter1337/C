#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct DinamicArray{
    double *arr;
    int length;
} DinamicArray;

bool allocate(DinamicArray *da, int length){
    da->arr = (double*) malloc(length * sizeof(double));
    da->length = length;
    if (da->arr == NULL)
        return false;
    return true;
}

void print(DinamicArray *da){
    for (int i = 0; i < da->length; i++){
        if (i == da->length - 1)
            printf("%f\n", da->arr[i]);
        else
            printf("%f, ", da->arr[i]);   
    }
}

bool reallocate_memory(DinamicArray *da, int new_size){
    double *new_arr = (double*) malloc(new_size * sizeof(double));
    if (new_arr == NULL)
        return false;
    int min = new_size < da->length ? new_size : da->length;
    for (int i = 0; i < min; i++)
        new_arr[i] = da->arr[i];
    free(da->arr);
    da->arr = new_arr;
    da->length = new_size;
    return true;
}

void free_memory(DinamicArray *da){
    free(da->arr);
}

int main()
{
    DinamicArray my_arr;
    bool trying = allocate(&my_arr, 100);
    if (trying == true)
        my_arr.arr[18] = 74.5;
        my_arr.arr[88] = 14;
        
    print(&my_arr);
    
    trying = reallocate_memory(&my_arr, 200);
    if (trying == true)
        printf("The memory reallocation was successful!");
        
    free_memory(&my_arr);
    
    return 0;
}
