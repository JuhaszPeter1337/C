#include <stdio.h>

double negyzet(double a){
    return a * a; 
}

double kob(double a){
    return a * a * a;
}

double szorzat(double a, double b){
    return a * b;
}
 
int main(void) {
    /* 
    Függvényre mutató pointer típusú változó:
    VisszatérésiTípus (*változónév)(ParaméterTípus1, ...);
    */ 
    
    double (*fptr)(double);
    
    fptr = negyzet;
    printf("%1.0f\n", fptr(5));
    
    fptr = kob;
    printf("%1.0f\n", fptr(5));
    
    double (*fptr2)(double, double);
    fptr2 = szorzat;
    printf("%1.0f", fptr2(5, 10));
    
    return 0;   
}