#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListaElem {
    char szo[50 + 1];
    struct ListaElem *kov;
} ListaElem;

ListaElem *elore_beszur(ListaElem *lista, char *mit){
    ListaElem *uj = (ListaElem*) malloc(sizeof(ListaElem));
    strcpy(uj->szo, mit);
    uj->kov = lista;
    return uj;
}

void print_lista(ListaElem *lista){
    for (ListaElem *mozgo = lista; mozgo != NULL; mozgo = mozgo->kov)
        printf("%s ", mozgo->szo);
    printf("\n");
}

int keres_listaban(ListaElem *lista, char *mit){
    for (ListaElem *mozgo = lista; mozgo != NULL; mozgo = mozgo->kov){
        if (strcmp(mozgo->szo, mit) == 0)
            return 1;
    }
    return 0;
}

int unique_szavak(ListaElem *lista){
    int mennyi = 0;
    if (lista == NULL)
        return mennyi;
    else{
        ListaElem *uj_lista = NULL;
        ListaElem *mozgo = lista;
        while (mozgo != NULL){
            if (keres_listaban(uj_lista, mozgo->szo) == 0){
                uj_lista = elore_beszur(uj_lista, mozgo->szo);
            }
            mozgo = mozgo->kov;
        }
        for (mozgo = uj_lista; mozgo != NULL; mozgo = mozgo->kov)
            mennyi++;
        return mennyi;
    }
}

int main()
{
    ListaElem *lista = NULL;
    
    lista = elore_beszur(lista, "Peter");
    lista = elore_beszur(lista, "Juhasz");
    lista = elore_beszur(lista, "Kecske");
    lista = elore_beszur(lista, "Alma");
    lista = elore_beszur(lista, "Peter");
    lista = elore_beszur(lista, "Peter");
    lista = elore_beszur(lista, "Juhasz");
    lista = elore_beszur(lista, "Sandor");
    
    print_lista(lista);
    
    int benne = keres_listaban(lista, "Alma");
    if (benne == 1)
        printf("Benne van\n");
    else
        printf("Nincs benne\n");
        
    int mennyi = unique_szavak(lista);
    printf("%d", mennyi);

    return 0;
}
