#include <stdio.h>

void novel(int *szam){
    (*szam)++;
}

int main()
{
    int x = 5;
    
    int *p = &x;
    
    novel(p);
    
    printf("%d", x);

    return 0;
}
