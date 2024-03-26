#include <stdio.h>

typedef enum Lampa{
    piros,
    piros_es_sarga,
    zold,
    sarga
} Lampa;

int main()
{
    Lampa lampa = piros_es_sarga;
    
    if (lampa == zold)
        printf("Mehet!");
    else if (lampa == piros_es_sarga)
        printf("Keszulj!");
    else if (lampa == piros)
        printf("Varakozz!");
    else
        printf("Állj meg!");

    return 0;
}
