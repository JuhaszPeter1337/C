#include <stdio.h>
#include <stdlib.h>

typedef struct BinarisFa{
    int adat;
    struct BinarisFa *bal, *jobb;
} BinarisFa;


BinarisFa *beszur(BinarisFa *gyoker, int elem){
    if (gyoker == NULL){
        BinarisFa *uj = (BinarisFa*) malloc(sizeof(BinarisFa));
        uj->bal = NULL;
        uj->jobb = NULL;
        uj->adat = elem;
        return uj;
    }
    
    if (elem < gyoker->adat)
        gyoker->bal = beszur(gyoker->bal, elem);
    else if (elem > gyoker->adat)
        gyoker->jobb = beszur(gyoker->jobb, elem);
    else
        ;
        
    return gyoker;
}

BinarisFa *keres(BinarisFa *gyoker, int adat){
    BinarisFa *mozgo = gyoker;
    while (mozgo != NULL && adat != mozgo->adat){
        if (adat < mozgo->adat)
            mozgo = mozgo->bal;
        else
            mozgo = mozgo->jobb;
    }
    return mozgo;
}

void inorder_bejaras(BinarisFa *gyoker){
    if (gyoker == NULL)
        return;
        
    inorder_bejaras(gyoker->bal);
    printf("%d ", gyoker->adat);
    inorder_bejaras(gyoker->jobb);
}

void postorder_bejaras(BinarisFa *gyoker){
    if (gyoker == NULL)
        return;
        
    postorder_bejaras(gyoker->jobb);
    printf("%d ", gyoker->adat);
    postorder_bejaras(gyoker->bal);
}

void preorder_bejaras(BinarisFa *gyoker){
    if (gyoker == NULL)
        return;
        
    printf("%d ", gyoker->adat);
    preorder_bejaras(gyoker->bal);
    preorder_bejaras(gyoker->jobb);
}

void felszabadit_inorder(BinarisFa *gyoker){
    if (gyoker == NULL)
        return;
        
    felszabadit_inorder(gyoker->bal);
    felszabadit_inorder(gyoker->jobb);
    free(gyoker);
}

void felszabadit_postorder(BinarisFa *gyoker){
    if (gyoker == NULL)
        return;
        
    felszabadit_postorder(gyoker->jobb);
    felszabadit_postorder(gyoker->bal);
    free(gyoker);
}

void fajlba_ir_preorder(BinarisFa *gyoker, FILE *fajl){
    if (gyoker == NULL)
        return;
        
    fprintf(fajl, "%d ", gyoker->adat);
    fajlba_ir_preorder(gyoker->bal, fajl);
    fajlba_ir_preorder(gyoker->jobb, fajl);
}

int elemszam(BinarisFa *gyoker){
    if (gyoker == NULL)
        return 0;
        
    return elemszam(gyoker->bal) + elemszam(gyoker->jobb) + 1;
}

int levelszam(BinarisFa *gyoker){
    if (gyoker == NULL)
        return 0;
        
    if (gyoker->bal == NULL && gyoker->jobb == NULL)
        return 1;
        
    return levelszam(gyoker->bal) + levelszam(gyoker->jobb);
}

int szint_elemei(BinarisFa *gyoker, int szint){
    if (gyoker == NULL)
        return 0;
    if (szint == 0)
        return 1;
        
    return szint_elemei(gyoker->bal, szint-1) + szint_elemei(gyoker->jobb, szint-1);
}

int main()
{
    BinarisFa *gyoker = NULL;
    
    int tomb[] = {5, 3, 7, 1, 4, 0, 2, 6, 9, 8};
    
    for (int i = 0; i < 10; i++)
        gyoker = beszur(gyoker, tomb[i]);
    
    printf("Inorder bejaras: ");
    inorder_bejaras(gyoker);
    printf("\n");
    printf("Posztorder bejaras: ");
    postorder_bejaras(gyoker);
    printf("\n");
    printf("Preorder bejaras: ");
    preorder_bejaras(gyoker);
    printf("\n");
    
    BinarisFa *kereses = keres(gyoker, 5);
    printf("A megtalalt adat: %d\n", kereses->adat);
    
    int elemek = elemszam(gyoker);
    int levelek = levelszam(gyoker);
    int szinten_levo_elemek = szint_elemei(gyoker, 2);
    
    printf("Elemszam: %d\n", elemek);
    printf("Levelszam: %d\n", levelek);
    printf("2. szint elemei (0. szint az elso): %d\n", szinten_levo_elemek);
    
    felszabadit_postorder(gyoker);
    
    postorder_bejaras(gyoker);

    return 0;
}
