#include <stdio.h>

# "*": dereferalo
# "&": referalo

# char is 1 bite
# int is 4 bites
# double is 8 bites

# First chapter

void change(int* pa, int* pb){
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}


int main()
{
    int* p;
    int a = 5;
    int b = 10;
    
    p = &a;
    
    printf("value of int a = %d\n", a);
    printf("address of p = %p, address of a using p = %p, address of a using a = %p\n", &p, p, &a);
    printf("address of int a = %p\n", &a);
    printf("value of int a = %d\n", *&a);
    printf("value of int a = %d\n", *&*&a);
    
    printf("value of pointer p = %d\n", *p);
    
    int* p2 = &b;
    
    printf("address of pointer p2 = %p\n", p2);
    
    change(&a, &b);
    
    printf("%d, %d", a, b);
    

    return 0;
}

# Second chapter

#include <stdio.h>

int main()
{
    int my_array[5] = {1, 2, 3, 4, 5};
    
    int a = 6;
    
    int *p1 = &my_array[0];
    int *p2 = my_array;
    int *p3 = &a;
    
    printf("%d\n", p1[1]);
    printf("%d\n", p2[3]);
    printf("%p\n", &p2[3]);
    printf("%p\n", &p2[4]);
    printf("%d\n", *p3);

    return 0;
}

# Third chapter

#include <stdio.h>

void print_using_array(int my_array[], int length){
    for (int i = 0; i != length; i++)
        printf("%d. = %d\n", i, my_array[i]);
}

void print_using_pointer(int *my_array, int length){
    for (int i = 0; i != length; i++)
        printf("%d. = %d\n", i, my_array[i]);
}

int main()
{
    int numbers[5] = {2, 5, 8, 1, 25};
    print_using_array(numbers, 5);
    printf("\n");
    print_using_pointer(numbers, 5);
    
    return 0;
}

# Fourth chapter

#include <stdio.h>

int* find(int* my_array, int length, int number){
    for (int i = 0; i < length; i++)
        if (my_array[i] == number)
            return &my_array[i];
    return NULL;
}

int main()
{
    int numbers[5] = {2, 5, 8, 1, 25};
    int* place = find(numbers, 5, 25);
    if (place != NULL)
        printf("Memory address: %p, value: %d", place, *place);
    else
        printf("%p", place);
    return 0;
}

# Fifth chapter

#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Memory address of the variable: %p\n", &a);
    printf("The given number: %d", a);
}
