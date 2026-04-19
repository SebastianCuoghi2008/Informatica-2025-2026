/*Leggere una parola dal terminale, e scriverla su un file.
Leggere il file e stampare tutto il contenuto a schermo.
Il file mantiene tutte le parole che sono state scritte in precedenza
e la nuova viene aggiunta alla fine*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *pFile = NULL;
    char Parola[25];

    pFile = fopen("Testo_append.txt", "a");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return 1;
    }
    else{
        printf("File aperto con successo!\n");
    }

    printf("Inserisci una parola casuale: ");
    scanf("%s", Parola);

    fprintf(pFile, "%s\n", Parola);

    fclose(pFile);
    pFile = NULL;

    pFile = fopen("Testo_append.txt", "r");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return 1;
    }
    else{
        printf("File aperto con successo!\n");
    }

    while(fgets(Parola, sizeof(Parola), pFile) != NULL){
        printf("%s", Parola);
    }

    fclose(pFile);
    pFile = NULL;

    return 0;
}