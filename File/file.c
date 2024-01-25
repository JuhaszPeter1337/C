#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data1 = 123;
    FILE *f = fopen("data.txt", "w");
    if (f == NULL) {
        perror("The file cannot be opened!\n");
        return; 
    }
    fprintf(f, "%d", data1);
    fclose(f);
        
    int data2;
    FILE *f = fopen("data.txt", "r");
    if (f == NULL) {
		perror("The file cannot be opened!\n");
        return;
    }
    fscanf(f, "%d", &data2);
    fclose(f);
	
	return 0;
}
