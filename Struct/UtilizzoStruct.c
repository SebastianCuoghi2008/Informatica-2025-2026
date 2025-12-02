/*Esempio Struct, utilizzo di una struttura complessa facendo acesso ai campi in modalità variabile e in modalità puntatore alla struttura*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char cognome[20];
    int eta;
}Persona;


int main(){
    Persona P1;
    Persona *P2;

    //inseriamo le informazioni della prima persona (P1);
    printf("inserisci il nome della prima persona: ");
    scanf("%s", P1.nome);
    fflush(stdin);      //un modo per fare Clear Buffer
    printf("inserisci il cognome della prima persona: ");
    scanf("%s", P1.cognome);
    fflush(stdin);      //un modo per fare Clear Buffer
    printf("inserisci l'eta' della prima persona: ");
    scanf("%d", &P1.eta);
    fflush(stdin);      //un modo per fare Clear Buffer

    printf("I dati della prima persona %s %s %d anni\n", P1.nome, P1.cognome, P1.eta);

    //inseriamo le informazioni della seconda persona (P2);
    P2=malloc(sizeof(Persona));
    printf("inserisci il nome della seconda persona: ");
    scanf("%s", P2->nome);
    fflush(stdin);      //un modo per fare Clear Buffer
    printf("inserisci il cognome della seconda persona: ");
    scanf("%s", P2->cognome);
    fflush(stdin);      //un modo per fare Clear Buffer
    printf("inserisci l'eta' della seconda persona: ");
    scanf("%d", &P2->eta);
    fflush(stdin);      //un modo per fare Clear Buffer

    printf("I dati della prima persona %s %s %d anni", P2->nome, P2->cognome, P2->eta);

}