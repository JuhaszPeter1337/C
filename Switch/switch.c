#include <stdio.h>
 
int main(void) {
    int c = 2;
    
    switch (c){
        case 0:
            printf("The number is zero!");
            break;
        case 1:
            printf("The number is one!");
            break;
        default:
            printf("The number is neither 0 nor 1!");
            break;
    }
    
    return 0;   
}