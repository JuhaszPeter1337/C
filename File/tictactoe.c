#include <stdio.h>
#include <string.h>

typedef enum Babu{
    ures,
    kor,
    iksz
} Babu;

typedef struct Jatek {
    Babu palya[3][3];
    Babu kovetkezo;
    char kor_nev[100 + 1];
    char iksz_nev[100 + 1];
} Jatek;

typedef struct Pozicio {
    int x;
    int y;
} Pozicio;

void uj_jatek(Jatek *pj, char const *jatekos1, char const *jatekos2){
    /* A kör kezd. */
    pj->kovetkezo = kor;
    
    /* nevek */
    strcpy(pj->kor_nev, jatekos1);
    strcpy(pj->iksz_nev, jatekos2);
    
    /* üres pályán */
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            pj->palya[x][y] = ures;
}

void lepes(Jatek *pj, Babu babu, Pozicio p){
    if (babu != pj->kovetkezo)
        return;
    else{
        pj->palya[p.x][p.y] = babu;
        pj->kovetkezo = pj->kovetkezo == kor ? iksz : kor;
    }
}

void iras(Jatek *pj, char *hova){
    static const char elemek[] = {' ', 'O', 'X'};
    
    int number;
    if (strcmp(hova, "konzolra") == 0)
        number = 0;
    else if (strcmp(hova, "fajlba") == 0)
        number = 1;
    else
        number = -1;
    
    switch (number){
        case 0:
            printf("+-----+\n");
            for (int x = 0; x < 3; x++){
                printf("|");
                for (int y = 0; y < 3; y++){
                    printf("%c", elemek[pj->palya[x][y]]);
                    printf("|");
                }
                printf("\n");
            }
            printf("+-----+\n");
            break;
        case 1:
            FILE *fp = fopen("állás.txt", "w");
            if (fp == NULL){
                perror("A fájlt nem sikerült megnyitni!\n");
                return;
            }
        
            fprintf(fp, "Tictactoe v1\n");
            fprintf(fp, "%s\n", pj->kor_nev);
            fprintf(fp, "%s\n", pj->iksz_nev);
            
            fprintf(fp, "\n+-----+\n");
            for (int x = 0; x < 3; x++){
                fprintf(fp,"|");
                for (int y = 0; y < 3; y++){
                        fprintf(fp, "%c", elemek[pj->palya[x][y]]);
                        fprintf(fp, "|");
                    }
                fprintf(fp, "\n");
            }
            fprintf(fp, "+-----+");
            break;
        case -1:
            printf("\nA fájl második paramétere nem jól lett megadva!\n");
            printf("A lehetséges opciók: \"fajlba\" vagy \"konzolra\"!");
            break;
    }
}

int main()
{
    Jatek jatek;
    
    uj_jatek(&jatek, "Peter", "Bela");
    
    Babu babu = kor;
    Pozicio p;
    p.x = 0, p.y = 0;
    lepes(&jatek, babu, p);
    babu = iksz;
    p.x = 1, p.y = 1;
    lepes(&jatek, babu, p);
    p.x = 1, p.y = 2;
    lepes(&jatek, babu, p);
    
    iras(&jatek, "konzolra");
    iras(&jatek, "fajlba");
    iras(&jatek, "kecske");

    return 0;
}
