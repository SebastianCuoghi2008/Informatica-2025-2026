#include <stdio.h>

int main(){
    FILE *pFile = fopen("SF.txt", "w");

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return 1;
    }

    fprintf(pFile, "%s %d %.2f", "Martina", 12, 6.5);
    
    fclose(pFile);
    return 0;
}