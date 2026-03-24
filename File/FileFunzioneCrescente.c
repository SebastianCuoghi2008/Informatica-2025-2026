/*Scrivere una funzione che preso in ingresso il nome del file contenente interi,
lo modifichi in modo taleda contenere gli stessi numeri ma ordinati in senso crescente*/

#include <stdio.h>
#include <stdlib.h>

void Ordina_file(char Nome_file[]){
    FILE *pFile;
    int Vettori[100];
    int N = 0;
    int tmp = 0;

    pFile = fopen(Nome_file, "r");

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        exit(1);
    }

    //Lettura dei numeri dei file:
    while(fscanf(pFile, "%d", &Vettori[N]) == 1){
        printf("Elemento %d: %d\n", N + 1, Vettori[N]);
        N++;
    }
    fclose(pFile);

    //Ordinamento del bubble sort:
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(Vettori[i] > Vettori[j]){
                tmp = Vettori[i];
                Vettori[i] = Vettori[j];
                Vettori[j] = tmp;
            }
        }
    }

    //Riapriamo il file per scriverci i numeri ordinati:
    pFile = fopen(Nome_file, "w");

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        exit(1);
    }

    for(int i = 0; i < N; i++){
        fprintf(pFile, "%d ", Vettori[i]);
    }
    fclose(pFile);
}

int main(){
    char Nome[20];

    printf("Inserisci il nome del file: ");
    scanf("%s", Nome);

    Ordina_file(Nome);
}