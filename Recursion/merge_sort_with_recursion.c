#include <stdio.h>

/*
Function order with parameters:
sort(my_arr, 0, 8, my_helper);
	middle = 4;
	sort(my_arr, 0, 4, my_helper)
		middle = 2;
		sort(my_arr, 0, 2, my_helper)
			middle = 1;
			sort(my_arr, 0, 1, my_helper)
				return;
			sort(my_arr, 1, 2, my_helper)
				return;
			merge(my_arr, 0, 1, 2, my_helper);
			(my_helper: 1 7)
			copy(my_helper, 0, 2, my_arr);
		sort(my_arr, 2, 4, my_helper)
			middle = 3;
			sort(my_arr, 2, 3, my_helper);
				return;
			sort(my_arr, 3, 4, my_helper);
				return;
			merge(my_arr, 2, 3, 4, my_helper)
			(my_helper: 2 4)
			copy(my_helper, 2, 4, my_arr);
		merge(my_arr, 0, 2, 4, my_helper);
		copy(my_helper, 0, 4, my_arr);
	sort(my_arr, 4, 8, my_helper);
		middle = 6;
		sort(my_arr, 4, 6, my_helper);
			middle = 5;
			sort(my_arr, 4, 5, my_helper);
				return;
			sort(my_arr, 5, 6, my_helper);
				return;
			merge(my_arr, 4, 5, 6, my_helper);
			(my_helper: 3 5)
			copy(my_helper, 4, 6, my_arr);
		sort(my_arr, 6, 8);
			middle = 7;
			sort(my_arr, 6, 7, my_helper);
				return;
			sort(my_arr, 7, 8, my_helper);
				return;
			merge(my_arr, 6, 7, 8, my_helper);
			(my_helper: 6 8)
			copy(my_helper, 6, 8, my_arr);
		merge(my_arr, 4, 6, 8, my_helper);
		copy(my_helper, 4, 8, my_arr);
	merge(my_arr, 0, 4, 8, my_helper);
	copy(my_helper, 0, 8, my_arr);
*/

void merge(int *arr, int begin, int middle , int end, int *helper){
    int i = begin;
    int j = middle;
    for (int k = begin; k < end; k++){
        if (i < middle && (arr[i] < arr[j] || j >= end)){
            helper[k] = arr[i];
            i++;
        }
        else{
            helper[k] = arr[j];
            j++;
        }
    }
}

void copy(int *helper, int begin, int end, int *arr){
    int middle = (end + begin) / 2;
    for (int i = begin; i < end; i++)
        arr[i] = helper[i];
}

void sort(int *arr, int begin, int end, int *helper){
    if (end - begin < 2)
        return;
    int middle = (begin + end) / 2;
    sort(arr, begin, middle, helper);
    sort(arr, middle, end, helper);
    merge(arr, begin, middle, end, helper);
    copy(helper, begin, end, arr);
}

int main()
{
    int my_arr[8] = {1, 7, 4, 2, 5, 3, 8, 6};
    int my_helper[8];
    
    sort(my_arr, 0, 8, my_helper);
    
    for (int i = 0; i < 8; i++)
        printf("%d ", my_helper[i]);

    return 0;
}
