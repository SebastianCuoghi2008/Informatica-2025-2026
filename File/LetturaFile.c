#include <stdio.h>

int main(){
    FILE *pFile = fopen("Input.txt", "r");
    char Riga[100];

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return 1;
    }

    while(fgets(Riga, sizeof(Riga), pFile) != NULL){
        printf("%s", Riga);
    }
    fclose(pFile);
    return 0;
}