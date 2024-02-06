#include <stdio.h>
#include <stdbool.h>

int findItem(int *arr, int size, int item){
    for (int i = 0; i < size; i++){
        if (arr[i] == item)
            return i;
    }
    return -1;
}

int *findItemWithPointer(int *arr, int size, int item){
    for (int i = 0; i < size; i++){
        if (arr[i] == item)
            return arr+i;
    }
    return NULL;
}

void Iterating(int *arr, int size){
    for (int *it = arr; it != arr+size; it++){
        printf("Memory address: %p, value: %d\n", it, *it);
    }
}

void *findItemWithIterating(int *arr, int size, int item){
    for (int *it = arr; it != arr+size; it++){
        if (*it == item)
            return it;
    }
    return NULL;
}

bool binarySearch(int *arr, int size, int item){
    int min = 0;
    int max = size - 1;
    int middle = (min + max) / 2;
    
    while(min <= max && arr[middle] != item){
        if (arr[middle] < item)
            min = middle + 1;
        else
            max = middle - 1;
        middle = (min + max) / 2;
    }
    return min <= max ? true : false;
}

int main()
{
    int my_arr[5] = {8, 4, 1, 5, 9};
    
    int where = findItem(my_arr, 5, 9);
    
    if (where != -1)
        printf("Place: %d, value: %d\n", where, my_arr[where]);
    else
        printf("The item was not found!\n");
        
    int *where2 = findItemWithPointer(my_arr, 5, 6);
    
    if (where2 != NULL)
        printf("%d", *where2);
    else
        printf("The item was not found!\n");
        
    Iterating(my_arr, 5);
    
    int *where3 = findItemWithIterating(my_arr, 5, 1);
    
    if (where3 != NULL)
        printf("The searched value: %d, the memory address of the item: %p\n", *where3, where3);
    else
        printf("The item was not found!\n");
        
    printf("The memory address of my_arr+2: %p, the value of *(my_arr+2): %d\n", my_arr+2, *(my_arr+2));
    
    int my_arr2[] = {11, 25, 33, 41, 56, 65, 78, 88, 95};
    
    bool contain = binarySearch(my_arr2, 9, 88);
    
    if (contain == false)
        printf("The array does not contain the item!\n");
    else
        printf("The array contains the item!\n");

    return 0;
}
