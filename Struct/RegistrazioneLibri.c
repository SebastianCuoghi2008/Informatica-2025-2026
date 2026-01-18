/*Registrare le informazioni di alcuni libri:
    titolo, autore, anno pubblicazione.
    Array di libri.
    Caricare l'array.
    Pubblicare.
    Rimuovere un libro.
    Cercare un libro in base al titolo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

struct Libro{
    char Titolo[40];
    char Autore[20];
    int Anno;
    float Prezzo;
};

void Compatta(Stringa Buffer, int Lunghezza){
    if(Lunghezza > 0 && Buffer[Lunghezza - 1] == '\n'){
        Buffer[Lunghezza - 1] = '\0';
        Lunghezza --;
    }
}

int main(){
    struct Libro *Libri;
    int N = 3;
    int Dotato;
    int I_Dotato;
    float Costoso;
    int I_Costoso;
    char Lib[40];
    int Lun;

    //allocazione dei primi 3 elementi
    Libri = (struct Libro*)malloc(N * sizeof(struct Libro));

    if(Libri == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    //inserimento dei dati:
    strcpy(Libri[0].Titolo, "l'amore mio non muore");
    strcpy(Libri[0].Autore, "Roberto Saviano");
    Libri[0].Anno = 2025;
    Libri[0].Prezzo = 19.50;

    strcpy(Libri[1].Titolo, "Maledetti di Dio");
    strcpy(Libri[1].Autore, "Sven Assel");
    Libri[1].Anno = 1953;
    Libri[1].Prezzo = 13;

    strcpy(Libri[2].Titolo, "Il diritto di contare");
    strcpy(Libri[2].Autore, "Margot Lee Schetterly");
    Libri[2].Anno = 2017;
    Libri[2].Prezzo = 18.5;

    //Realloc per aggiungere uno o più libri:
    N += 1;

    Libri = (struct Libro*)realloc(Libri, N * sizeof(struct Libro));

    if(Libri == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    strcpy(Libri[3].Titolo, "Orgoglio e pregiudizio");
    strcpy(Libri[3].Autore, "Jane Austen");
    Libri[3].Anno = 1813;
    Libri[3].Prezzo = 9;

    //Visualizzaione dei dati aggiornati:
    printf("\n===Lista Libri===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Libro %d: \n", i + 1);
        printf("Titolo: %s \n", Libri[i].Titolo);
        printf("Autore: %s \n", Libri[i].Autore);
        printf("Anno: %d \n", Libri[i].Anno);
        printf("Prezzo: %.2f \n\n", Libri[i].Prezzo);
    }

    //Ricerca del libro più dotato:
    Dotato = Libri[0].Anno;
    I_Dotato = 0;
    
    for(int i = 1; i < N; i ++){
        if(Libri[i].Anno < Dotato){
            Dotato = Libri[i].Anno;
            I_Dotato = i;
        }
    }
    printf("Il libro piu dotato e': %s\n", Libri[I_Dotato].Titolo);

    //Ricerca del libro più costoso:
    Costoso = Libri[0].Prezzo;
    I_Costoso = 0;
    
    for(int i = 1; i < N; i ++){
        if(Libri[i].Prezzo > Costoso){
            Costoso = Libri[i].Prezzo;
            I_Costoso = i;
        }
    }
    printf("Il libro piu costoso e': %s\n", Libri[I_Costoso].Titolo);

    //ELeminazione di un libro:
    printf("Inserisci il titolo del libro da eliminare: ");
    fgets(Lib, 40, stdin);
    Lun = strlen(Lib);
    Compatta(Lib, Lun);

    for(int i = 0; i < N; i ++){
        if(!(strcmp(Libri[i].Titolo, Lib))){
            for(int j = i; j < (N - 1); j++){
                strcpy(Libri[j].Titolo, Libri[j + 1].Titolo);
                strcpy(Libri[j].Autore, Libri[j + 1].Autore);
                Libri[j].Anno, Libri[j + 1].Anno;
                Libri[j].Prezzo, Libri[j + 1].Prezzo;
            }
            N -= 1;
        }
    }

    Libri = (struct Libro*)realloc(Libri, N * sizeof(struct Libro));

    if(Libri == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    printf("\n===Lista Libri===\n\n");
    for(int i = 0; i < N; i ++){
        printf("Libro %d: \n", i + 1);
        printf("Titolo %s: \n", Libri[i].Titolo);
        printf("Autore %s: \n", Libri[i].Autore);
        printf("Anno %d: \n", Libri[i].Anno);
        printf("Prezzo %.2f: \n\n", Libri[i].Prezzo);
    }
    free(Libri);
}