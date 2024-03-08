#include <stdio.h>
#include <stdlib.h>

typedef struct ListaElem{
    int adat;
    struct ListaElem *kov;
} ListaElem;

void elore_beszur(ListaElem **peleje, int adat){
    ListaElem *uj = (ListaElem*) malloc(sizeof(ListaElem));
    uj->adat = adat;
    uj->kov = *peleje;
    *peleje = uj;
}

void kiir(ListaElem **peleje){
    for (ListaElem *mozgo = *peleje; mozgo != NULL; mozgo=mozgo->kov)
        printf("%d ", mozgo->adat);
    printf("\n");
}

void vegere_beszur(ListaElem **peleje, int adat){
    ListaElem *uj = (ListaElem*) malloc(sizeof(ListaElem));
    uj->adat = adat;
    uj->kov = NULL;
    
    if (*peleje == NULL)
        *peleje = uj;
    else {
        ListaElem *mozgo = *peleje;
        while (mozgo->kov != NULL)
            mozgo = mozgo->kov;
        mozgo->kov = uj;
    }
}

void felszabadit(ListaElem **peleje){
    ListaElem *mozgo = *peleje;
    while (mozgo != NULL){
        ListaElem *temp = mozgo->kov;
        free(mozgo);
        mozgo = temp;
    }
}

int main()
{
    ListaElem *eleje = NULL;
    
    elore_beszur(&eleje, 5);
    elore_beszur(&eleje, 3);

    kiir(&eleje);

    printf("%d\n", eleje->adat);
    printf("%d\n", eleje->kov->adat);
    printf("%d\n", (*eleje).adat);
    printf("%d\n", (*eleje->kov).adat);
    
    vegere_beszur(&eleje, 8);
    kiir(&eleje);
    
    felszabadit(&eleje);
    kiir(&eleje);
    
    return 0;
}
