/*Scrivi un programma in C che:
    1. Chiede all'utente qunati numeri interi vuole inserire;
    2. Alloca dinamicamente un array di quella dimensione con malloc();
    3. Permette all'utente di inserire i numeri;
    4. Chiede all'utente se vuole aumentare la dimensione dell'array;
        -se sì richiede la nuova dimensione e usa realloc() per ridimensionarlo;
        -permette quindi di inserirei nuovi valori spazi aggiunti;
    5. Infine, stampa tutti gli elementi dell'array;
*/

#include <stdio.h>
#include <stdlib.h>

int* InserisciValori(int *_vettore, int _N){

    for(int i=0; i<_N; i++){
        printf("inserisci l'elemento: ");
        scanf("%d", &_vettore[i]);
    }
    return _vettore;
}

int* CreaVettore(int _N){
    int *_vettore=NULL;

    _vettore=(int*)malloc(_N *sizeof(int));

    if(_vettore==NULL){
        printf("Errore di allocazione!\n");
        return NULL;
    }
    return _vettore;
}

void StampaVettore(int *_vettore, int _N){
    
    printf("hai inserito i seguenti elementi: ");
    for(int i=0; i<_N; i++){
        printf("%d\t", _vettore[i]);
    }
    printf("\n");
}

int main(){
    int *vettore = NULL; 
    int *numeri = NULL;   // array dinamico
    int dimensione = 0;    // quanti elementi ci sono
    int scelta, N, i, j, trovato;

    do{
        scanf("%d", &scelta);

        if (scelta == 1){
            vettore = CreaVettore(N);
        }
        else if (scelta == 2){
            vettore = InserisciValori(vettore, N);
        }
        else if (scelta == 3){
            printf("Inserisci un numero: ");
            scanf("%d", &N);
            numeri =(int *)realloc(numeri, (dimensione + 1) * sizeof(int));
            if (numeri == NULL) {
                printf("Errore di allocazione!\n");
                return 1;
            }
            numeri[dimensione] = N;
            dimensione++;
            printf("Numero aggiunto!\n");
        }
        else if (scelta == 4){
            StampaVettore(vettore, N);
        }
    }while (scelta != 5);
}