#include <stdio.h>
#include <stdlib.h>

void merge(int *arr1, int n1, int *arr2, int n2, int *arr3){
    int i = 0;
    int j = 0;
    for (int k = 0; k < n1 + n2; k ++){
        printf("i:%d, j:%d \n", i, j);
        if (i < n1 && arr1[i] < arr2[j] || j >= n2){
            arr3[k] = arr1[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
        }
    }
}

int main()
{
    int t1[] = {3, 6, 9, 10};
    int t2[] = {1, 4, 7, 8};
    
    int *t3 = (int*) malloc(8 * sizeof(int));
    
    merge(t1, 4, t2, 4, t3);
    
    for (int i = 0; i < 8; i++)
        printf("%d\n", t3[i]);

    return 0;
}
