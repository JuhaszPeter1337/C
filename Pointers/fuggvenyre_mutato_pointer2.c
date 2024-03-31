#include <stdio.h>
#include <ctype.h>
#include <string.h>

int osszead(int a, int b){
    return a + b;
}

int szoroz(int a, int b){
    return a * b;
}

int hatvanyoz(int a, int b){
    int eredmeny = 1;
    
    for (int i = 0; i < b; i++)
        eredmeny *= a;
        
    return eredmeny;
}

typedef int (*MatFvPtr)(int, int);

typedef struct MenuPont{
    char *nev;
    MatFvPtr f;
} MenuPont;
 
int main(void) {
    MenuPont menupontok[] = {
        {"Osszeadas", osszead},
        {"Szorzas", szoroz},
        {"Hatvanyozas", hatvanyoz},
        {NULL, NULL}
    };
    
    printf("Menupontok:\n");
    int i;
    for (i = 1; menupontok[i-1].nev != NULL; i++)
        printf("%d. %s\n", i, menupontok[i-1].nev);
    int meret = i-1; 
    
    int szam;
    printf("Adja meg a kivant szamot! ");
    scanf("%d", &szam);
    
    if (szam > meret || szam < 1)
        printf("A megadott szam (%d) nem megfelelo! Nincs ilyen menupont!", szam);
    else{
        int param1, param2;
        printf("Adja meg az elso parametert! ");
        scanf("%d", &param1);
        printf("Adja meg a masodik parametert! ");
        scanf("%d", &param2);
        MatFvPtr fuggveny = menupontok[szam-1].f;
        
        char lower[strlen(menupontok[szam-1].nev) + 1];
        int i = 0;
        while(menupontok[szam-1].nev[i]){
            lower[i] = tolower(*(menupontok[szam-1].nev+i));
            i++;
        }
        lower[i] = '\0';
        
        printf("A kiszamolt ertek (%s muveletet) hasznalva: %d", lower, fuggveny(param1, param2));
    }
    
    return 0;
}