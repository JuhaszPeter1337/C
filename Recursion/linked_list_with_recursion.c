#include <stdio.h>
#include <stdlib.h>

typedef struct ListaElem{
    int adat;
    struct ListaElem *kov;
} ListaElem;

ListaElem *letrehoz(void){
    int szamok[] = {8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1};
                     
    ListaElem *lista = NULL;
    
    int i = 0;
    do {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->adat = szamok[i];
        u->kov = lista;
        lista = u;
        i++;
    } while(szamok[i] != -1);
    
    return lista;
}

void printlist(ListaElem *eleje){
    if (eleje == NULL)
        return;
        
    printf("%d ", eleje->adat);
    printlist(eleje->kov);
}

int main()
{
    ListaElem *eleje;
    
    eleje = letrehoz();
    
    printlist(eleje);

    return 0;
}
