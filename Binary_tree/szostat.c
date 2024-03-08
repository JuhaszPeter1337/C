#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SzoStat{
    char szo[50+1];
    int db;
    struct SzoStat *bal, *jobb;
} SzoStat;

SzoStat *beszur(SzoStat *fa, char *szo){
    if (fa == NULL){
        SzoStat *uj = (SzoStat*) malloc(sizeof(SzoStat));
        strcpy(uj->szo, szo);
        uj->db = 1;
        uj->bal = NULL;
        uj->jobb = NULL;
        return uj;
    }
    int ertek = strcmp(szo, fa->szo);
    if (ertek < 0)
        fa->bal = beszur(fa->bal, szo);
    else if (ertek > 0)
        fa->jobb = beszur(fa->jobb, szo);
    else
        fa->db++;
    return fa;
}

void kiir_fa(SzoStat *fa){
    if (fa == NULL)
        return;
        
    kiir_fa(fa->bal);
    printf("%s : %d\n", fa->szo, fa->db);
    kiir_fa(fa->jobb);
}

void felszabadit_fa(SzoStat *fa){
    if (fa == NULL)
        return;
    felszabadit_fa(fa->bal);
    felszabadit_fa(fa->jobb);
    free(fa);
}

int main()
{
    SzoStat *fa = NULL;
    char szo[50+1];
    
    while(scanf("%s", szo) == 1)
        fa = beszur(fa, szo);
    
    printf("Szolista:\n");
    kiir_fa(fa);
    
    felszabadit_fa(fa);

    return 0;
}
