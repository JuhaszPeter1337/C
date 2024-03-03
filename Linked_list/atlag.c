#include <stdio.h>
#include <stdlib.h>

typedef struct Szam{
    int szam;
    struct Szam *kov;
} Szam;

Szam *elejere_szur(Szam *lista, int szam){
    Szam *uj = (Szam*) malloc(sizeof(Szam));
    uj->szam = szam;
    uj->kov = lista;
    return uj;
}

void print_lista(Szam *lista, double atlag){
    printf("Atlagnal kissebb szamok: ");
    for (Szam *mozgo = lista; mozgo != NULL; mozgo = mozgo->kov){
        if(mozgo->szam < atlag)
            printf("%d ", mozgo->szam);   
    }
}

double atlag(Szam *lista){
    double osszeg = 0;
    int elemszam = 0;
    for (Szam *mozgo = lista; mozgo != NULL; mozgo = mozgo->kov){
        osszeg = osszeg + mozgo->szam;
        elemszam++;
    }
    // double/int okes
    return osszeg / elemszam;
}

void felszabadit(Szam *lista){
    while(lista != NULL){
        Szam *kov = lista->kov;
        free(lista);
        lista = kov;
    }
}

int main()
{
    Szam *lista = NULL;
    
    int szam;
    
    scanf("%d", &szam);
    while(szam != 0){
        lista = elejere_szur(lista, szam);
        scanf("%d", &szam);
    }
    
    double atl = atlag(lista);
    printf("Atlag: %lf\n", atl);
    print_lista(lista, atl);
    
    felszabadit(lista);

    return 0;
}
