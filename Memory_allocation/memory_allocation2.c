#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_strings(char const *first, char const *second){
    int length = strlen(first) + strlen(second) + 1;
    
    char *arr = (char*) malloc(length * sizeof(char));
    
    if (arr == NULL)
        return NULL;
        
    strcpy(arr, first);
    strcat(arr, second);
    
    return arr;
}

int main()
{
    char *my_str = concat_strings("Hello, ", "my name is Peter!");
    
    printf("%s", my_str);
    
    free(my_str);

    return 0;
}
