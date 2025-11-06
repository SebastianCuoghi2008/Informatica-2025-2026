/*Calcola il Codice Fiscale*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char Nome[50];
    char Cognome[50];
    char DataDiNascita[11];
    char Sesso;
    char Comune[50];
    char CodiceFiscale[17];

    printf("Inserisci il nome: ");
    scanf("%s", Nome);

    printf("Inserisci il cognome: ");
    scanf("%s", Cognome);

    printf("Inserisci la data di nascita (gg/mm/aaaa): ");
    scanf("%s", DataDiNascita);

    printf("Inserisci il sesso (M/F): ");
    scanf(" %c", &Sesso);

    printf("Inserisci il comune di nascita: ");
    scanf("%s", Comune);

    calcola_codice_fiscale(Nome, Cognome, DataDiNascita, Sesso, Comune, CodiceFiscale);

    printf("Il codice fiscale calcolato è: %s\n", CodiceFiscale);

    return 0;
}