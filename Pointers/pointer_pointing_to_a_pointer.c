#include <stdio.h>

int main()
{
    int a = 5;
    
    int *p1 = &a;
    *p1 = 8;
    printf("%d\n", *p1);
    
    int **p2 = &p1;
    **p2 = 18;
    printf("%d\n", **p2);
    
    printf("%d\n", a);
    printf("%p\n", p2);
    printf("%p\n", &p1);
    
    printf("Magic!!!\n");
    printf("%p\n", &a);
    printf("%p\n", *p2);
    printf("%p\n", &p1);
    printf("%p\n", p2);

    return 0;
}
