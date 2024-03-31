#include <stdio.h>
#include <string.h>

int main()
{
    char *nev = "Peter Shepherd";
    
    int hossz = strlen(nev);
    
    char tomb[hossz];
    
    int i = 0;
    while(nev[i]){
        tomb[i] = *(nev+i);
        i++;
    }
    tomb[i] = '\0';
    
    printf("%s", tomb);

    return 0;
}
