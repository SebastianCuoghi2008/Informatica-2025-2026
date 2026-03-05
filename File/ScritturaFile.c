#include <stdio.h>

int main(){
    FILE *pFile = fopen("Output.txt", "w");

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return 1;
    }

    fprintf(pFile, "Ciao bella!\n");
    fprintf(pFile, "Il numero: %d \n", 10);
    
    fclose(pFile);
    return 0;
}