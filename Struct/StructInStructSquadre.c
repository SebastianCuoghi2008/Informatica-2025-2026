/*Visualizzare le squadre il cui allenatore presenta più di 10 titoli e un punteggio della squadra superiore a 30*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Squadra{
    char nome[20];
    char colore[20];
    int punteggio;
    struct Allenatore{
        char nomeAl[20];
        char cognomeAl[20];
        int titoli;
    }mister;
};

typedef struct Squadra Squadre;

void Stampamento_Squadre(Squadre *Teams, int N){
    for(int i=0; i<N; i++){
        printf("nome squadra: %s\n", Teams[i].nome);
        printf("colore squadra: %s\n", Teams[i].colore);
        printf("punteggio squadra: %d\n", Teams[i].punteggio);
        printf("nome allenatore: %s\n", Teams[i].mister.nomeAl);
        printf("cognome allenatore: %s\n", Teams[i].mister.cognomeAl);
        printf("numero titoli allenatore: %d\n", Teams[i].mister.titoli);
    }
}

int main(){
    Squadre *Teams;
    int N;

    do{
        printf("inserisci il numero delle squadre(max 10): ");
        scanf("%d", &N);
    }while(N<0 || N>10);

    Teams=(Squadre*)malloc(N*sizeof(Squadre));
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
        printf("inserisci il nome dell'allenatore: ");
        scanf("%s", Teams[i].mister.nomeAl);
        fflush(stdin);
        printf("inserisci il cognome dell'allenatore: ");
        scanf("%s", Teams[i].mister.cognomeAl);
        fflush(stdin);  
        printf("inserisci il numero di titoli dell'allenatore: ");
        scanf("%d", &Teams[i].mister.titoli);
        fflush(stdin);  
    }
}
    