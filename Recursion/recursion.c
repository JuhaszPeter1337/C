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
Fibonacci-sorozat lépések:
1. fib(5) hívás: fib(4) és fib(3) adja vissza az eredményét
2. fib(4) hívás: fib(3) és fib(2) adja vissza az eredményét
3. fib(3) hívás: fib(2) és fib(1) adja vissza az eredményét
4. fib(2) hívás: fib(1) és fib(0) adja vissza az eredményét
5. Rendben ezeket már tudjuk: fib(1) = 1 és fib(0) = 0, szóval fib(2) = 1 + 0 = 1
6. Akkor fib(3)-at is tudjuk: fib(2) = 1 és fib(1) = 1, szóval fib(3) = 1 + 1 = 2
7. Akkor fib(4)-et is tudjuk: fib(3) = 2 és fib(2) = 1, szóval fib(3) = 2 + 1 = 3
8. Akkor végül fib(5)-öt is tudjuk: fib(4) = 3 és fib(3) = 2, szóval fib(5) = 3 + 2 = 5
9. Visszaadjuk az 5-öt.

fib(5) = fib(4) + fib(3) = 5
fib(4) = fib(3) + fib(2) = 3
fib(3) = fib(2) + fib(1) = 2
fib(2) = fib(1) + fib(0) = 1
fib(1) = 1
fib(0) = 
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
