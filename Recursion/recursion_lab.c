#include <stdio.h>

int fib(int number){
    if (number < 2)
        return number;
    return fib(number-1) + fib(number-2);
}

void print_string(char *text){
    if (text[0] == '\0')
        return;
    putchar(text[0]);
    printf("%s", text + 1);
}

void print_string2(char *text){
    if (text[0] == '\0')
        return;
    putchar(text[0]);
    print_string2(text + 1);
}

void print_array(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void print_array_backwards(int *arr, int size){
    for (int i = size - 1; i >= 0; i--)
        printf("%d ", arr[i]);
}

void print_array_recur(int *arr, int size){
    if (size > 0){
        printf("%d ", arr[0]);
        print_array_recur(arr + 1, size - 1);
    }
}

void print_array_backwards_recur(int *arr, int size){
    if (size > 0){
        printf("%d ", arr[size - 1]);
        print_array_backwards_recur(arr, size - 1);
    }
}

void changing(int number, int number_system){
    if (number / number_system > 0)
        changing(number / number_system, number_system);
    printf("%d", number % number_system);
}

void print_number_by_three(int number){
    if (number < 1000) {
        printf("%d", number);
        return;
    }
    
    print_number_by_three(number / 1000);
    printf(" %0.3d", number % 1000);
}

int main()
{
    print_string("alma");
    printf("\n");
    print_string2("alma");
    printf("\n");
    
    int my_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    print_array(my_arr, 10);
    printf("\n");
    print_array_backwards(my_arr, 10);
    printf("\n");
    print_array_recur(my_arr, 10);
    printf("\n");
    print_array_backwards_recur(my_arr, 10);
    printf("\n");
    changing(27, 5);
    printf("\n");
    print_number_by_three(16077216);

    return 0;
}
