#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Word{
    char hungarian[50];
    char english[50];
} Word;

typedef struct Dictionary{
    Word words[200];
    int quantity;
} Dictionary;

bool add(Dictionary *dict, Word word){
    if (dict->quantity == 200){
        printf("No empty space!\n");
        return false;
    }
    
    for (int i = 0; i < dict->quantity; i++){
        if (strcmp(dict->words[i].hungarian, word.hungarian) == 0 
            &&
            strcmp(dict->words[i].english, word.english) == 0
        ){
            printf("The words are already there!\n");
            return false;
        }
    }
    
    dict->words[dict->quantity] = word;
    dict->quantity++;
    return true;
}

bool save(Dictionary *dict, char *filename){
    FILE *f = fopen(filename, "w");    
    if (f == NULL){
        perror("The file cannot be opened!\n");
        return false;
    }
    for (int i = 0; i < dict->quantity; i++){
        fprintf("%s - %s", dict->words[i].hungarian, dict->words[i].english);
    }
    fclose(f)
    return true;
}

int main()
{
    Dictionary d;
    Word w = {"alma", "apple"};
    bool ret = add(&d, w);
    printf("%d\n", ret);
    bool ret2 = add(&d, (Word) {"auto", "car"});
    bool ret3 = add(&d, (Word) {"auto", "car"});
    bool ret4 = add(&d, (Word) {"kecske", "goat"});
    
    printf("%s, %s\n", d.words[0].hungarian, d.words[0].english);
    printf("%d", d.quantity);
    
    return 0;
}
