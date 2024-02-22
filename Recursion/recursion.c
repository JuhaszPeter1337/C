#include <stdio.h>

/*
Faktoriális lépések:
1. fakt(5) hívás: adjátok vissza az "n * fakt(4)" értéket
2. fakt(4) hívás: rendben de először adjátok vissza az "n * fakt(3)" értéket
3. fakt(3) hívás: rendben de először adjátok vissza az "n * fakt(2)" értéket
4. fakt(2) hívás: rendben de először adjátok vissza az "n * fakt(1)" értéket
5. fakt(1) hívás: visszaadja, hogy ő 1
6. Akkor tudjuk, hogy fakt(2) = 2 * fakt(1) = 2 * 1 = 2
7. Akkor tudjuk, hogy fakt(3) = 3 * fakt(2) = 3 * 2 = 6
8. Akkor tudjuk, hogy fakt(4) = 4 * fakt(3) = 4 * 6 = 24
9. Akkor tudjuk, hogy fakt(5) = 5 * fakt(4) = 5 * 24 = 120
10. Visszaadjuk, hogy az eredmény 120
*/
int fakt(int n) {
   if (n == 1)
      return 1;
   else{
      return n * fakt(n-1);
   }
}

/*
// FIB nagy betűvel: már ki van számolva
fib(5)
	fib(4) + fib(3)
		fib(3) + fib(2) + fib(3)
			fib(2) + fib(1) + fib(2) + fib(3)
				fib(1) + fib(0) + fib(1) + fib(2) + fib(3)
				    FIB(1) + FIB(0) + FIB(1) + fib(1) + fib(0) + fib(3)
				        FIB(1) + FIB(0) + FIB(1) + FIB(1) + FIB(0) + fib(2) + fib(1)
				            FIB(1) + FIB(0) + FIB(1) + FIB(1) + FIB(0) + fib(1) + fib(0) + fib(1)
				                FIB(1) + FIB(0) + FIB(1) + FIB(1) + FIB(0) + FIB(1) + FIB(0) + FIB(1)
									1 + 0 + 1 + 1 + 0 + 1 + 0 + 1 = 5
				
				

Lefutási sorrend:	
n:5 n:4 n:3 n:2 n:1 n:0 n:1 n:2 n:1 n:0 n:3 n:2 n:1 n:0 n:1 

fib(5) = fib(4) + fib(3) = 5
fib(4) = fib(3) + fib(2) = 3
fib(3) = fib(2) + fib(1) = 2
fib(2) = fib(1) + fib(0) = 1
fib(1) = 1
fib(0) = 0
*/
int fibonacci(int n){
    if (n < 2)
        return n;
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
        
}

int main()
{
    int value = fakt(5);
    printf("5! = %d\n", value);
    
    value = fibonacci(8);
    printf("Fibonacci 8 = %d\n", value);

    return 0;
}
