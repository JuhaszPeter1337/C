#include <stdio.h>

typedef enum Lampa{
    piros,
    piros_es_sarga,
    zold,
    sarga
} Lampa;

typedef enum Irany{
    eszak,
    del,
    kelet,
    nyugat
} Irany;

typedef enum Osztaly{
    a = 25,
    b = 50,
    c = 75,
    d = 100
} Osztaly;

int main()
{
    Lampa lampa = piros_es_sarga;
    
    switch (lampa){
        case zold:
            printf("Mehet!");
            break;
        case piros_es_sarga:
            printf("Keszulj!");
            break;
        case piros:
            printf("Varakozz!");
            break;
        case sarga:
            printf("Állj meg!");
            break;
    }
    
    Irany irany = 3;
    if (irany == nyugat)
        printf("\nAz irany nyugat!");

    Osztaly osztaly = 75;
    if (osztaly == c)
        printf("\nC osztaly!");

    return 0;
}
