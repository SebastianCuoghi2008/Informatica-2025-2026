/*Creare una struct che rappresenta un tavolo contenente i dati: altezza,
larghezza, profondità, materiale, marca.
Creare un array di 3 tavoli con i seguenti dati:
Tavolo 1 marca Ikea, materiale truciolato, altezza 90 cm, profondità 50 cm, larghezza 120 cm
Tavolo 2 marca Mondi, materiale noce, altezza 95 cm, profondità 75 cm, larghezza 140 cm
Tavolo 3 marca Silmy, materiale compensato, altezza 80 cm, profondità 60 cm, larghezza 90 cm
Infine creare dinamicamente un tavolo chiedendo di inserire i dati da tastiera.
Per ogni dato (altezza, larghezza, profondità, materiale, marca) controllare se
esiste un tavolo con quel dato e stampare a schermo la posizione nell'array.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char* Stringa;

struct Tavolo{
    char Marca[50];
    char Materiale[50];
    int Altezza;
    int Larghezza;
    int Profondità;
};


int main(){
    struct Tavolo *Tavoli;
    int N = 3;

    //Allocazione dei tavoli
    Tavoli = (struct Tavolo*)malloc(N * sizeof(struct Tavolo));     

    if(Tavoli == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    //inserimento dei dati:
    strcpy(Tavoli[0].Marca, "Ikea");
    strcpy(Tavoli[0].Materiale, "Truciolato");
    Tavoli[0].Altezza = 90;
    Tavoli[0].Profondità = 50;
    Tavoli[0].Larghezza = 120;

    strcpy(Tavoli[1].Marca, "Mondi");
    strcpy(Tavoli[1].Materiale, "Noce");
    Tavoli[1].Altezza = 95;
    Tavoli[1].Profondità = 75;
    Tavoli[1].Larghezza = 140;

    strcpy(Tavoli[2].Marca, "Slimy");
    strcpy(Tavoli[2].Materiale, "Compensato");
    Tavoli[2].Altezza = 80;
    Tavoli[2].Profondità = 60;
    Tavoli[2].Larghezza = 90;

    //Visualizzaione dei dati:
    printf("\n===Lista Tavoli===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Tavolo %d: \n", i + 1);
        printf("Marca: %s \n", Tavoli[i].Marca);
        printf("Materiale: %s \n", Tavoli[i].Materiale);
        printf("Altezza: %dcm \n", Tavoli[i].Altezza);
        printf("Profondità: %dcm \n", Tavoli[i].Profondità);
        printf("Larghezza: %dcm \n\n", Tavoli[i].Larghezza);
    }

    //Realloc per aggiungere uno o più libri:
    N += 1;

    Tavoli = (struct Tavolo*)realloc(Tavoli, N * sizeof(struct Tavolo));

    if(Tavoli == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    //inserimento dato utente tavolo dinamico:
    printf("Inserisci la marca del tavolo: ");
    fgets(Tavoli[3].Marca, 50, stdin);
    printf("Inserisci il materiale del tavolo: ");
    fgets(Tavoli[3].Materiale, 50, stdin);
    printf("Inserisci l'altezza del tavolo: ");
    scanf("%d", &Tavoli[3].Altezza);
    printf("Inserisci la profondità del tavolo: ");
    scanf("%d", &Tavoli[3].Profondità);
    printf("Inserisci la larghezza del tavolo: ");
    scanf("%d", &Tavoli[3].Larghezza);

    //Visualizzaione dei dati aggiornati:
    printf("\n===Lista Tavoli===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Tavolo %d: \n", i + 1);
        printf("Marca: %s \n", Tavoli[i].Marca);
        printf("Materiale: %s \n", Tavoli[i].Materiale);
        printf("Altezza: %dcm \n", Tavoli[i].Altezza);
        printf("Profondità: %dcm \n", Tavoli[i].Profondità);
        printf("Larghezza: %dcm \n\n", Tavoli[i].Larghezza);
    }
    free(Tavoli);
}