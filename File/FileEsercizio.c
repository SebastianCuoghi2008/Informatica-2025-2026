/*Scrivere un programma che inverta ogni riga contenuta 
nel file righe.txt e riporti il risultato sullo schermo. 
Per esempio la riga "PROVA DI STAMPA"  diventa 
"APMATS ID AVORP"*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Inversione_lettere(char* Stringa, char* Nuova_S){

    for(int i = 0; i < strlen(Stringa); i++){
        Nuova_S[strlen(Stringa) - i - 1] = Stringa[i];
    }
    Nuova_S[strlen(Stringa)] = '\0';
}

int main(){

    FILE *pFile = NULL;
    char Stringa[100];
    char Nuova_S[100];
    char Totale_S[100] = "";

    //Modalità schermo:
    pFile = fopen("Righe2-2.txt", "r");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return 1;
    }
    else{
        printf("File aperto con successo!\n");
    }

    while(fgets(Stringa, sizeof(Stringa), pFile) != NULL){
        Inversione_lettere(Stringa, Nuova_S);
        printf("%s\n", Nuova_S);
        strcat(Totale_S, Nuova_S);
        strcat(Totale_S, "\n");
    }

    fclose(pFile);
    pFile = NULL;

    printf("\n");

    //Modalità File:
    pFile = fopen("Righe2-2.txt", "w");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return 1;
    }
    else{
        printf("File aperto con successo!\n");
    }

    fprintf(pFile, "%s", Totale_S);

    fclose(pFile);
    pFile = NULL;

    return 0;
}