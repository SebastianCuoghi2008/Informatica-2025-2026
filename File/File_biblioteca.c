/*CREARE UN PROGRAMMA CHE GESTISCA UNA LIBRERIA DOTATA DI DIVERSI LIBRI TALE DA POTER ESEGUIRE LE SEGUENTI OPERAZONI:
- AGGIUNTA/CREAZIONE DELLA LISTA DI LIBRI;
- RICERCA DI UN LIBRO;
- CANCELLAZIONE DI UN LIBRO;
- MODIFICA DELL'ISBN;
- SEPARARE LA LISTA DEI LIBRI IN DUE LISTE CONTENENTI RISPETTIVAMENTE I LIBRI CREATI PRIMA DEL 2000 E QUELLI DOPO;
TUTTO VIENE GESTITO DA FILE BINARI
typedef struct{
      char autore[30];
      char titolo[30];
      char ISBN[20];
      int anno;
}Libro;*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Autore[30];
    char Titolo[30];
    char ISBN[20];
    int Anno;
}Libro;

void Aggiunta_libro(){

    FILE *pFile = fopen("Biblioteca.bin", "ab");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Libro libro;

    printf("Inserisci L'autore del libro: ");
    scanf(" %[^\n]", libro.Autore);
    getchar();
    printf("Inserisci il titolo del libro: ");
    scanf(" %[^\n]", libro.Titolo);
    getchar();
    printf("Inserisci il ISBN del libro: ");
    scanf(" %[^\n]", libro.ISBN);
    getchar();
    printf("Inserici l'anno del libro: ");
    scanf("%d", &libro.Anno);
    getchar();

    fwrite(&libro, sizeof(Libro), 1, pFile);
    fclose(pFile);

    printf("Contatto aggiunto\n");
}

void Stampa_libri(){

    FILE *pFile = fopen("Biblioteca.bin", "rb");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Libro libro;

    printf("\n----TUTTI I LIBRI PRESENTI----\n");
    while(fread(&libro, sizeof(Libro), 1, pFile) == 1){
        printf("Autore: %s, Titolo %s, ISBN: %s, Anno: %d\n", libro.Autore, libro.Titolo, libro.ISBN, libro.Anno);
    }
    
    fclose(pFile);
    printf("---------------\n");
}

void Ricerca_libro(){

    FILE *pFile = fopen("Biblioteca.bin", "rb");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Libro libro;

    fclose(pFile);
}

void Cancellazione_libro(){

}

void Modificazione_libro(){

}

void Separazione_specifica(){

}

int main(){

    int Scelta;

    do{
        printf("\n-------Libraccio.it-------: \n");
        printf("1. AGGIUNTA/CREAZIONE DELLA LISTA DI LIBRI\n");
        printf("2. VISUALIZZAZIONE DEI LIBRI\n");
        printf("3. RICERCA DI UN LIBRO\n");
        printf("4. CANCELLAZIONE DI UN LIBRO\n");
        printf("5. MODIFICA DELL'ISBN\n");
        printf("6. SEPARARE LA LISTA DEI LIBRI IN DUE LISTE CONTENENTI RISPETTIVAMENTE I LIBRI CREATI PRIMA DEL 2000 E QUELLI DOPO");
        printf("0. Esci\n");
        printf("Scegli: ");
        scanf("%d", &Scelta);

        switch(Scelta){
            case 1:
                Aggiunta_libro();
                break;
            case 2:
                Stampa_libri();
                break;
            case 3:
                Ricerca_libro();
                break;
            case 4:
                Cancellazione_libro();
                break;
            case 5:
                Modificazione_libro();
                break;
            case 6:
                Separazione_specifica();
                break;
            case 0:
                printf("Esci dal programma ");
                break;
            default:
                printf("Scelta non valida\n");
        }      
    }while(Scelta != 0);

}