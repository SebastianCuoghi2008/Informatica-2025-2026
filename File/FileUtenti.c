/*Il programma fa aggiungere persone ad una lista e preparare una mail per inviargli un buono sconto.
L'utente sceglie fra 3 operazioni:
1- L'utente inserisce nome, cognome ed indirizzo mail. Con questi dati, creare una struct dell'utente e aggiungere i 3 dati,
divisi su 3 righe a un file ListaUtenti.txt. Non sovrascrivere gli altri utenti presenti, se ce ne sono.
2- L'utente inserisce un numero a schermo, lo sconto da inviare. Salvare questo valore in un file binario ScontoPercentuale.bin.
3- Caricare gli utenti da ListaUtenti.txt in una lista, e la percentuale di sconto da ScontoPercentuale.bin,
poi per ogni utente stampare a schermo:*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Nome[50];
    char Cognome[50];
    char Email[100];
}Utente;

void Aggiungi_utente(){

    FILE *pFile = fopen("ListaUtenti.txt", "a");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Utente utente;

    printf("Inserisci il nome: ");
    scanf(" %[^\n]", utente.Nome);
    getchar();
    printf("Inserisci il cognome: ");
    scanf(" %[^\n]", utente.Cognome);
    getchar();
    printf("Inserisci l'email: ");
    scanf(" %[^\n]", utente.Email);
    getchar();

    fprintf(pFile, "Nome: %s\nCognome: %s\nEmail: %s\n", utente.Nome, utente.Cognome, utente.Email);
    fclose(pFile);

    printf("\nL'utente e' stato aggiunto\n");
}

void Imposta_sconto(){

    FILE *pFile = fopen("ScontoPercentuale.bin", "wb");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    int Sconto;

    printf("Perfavore inserisci la percentuale di sconto da inviare: ");
    scanf("%d", &Sconto);

    fwrite(&Sconto, sizeof(int), 1, pFile);
    fclose(pFile);

    printf("Lo sconto e' stato impostato\n");
}

void Stampa_utenti_e_sconto(){

    FILE *pFile = fopen("ListaUtenti.txt", "r");
    FILE *pFile_sconto = fopen("ScontoPercentuale.bin", "rb");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }
    if(pFile_sconto == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    char Linea[200];
    int Sconto;

    fread(&Sconto, sizeof(int), 1, pFile_sconto);

    printf("\nLa percentuale di sconto da inviare e' del: %d%%\n", Sconto);
    printf("\n----Lista utenti----\n");
    while(fgets(Linea, sizeof(Linea), pFile)){
        printf("%s", Linea);
    }
    
    fclose(pFile);
    fclose(pFile_sconto);
}

int main(){

    int Scelta;

    do{
        printf("\nMenu' gestione utenti: \n");
        printf("1. Aggiungi utente\n");
        printf("2. Imposta sconto\n");
        printf("3. Visualizza utenti e sconto\n");
        printf("0. Esci\n");
        printf("Scegli: ");
        scanf("%d", &Scelta);

        switch(Scelta){
            case 1:
                Aggiungi_utente();
                break;
            case 2:
                Imposta_sconto();
                break;
            case 3:
                Stampa_utenti_e_sconto();
                break;
            case 0:
                printf("Esci dal programma ");
                break;
            default:
                printf("Scelta non valida, riprova.\n");
                break;
        }
    }while(Scelta != 0);

    return 0;
}