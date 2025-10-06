/* Scrivi un programma in C che gestisca un insieme di numeri interi usando un array dinamico.
il programma deve permettere, tramite menù:
1. Aggiungere un numero (espandendo l'array con realloc, cioè una nuova dimensione)
2. Visualizzare tutti i numeri
3. Cercare un numero specifico
4. Ordinare i numeri in ordine crescente
5. Eliminare un numero scelto
6. uscire 
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