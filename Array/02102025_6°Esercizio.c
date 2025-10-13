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

int* AumentaDim(int _n, int *_vettore){
        int nuovaDim=0;
        int *_Aumenta=NULL;
        do{
            printf("inserisci una nuova dimensione: ");
            scanf("%d", &nuovaDim);
            _Aumenta=(int*)realloc(_vettore, nuovaDim *sizeof(int));
            for(int i=_n; i<nuovaDim; i++){
                printf("inserisci nuovi valori: ");
                scanf("%d", &_Aumenta[i]);
            }

        }while(nuovaDim!=_n);
    return _Aumenta;
}
int main(){
    int *vettore = NULL;  //puntatore al vettore 
    int N;    
    int scelta=0;

    do{
        printf("inserisci la quantità degli elementi: ");
        scanf("%d", &N);
    }while(N<0);

    vettore = CreaVettore(N);
    vettore = InserisciValori(vettore, N);
    StampaVettore(vettore, N);

    printf("vuoi aumentare la dimensione? se vuoi aumentarla, inserisci 1 altrimenti 0: ");
    scanf("%d", &scelta);

    if(scelta==1){
        vettore = AumentaDim(N, vettore);
    }
    StampaVettore(vettore, N);

    free(vettore);
}