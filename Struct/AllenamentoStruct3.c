/*Creare una struct Casa con:
- costo bollette
- struct proprietario (con nome e cognome)
- struct indirizzo (con via e numero civico)

Creare un array di 4 case:
Alessandro Mazzacani, via Garibaldi 12, 700€
Sebastian Cuoghi, via Borsellino 44, 900€
Andrea Roncaglia, via Terni 3, 500€
Samuele Lotti, via Alberi 90, 1200€

Stampare a schermo il nome del proprietario con le bollette più costose, e quello con le bollette meno costose.

Eliminare dall'array tutte le case con più di 800 euro di bollette

Aggiungere una casa all'array, facendo inserire i dati all'utente.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char* Stringa;

struct Casa{
    int Costo_bollette;
    struct Proprietario{
        char Nome[30];
        char Cognome[30];
        struct Indirizzo{
            char Via[50];
            int Numero_civico;
        }Indirizzo;
    }Proprietario;
};

int main(){
    int N = 4;
    struct Casa *Case;
    float Costoso;
    int I_Costoso;

    //Allocazione dei dati:
    Case = (struct Casa*)malloc(N * sizeof(struct Casa));

    if(Case == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    //Inserimento dei dati:
    strcpy(Case[0].Proprietario.Nome, "Alessandro");
    strcpy(Case[0].Proprietario.Cognome, "Mazzacani");
    strcpy(Case[0].Proprietario.Indirizzo.Via, "via Garibaldi");
    Case[0].Proprietario.Indirizzo.Numero_civico = 12;
    Case[0].Costo_bollette = 700;

    strcpy(Case[1].Proprietario.Nome, "Sebastian");
    strcpy(Case[1].Proprietario.Cognome, "Cuoghi");
    strcpy(Case[1].Proprietario.Indirizzo.Via, "via Borsellino");
    Case[1].Proprietario.Indirizzo.Numero_civico = 44;
    Case[1].Costo_bollette = 900;       

    strcpy(Case[2].Proprietario.Nome, "Andrea");
    strcpy(Case[2].Proprietario.Cognome, "Roncaglia");
    strcpy(Case[2].Proprietario.Indirizzo.Via, "via Terni");
    Case[2].Proprietario.Indirizzo.Numero_civico = 3;
    Case[2].Costo_bollette = 500;

    strcpy(Case[3].Proprietario.Nome, "Samuele");
    strcpy(Case[3].Proprietario.Cognome, "Lotti");
    strcpy(Case[3].Proprietario.Indirizzo.Via, "via Alberi");
    Case[3].Proprietario.Indirizzo.Numero_civico = 90;
    Case[3].Costo_bollette = 1200;

    //Visualizzaione dei dati:
    printf("\n===Lista Case===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Casa %d: \n", i + 1);
        printf("Nome: %s \n", Case[i].Proprietario.Nome);
        printf("Cognome: %s \n", Case[i].Proprietario.Cognome);
        printf("Via: %s \n", Case[i].Proprietario.Indirizzo.Via);
        printf("Livello: %d \n", Case[i].Proprietario.Indirizzo.Numero_civico);
        printf("Livello: %d \n\n", Case[i].Costo_bollette);
    }

    //Ricerca della casa con più bollette:
    Costoso = Case[0].Costo_bollette;
    I_Costoso = 0;
    
    for(int i = 1; i < N; i ++){
        if(Case[i].Costo_bollette > Costoso){
            Costoso = Case[i].Costo_bollette;
            I_Costoso = i;
        }
    }
    printf("La via con la casa con più bollette e': %s\n", Case[I_Costoso].Proprietario.Indirizzo.Via);

    for(int i = 1; i < N; i ++){
        if(Case[i].Costo_bollette < Costoso){
            Costoso = Case[i].Costo_bollette;
            I_Costoso = i;
        }
    }
    printf("La via con la casa con meno bollette e': %s\n", Case[I_Costoso].Proprietario.Indirizzo.Via);

    //ELeminazione della case con le bollete maggiore di 800€:
    for(int i = 0; i < N; i ++){
        if(Case[i].Costo_bollette > 800){
            printf("Questa casa ha un costo di bollette troppo alto: %d\n", i);
            for(int j = i; j < N -1; j++){
                strcpy(Case[j].Proprietario.Nome, Case[j + 1].Proprietario.Nome);
                strcpy(Case[j].Proprietario.Cognome, Case[j + 1].Proprietario.Cognome);
                strcpy(Case[j].Proprietario.Indirizzo.Via, Case[j + 1].Proprietario.Indirizzo.Via);
                Case[j].Proprietario.Indirizzo.Numero_civico, Case[j + 1].Proprietario.Indirizzo.Numero_civico;
                Case[j].Costo_bollette, Case[j + 1].Costo_bollette;
            }
            N -= 1;
        }
    }

    //Realloc per ristampare i dati:
    Case = (struct Casa*)realloc(Case, N * sizeof(struct Casa));

    if(Case == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    //Visualizzaione dei dati aggiornati:
    printf("\n===Lista Case===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Casa %d: \n", i + 1);
        printf("Nome: %s \n", Case[i].Proprietario.Nome);
        printf("Cognome: %s \n", Case[i].Proprietario.Cognome);
        printf("Via: %s \n", Case[i].Proprietario.Indirizzo.Via);
        printf("Livello: %d \n", Case[i].Proprietario.Indirizzo.Numero_civico);
        printf("Livello: %d \n\n", Case[i].Costo_bollette);
    }

    //Realloc per ristampare i dati:
    N += 1;

    Case = (struct Casa*)realloc(Case, N * sizeof(struct Casa));

    if(Case == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    //inserimento dato utente casa dinamica:
    printf("Inserisci il nome del proprietario: ");
    fgets(Case[N-1].Proprietario.Nome, 30, stdin);
    printf("Inserisci il cognome del proprietario: ");
    fgets(Case[N-1].Proprietario.Cognome, 30, stdin);
    printf("Inserisci la via della casa: ");
    fgets(Case[N-1].Proprietario.Indirizzo.Via, 50, stdin);
    printf("Inserisci il numero civico della casa: ");
    scanf("%d", &Case[N-1].Proprietario.Indirizzo.Numero_civico);
    printf("Inserisci il costo delle bollette: ");
    scanf("%d", &Case[N-1].Costo_bollette);

    //Visualizzaione dei dati aggiornati:
    printf("\n===Lista Case===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Casa %d: \n", i + 1);
        printf("Nome: %s \n", Case[i].Proprietario.Nome);
        printf("Cognome: %s \n", Case[i].Proprietario.Cognome);
        printf("Via: %s \n", Case[i].Proprietario.Indirizzo.Via);
        printf("Livello: %d \n", Case[i].Proprietario.Indirizzo.Numero_civico);
        printf("Livello: %d \n\n", Case[i].Costo_bollette);
    }
    free(Case);

}
