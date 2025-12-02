/*Creare una struct Squadra contenente le seguenti informazioni: nome, colore, punteggio.
caricato un massimo di 10 squadre stampare quelle con punteggio superiore a 100*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char colore[20];
    int punteggio;
}Squadra;

void Stampamento(Squadra *Teams, int N){
    for(int i=0; i<N; i++){
        printf("nome squadra: %s\n", Teams[i].nome);
        printf("colore squadra: %s\n", Teams[i].colore);
        printf("punteggio squadra: %d\n", Teams[i].punteggio);
    }
}

int main(){
    Squadra *Teams;
    int N;

    do{
        printf("inserisci il numero delle squadre(max 10): ");
        scanf("%d", &N);
    }while(N<0 || N>10);

    Teams=(Squadra*)malloc(N*sizeof(Squadra));
    if(Teams == NULL){
        printf("Errore durante l'allocazione");
        exit(1);
    }
    for(int i=0; i<N; i++){
        printf("inserisci il nome della squadra: ");
        scanf("%s", Teams[i].nome);
        fflush(stdin);
        printf("inserisci il colore della squadra: ");
        scanf("%s", Teams[i].colore);
        fflush(stdin);
        printf("inserisci il punteggio della squadra: ");
        scanf("%d", &Teams[i].punteggio);
        fflush(stdin);    
    }
    Stampamento(Teams, N);
}