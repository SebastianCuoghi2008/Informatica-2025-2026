/* Scrivere un linguaggio C che:
    1. Allochi un array iniziale di numeri;
    2. Inserimento dei valori;
    3. Stampa array;
    4. Calcoli la somma degli elementi multipli di 3;
    5. Creare un nuovo array contenente solo valori dispari;
*/

#include <stdio.h>
#include <stdlib.h>

int* CreaVettore(int _N){
    int *_vettore=NULL;

    _vettore=(int*)malloc(_N *sizeof(int));

    if(_vettore==NULL){
        printf("Errore di allocazione!\n");
        return NULL;
    }
    return _vettore;
}

int* InserisciValori(int *_vettore, int _N){

    for(int i=0; i<_N; i++){
        printf("inserisci l'elemento: ");
        scanf("%d", &_vettore[i]);
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

int CalcolaSomma(int *_vettore, int _N){
    int somma=0;
    
    for(int i=0; i<_N; i++){
        if(_vettore[i]%3==0){
            somma+=_vettore[i];
        }
    }
    return somma;
}

int *EstraDispari(int *_vettore, int _N, int *_DimDispari){
    int *_dispari=NULL;
    *_DimDispari=0;

    for(int i=0; i<_N; i++){
        if(_vettore[i]%2!=0){
            (*_DimDispari)++;
            int *temp = realloc(_dispari, (*_DimDispari)*sizeof(int));
        }
    }
}

int main(){
    int *vettore=NULL;  //puntatore al vettore
    int *dispari=NULL;
    int N, DimDispari;

    do{
        printf("inserisci la quantità degli elementi: ");
        scanf("%d", &N);
    }while(N<0);

    vettore = CreaVettore(N);
    vettore = InserisciValori(vettore, N);
    StampaVettore(vettore, N);

    printf("la somma degli elementi divisibili per 3 vale: %d\n", CalcolaSomma(vettore, N));
    //creiamo l'array contenente i valori dispari tramite la realloc 
    dispari= EstraDispari(int *_vettore, int _N, int *_DimDispari){

    }
}