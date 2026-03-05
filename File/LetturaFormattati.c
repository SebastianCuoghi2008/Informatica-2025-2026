#include <stdio.h>

int main(){
    FILE *pFile = fopen("LF.txt", "r");
    char Nome[100];
    int Eta = 0;
    float Media = 0;

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return 1;
    }

    fscanf(pFile, "%s %d %f", Nome, &Eta, &Media);

    printf("Nome: %s Eta': %d  Media: %.2f", Nome, Eta, Media);

    fclose(pFile);
    return 0;
}