#include <stdio.h>
#include <stdbool.h>

void selection_sort(int *arr, int size){
    for (int i = 0; i < size - 1; i++){
        int minindex = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        
        if (minindex != i){
            int temp = arr[minindex];
            arr[minindex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int my_arr[] = {6, 4, 9, 1, 8, 2, 7, 5, 3};
    for (int i = 0; i < 9; i++)
        printf("%d ", my_arr[i]);
    printf("\n");
    selection_sort(my_arr, 9);
    for (int i = 0; i < 9; i++)
        printf("%d ", my_arr[i]);

    return 0;
}
