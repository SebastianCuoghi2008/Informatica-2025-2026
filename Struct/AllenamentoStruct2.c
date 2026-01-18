#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Utente{
    char Nome[30];
    char Cognome[30];
    struct Abbonamento{
        int Giorni_rimanenti;
        int Livello;
    }Abbonamento;
};

int main(){
    int N = 3;
    struct Utente *Utenti;

    //Allocazione dei dati:

    Utenti = (struct Utente*)malloc(N * sizeof(struct Utente));

    if(Utenti == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    //Inserimento dei dati:

    strcpy(Utenti[0].Nome, "Alessandro");
    strcpy(Utenti[0].Cognome, "Mazzacani");

    strcpy(Utenti[1].Nome, "Sebastian");
    strcpy(Utenti[1].Cognome, "Cuoghi");

    strcpy(Utenti[2].Nome, "Leonardo");
    strcpy(Utenti[2].Cognome, "Cuoghi");

    //Inserimento dati (Giorni_rimanenti e Livello), struct nella struct:

    Utenti[0].Abbonamento.Giorni_rimanenti = 30;
    Utenti[0].Abbonamento.Livello = 1;

    Utenti[1].Abbonamento.Giorni_rimanenti = 90;
    Utenti[1].Abbonamento.Livello = 2;

    Utenti[2].Abbonamento.Giorni_rimanenti = 0;
    Utenti[2].Abbonamento.Livello = 3;

    //Visualizzaione dei dati:
    printf("\n===Lista utenti===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Utente %d: \n", i + 1);
        printf("Nome: %s \n", Utenti[i].Nome);
        printf("Cognome: %s \n", Utenti[i].Cognome);
        printf("Giorni rimanenti: %d \n", Utenti[i].Abbonamento.Giorni_rimanenti);
        printf("Livello: %d \n\n", Utenti[i].Abbonamento.Livello);
    }

    //ELeminazione degli abbonamenti scaduti:
    for(int i = 0; i < N; i ++){
        if(Utenti[i].Abbonamento.Giorni_rimanenti == 0){
            printf("Questo abbonamento è scaduto %d\n", i);
            for(int j = i; j < N -1; j++){
                strcpy(Utenti[j].Nome, Utenti[j + 1].Nome);
                strcpy(Utenti[j].Cognome, Utenti[j + 1].Cognome);
                Utenti[j].Abbonamento.Giorni_rimanenti = Utenti[j + 1].Abbonamento.Giorni_rimanenti;
                Utenti[j].Abbonamento.Livello = Utenti[j + 1].Abbonamento.Livello;
            }
            N -= 1;
        }
    }

    //Realloc per ristampare i dati:
    Utenti = (struct Utente*)realloc(Utenti, N * sizeof(struct Utente));

    if(Utenti == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    //Visualizzaione dei dati aggiornati:
    printf("\n===Lista utenti===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Utente %d: \n", i + 1);
        printf("Nome: %s \n", Utenti[i].Nome);
        printf("Cognome: %s \n", Utenti[i].Cognome);
        printf("Giorni rimanenti: %d \n", Utenti[i].Abbonamento.Giorni_rimanenti);
        printf("Livello: %d \n\n", Utenti[i].Abbonamento.Livello);
    }
    free(Utenti);
}