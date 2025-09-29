/*Creare un array dinamico chedendo all'utente la sua dumensione. Il programma deve avere le seguenti funzioni:
1. Crea l'array
2. Inserisci gli elementi nell'array
3. Stampa dei valori
4. Esci 
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

int main(){
    int *vettore=NULL;  //puntatore al vettore
    int N=0;

    do{
        printf("inserisci la quantità degli elementi: ");
        scanf("%d", &N);
    }while(N<0);

    vettore = CreaVettore(N);
    vettore = InserisciValori(vettore, N);
    StampaVettore(vettore, N);

    free(vettore);
}