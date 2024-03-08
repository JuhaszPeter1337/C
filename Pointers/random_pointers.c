#include <stdio.h>

int main()
{
    int y = 10;
    int *py = &y;
    int **ppy = &py;
    
    printf("%p %p %p %p\n", ppy, &py , py, &y);
    printf("%p\n", *ppy);
    printf("%d\n", **ppy);
    
    int x = 5;
    *ppy = &x;
    printf("%d", **ppy);

    return 0;
}
