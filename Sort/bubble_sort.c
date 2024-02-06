#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int *arr, int size){
    for (int i = size - 1; i > 0; i--){
        bool sorted = false;
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
                sorted = true;
            }
        }
        if (sorted == false)
            return;
    }
}

int main()
{
    int my_arr[] = {6, 4, 9, 1, 8, 2, 7, 5, 3};
    for (int i = 0; i < 9; i++)
        printf("%d ", my_arr[i]);
    printf("\n");
    bubble_sort(my_arr, 9);
    for (int i = 0; i < 9; i++)
        printf("%d ", my_arr[i]);

    return 0;
}
