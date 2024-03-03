#include <stdio.h>
#include <stdlib.h>

typedef struct Prim{
    int alap;
    int kitevo;
    struct Prim *kov;
} Prim;

void print_lista_hatvany(Prim *lista){
    for (Prim *mozgo = lista; mozgo != NULL; mozgo = mozgo->kov){
        printf("%d^%d ", mozgo->alap, mozgo->kitevo);
        if (mozgo->kov != NULL)
            printf("* ");
    }
    printf("\n");
}

Prim *felbontas(int szam){
    Prim *lista = NULL;
    int oszto = 2;
    int eredeti = szam;
    
    while(szam > 1){
        int kitevo = 0;
        while (szam % oszto == 0){
            szam = szam / oszto;
            kitevo++;
        }
        if (kitevo != 0){
            Prim *uj = (Prim*) malloc(sizeof(Prim));
            uj->alap = oszto;
            uj->kitevo = kitevo;
            uj->kov = NULL;
            if (lista == NULL)
                lista = uj;
            else{
                Prim *mozgo = lista;
                while(mozgo->kov != NULL)
                    mozgo = mozgo->kov;
                mozgo->kov = uj;
            }
        }
        oszto++;
    }
    print_lista_hatvany(lista);
    return lista;
}

Prim *legnagyobb_kozos_oszto(Prim *elso, Prim *masodik){
    Prim *kozos = NULL;
    Prim *mozgo1 = elso;
    while(mozgo1 != NULL){
        Prim *mozgo2 = masodik;
        while(mozgo2 != NULL){
            if (mozgo1->alap == mozgo2->alap){
                Prim *uj = (Prim*) malloc(sizeof(Prim));
                uj->alap = mozgo1->alap;
                uj->kitevo = mozgo1->kitevo < mozgo2->kitevo ? mozgo1->kitevo : mozgo2->kitevo;
                uj->kov = NULL;
                if (kozos == NULL)
                    kozos = uj;
                else{
                    Prim *mozgo = kozos;
                    while(mozgo->kov != NULL)
                        mozgo = mozgo->kov;
                    mozgo->kov = uj;
                }
            }
            mozgo2 = mozgo2->kov;
        }
        mozgo1 = mozgo1->kov;
    }
    print_lista_hatvany(kozos);
    return kozos;
}

void felszabadit_lista(Prim *lista){
    while (lista != NULL){
        Prim *kovetkezo = lista->kov;
        free(lista);
        lista = kovetkezo;
    }
}

int main()
{
    printf("60 primtenyezos felbontas: "); 
    Prim *lista = felbontas(60);
    printf("80 primtenyezos felbontas: "); 
    Prim *lista2 = felbontas(80);
    printf("60-80 legnagyobb kozos oszto: "); 
    Prim *kozos = legnagyobb_kozos_oszto(lista, lista2);
    
    felszabadit_lista(lista);
    felszabadit_lista(lista2);
    felszabadit_lista(kozos);
        
    return 0;
}
