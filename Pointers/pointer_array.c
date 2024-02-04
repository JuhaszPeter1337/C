#include <stdio.h>

int main()
{
    int a = 5, b = 1, c = 8, d = 17;
    
    int *p[4];
    
    p[0] = &a, p[1] = &b, p[2] = &c, p[3] = &d;
    
    printf("Memory address of variable a: %p, Value of p[0]: %p\n", &a, p[0]);
    printf("Memory address of variable b: %p, Value of p[1]: %p\n", &b, p[1]);
    printf("Memory address of variable c: %p, Value of p[2]: %p\n", &c, p[2]);
    printf("Memory address of variable d: %p, Value of p[3]: %p\n", &d, p[3]);

    return 0;
}
