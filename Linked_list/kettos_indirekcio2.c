#include <stdio.h>
#include <stdlib.h>

typedef struct ListaElem{
    int adat;
    struct ListaElem *kov;
} ListaElem;

void kiir(ListaElem **peleje){
    for (ListaElem *mozgo = *peleje; mozgo != NULL; mozgo=mozgo->kov)
        printf("%d ", mozgo->adat);
    printf("\n");
}

void vegere(ListaElem **peleje, int adat) {
    ListaElem **mozgo = peleje;        /* pointer megkeresése */
    while (*mozgo != NULL){
        mozgo = &(*mozgo)->kov;
    }
    
    ListaElem *uj = (ListaElem*) malloc(sizeof(ListaElem));
    uj->adat = adat;
    uj->kov = NULL;
    *mozgo = uj;           /* a megtalált NULL pointer felülírása */
}

int main()
{
    ListaElem *eleje = NULL;
    
    vegere(&eleje, 3);
    vegere(&eleje, 5);
    vegere(&eleje, 8);
    
    kiir(&eleje);

    return 0;
}
