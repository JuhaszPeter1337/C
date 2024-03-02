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

int getLength(ListaElem *lista){
    int length = 0;
    if (lista == NULL)
        return 0;
    else{
        for (ListaElem *mozgo = lista; mozgo != NULL; mozgo = mozgo->kov)
            length++;
        return length;
    }
}

void freeList(ListaElem *lista){
    ListaElem *mozgo = lista;
    do {
        ListaElem *tmp = mozgo->kov;
        free(mozgo);
        mozgo = tmp;
    } while (mozgo != NULL);
}

ListaElem *lista_elejere_beszur(ListaElem *lista, int szam){
    ListaElem *u = (ListaElem*) malloc(sizeof(ListaElem));
    u->adat = szam;
    u->kov = lista;
    return u;
}

ListaElem *lista_vegere_beszur(ListaElem *lista, int szam){
    ListaElem *u = (ListaElem*) malloc(sizeof(ListaElem));
    u->adat = szam;
    u->kov = NULL;
    
    if (lista == NULL)
        return u;
    else{
        ListaElem *mozgo = lista;
        while (mozgo->kov != NULL)
            mozgo = mozgo->kov;
        mozgo->kov = u;
        return lista;
    }
}

ListaElem *keres(ListaElem *lista, int szam){
    ListaElem *mozgo = lista;
    while (mozgo != NULL){
        if (mozgo->adat != szam)
            mozgo = mozgo->kov;
        else
            return mozgo;
    }
    return NULL;
}

void printList(ListaElem *lista){
    for (ListaElem* mozgo = lista; mozgo != NULL; mozgo = mozgo->kov)
        printf("%d ", mozgo->adat);
}

int main()
{
    ListaElem *eleje;
    
    eleje = letrehoz();
    
    printList(eleje);
        
    int length = getLength(eleje);
    printf("\nLength: %d\n", length);
    
    freeList(eleje);
    
    ListaElem *masodik;
    
    masodik = lista_elejere_beszur(masodik, 13);
    masodik = lista_elejere_beszur(masodik, 21);
    masodik = lista_elejere_beszur(masodik, 48);
    
    masodik = lista_vegere_beszur(masodik, 53);
    masodik = lista_vegere_beszur(masodik, 88);
    
    printList(masodik);
    
    ListaElem *value = keres(masodik, 88);
    if (value == NULL)
        printf("\nAz adat nincs benne!");
    else
        printf("\nAdat: %d", value->adat);
        
    freeList(masodik);

    return 0;
}