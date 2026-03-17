/*Scrivere una funzione che preso in ingresso il nome del file contenente interi,
lo modifichi in modo taleda contenere gli stessi numeri ma ordinati in senso decrescente*/

#include <stdio.h>
#include <stdlib.h>

void Ordina_file(char Nome_file[]){
    FILE *pFile;
    int Vettori[100];
    int i = 0;

    pFile = fopen(Nome_file, "r");

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return 1;
    }

    /*Lettura dei numeri dei file*/
    while(fscanf(pFile, "%d", &Vettori[i]) == 1){
        printf("Elemento %d: %d\n", i + 1, Vettori[i]);
        i++;
    }
    fclose(pFile);
}

int main(){
    char Nome[20];

    printf("Inserisci il nome del file: ");
    scanf("%s", Nome);

    Ordina_file(Nome);
}