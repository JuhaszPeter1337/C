#include <stdio.h>

int main()
{
    const float PI = 3.14;
    
    printf("%0.2f", PI);
    
    // It returns with "error: assignment of read-only variable ‘PI’"
    PI = 4.14;

    return 0;
}
