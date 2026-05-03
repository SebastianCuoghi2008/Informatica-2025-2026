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
    char Cerca[30];

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Libro libro;

    printf("Inserisci il titolo del libro da cercare: ");
    scanf(" %[^\n]", Cerca);
    getchar();

    while(fread(&libro, sizeof(Libro), 1, pFile)){
        if(strcmp(libro.Titolo, Cerca) == 0){
            printf("Libro trovato!\n");
            printf("Autore: %s, Titolo %s, ISBN: %s, Anno: %d\n", libro.Autore, libro.Titolo, libro.ISBN, libro.Anno);
            printf("\n");
        }
    }

    if(strcmp(libro.Titolo, Cerca) != 0){
        printf("Libro non trovato\n");
    }

    fclose(pFile);
}

void Cancellazione_libro(){

    FILE *pFile = fopen("Biblioteca.bin", "rb");
    FILE *pFile_tmp = fopen("Tmp.bin", "wb");
    char Cerca[30];

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }
    if(pFile_tmp == NULL){
        printf("Errore nella apertura del file temopraneo\n");
        return;
    }

    Libro libro;

    printf("Inserisci il titolo del libro da eliminare: ");
    scanf(" %[^\n]", Cerca);
    getchar();

    while(fread(&libro, sizeof(Libro), 1, pFile)){
        if(strcmp(libro.Titolo, Cerca) == 0){
            printf("Trovato!\n");
            printf("Il libro sara' eliminato ");
            printf("\n");
        }
        else{
            fwrite(&libro, sizeof(Libro), 1, pFile_tmp);
        }
    }

    fclose(pFile);
    fclose(pFile_tmp);

    pFile = fopen("Tmp.dat", "rb");
    pFile_tmp = fopen("Biblioteca.bin", "wb");

    while(fread(&libro, sizeof(Libro), 1, pFile)){
        fwrite(&libro, sizeof(Libro), 1, pFile_tmp);
    }

    fclose(pFile);
    fclose(pFile_tmp);
}

void Modificazione_libro(){
    FILE *pFile = fopen("Biblioteca.bin", "rb+");
    char Modifica_ISBN[30];
    int Trovato = 0;

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Libro libro;

    printf("Inserisci il ISBN del libro da modificare: ");
    scanf(" %[^\n]", Modifica_ISBN);
    getchar();

    while(fread(&libro, sizeof(Libro), 1, pFile)){
        if(strcmp(libro.ISBN, Modifica_ISBN) == 0){
            printf("Trovato!\n");
            printf("Inserisci il nuovo ISBN: ");
            scanf(" %[^\n]", libro.ISBN);
            getchar();

            fseek(pFile, - sizeof(Libro), SEEK_CUR);

            fwrite(&libro, sizeof(Libro), 1, pFile);
            Trovato = 1;
        }
    }
    if(!Trovato){
        printf("\nProdotto non trovato");
    }
}

void Separazione_specifica(){

    FILE *pFile = fopen("Biblioteca.bin", "rb");
    FILE *pFile_pre2000 = fopen("Libri_pre2000.bin", "wb");
    FILE *pFile_post2000 = fopen("Libri_post2000.bin", "wb");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }
    if(pFile_pre2000 == NULL){
        printf("Errore nella apertura del file pre 2000\n");
        return;
    }
    if(pFile_post2000 == NULL){
        printf("Errore nella apertura del file post 2000\n");
        return;
    }

    Libro libro;

    while(fread(&libro, sizeof(Libro), 1, pFile)){
        if(libro.Anno < 2000){
            fwrite(&libro, sizeof(Libro), 1, pFile_pre2000);
        }
        else{
            fwrite(&libro, sizeof(Libro), 1, pFile_post2000);
        }
    }

    fclose(pFile);
    fclose(pFile_pre2000);
    fclose(pFile_post2000);

    pFile_pre2000 = fopen("Libri_pre2000.bin", "rb");
    pFile_post2000 = fopen("Libri_post2000.bin", "rb");

    printf("\n -----Libri creati prima del 2000-----\n");
    while(fread(&libro, sizeof(Libro), 1, pFile_pre2000)){
        printf("Autore: %s, Titolo %s, ISBN: %s, Anno: %d\n", libro.Autore, libro.Titolo, libro.ISBN, libro.Anno);
    }
    printf("\n -----Libri creati dopo il 2000-----\n");
    while(fread(&libro, sizeof(Libro), 1, pFile_post2000)){
        printf("Autore: %s, Titolo %s, ISBN: %s, Anno: %d\n", libro.Autore, libro.Titolo, libro.ISBN, libro.Anno);
    }

    fclose(pFile_pre2000);
    fclose(pFile_post2000);
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

    return 0;
}