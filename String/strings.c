#include <stdio.h>

int main()
{
    char arr[] = "Juhasz Peter";
    
    int i, space;
    for (i = 0; arr[i] != ' '; i++)
        ;
    space = i;
        
    char reverse_arr[20];
    
    int start = 0;
    for (int i = space + 1; arr[i] != '\0'; i++){
        reverse_arr[start] = arr[i];
        start++;
    }
    
    reverse_arr[start] = ' ';
    start++;
    
    for(int i = 0; i < space; i++){
        reverse_arr[start] = arr[i];
        start++;
    }
    
    reverse_arr[start] = '\0';
    
    printf("%s", reverse_arr);
    
    return 0;
}
