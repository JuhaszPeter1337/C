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
    printf("\n");
}

ListaElem *lista_megfordit(ListaElem *lista) {
    ListaElem *mozgo = lista;
    ListaElem *forditott = NULL;
    
    while (mozgo != NULL){
        ListaElem *atrak = mozgo;
        ListaElem *atrak_utani = mozgo->kov;
        atrak->kov = forditott;
        forditott = atrak;
        mozgo = atrak_utani;
    }
    return forditott;
}

ListaElem *torol_elem(ListaElem *lista, int szam){
    ListaElem *mozgo = lista;
    ListaElem *lemarado = NULL;
    
    if (lista == NULL)
        return NULL;
    while (mozgo != NULL){
        if (mozgo->adat > szam){
            ListaElem *torlendo = mozgo;
            mozgo = mozgo->kov;
            if (lemarado == NULL){
                // Változott a lista elejére mutató pointer
                lista = mozgo;
            }
            else{
                lemarado->kov = mozgo;
            }
            free(torlendo);
        }
        else{
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
    }
    // Ez csak azért kell, hogy pontosan tudjuk, hol van a memóriában a lista eleje
    return lista;
}

void madarnyelv(ListaElem *lista, int szam){
    ListaElem *mozgo = lista;
    
    while (mozgo != NULL){
        if (mozgo->adat == szam){
            ListaElem *uj_0 = (ListaElem*) malloc(sizeof(ListaElem));
            ListaElem *uj_szam = (ListaElem*) malloc(sizeof(ListaElem));
            uj_0->adat = 0;
            uj_szam->adat = szam;
            uj_szam->kov = mozgo->kov;
            uj_0->kov = uj_szam;
            mozgo->kov = uj_0;
            mozgo = mozgo->kov->kov->kov;
        }
        else
            mozgo = mozgo->kov;
    }
}

int main()
{
    ListaElem *eleje;
    
    eleje = letrehoz();
    
    printList(eleje);
        
    int length = getLength(eleje);
    printf("Length: %d\n", length);
    
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
        printf("Az adat nincs benne!");
    else
        printf("Adat: %d\n", value->adat);
    
    ListaElem *harmadik = lista_megfordit(masodik);

    printList(harmadik);
    
    ListaElem *negyedik = torol_elem(harmadik, 25);
    printList(negyedik);
    
    ListaElem *otodik;
    
    otodik = lista_elejere_beszur(otodik, 13);
    otodik = lista_elejere_beszur(otodik, 21);
    otodik = lista_elejere_beszur(otodik, 48);
    
    otodik = lista_vegere_beszur(otodik, 53);
    otodik = lista_vegere_beszur(otodik, 88);
    otodik = lista_vegere_beszur(otodik, 13);
    
    printList(otodik);
    
    madarnyelv(otodik, 13);
    printList(otodik);

    return 0;
}