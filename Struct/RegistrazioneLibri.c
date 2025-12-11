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

typedef struct{
    char Titolo[40];
    char Autore[30];
    int AnnoPubblicazione;
}Libro;

void InserimentoLibri(Libro *Libreria, int N){
    for(int i=0; i<N; i++){
        printf("inserisci il titolo del libro: ");
        scanf("%s", Libreria[i].Titolo);
        fflush(stdin);
        printf("inserisci l'autore del libro: ");
        scanf("%s", Libreria[i].Autore);
        fflush(stdin);
        printf("inserisci l'anno di pubblicazione del libro: ");
        scanf("%d", &Libreria[i].AnnoPubblicazione);
        fflush(stdin);    
    }
}
void StampamentoLibri(Libro *Libreria, int N){
    for(int i=0; i<N; i++){
        printf("Titolo libro: %s\n", Libreria[i].Titolo);
        printf("Autore libro: %s\n", Libreria[i].Autore);
        printf("Anno pubblicazione libro: %d\n", Libreria[i].AnnoPubblicazione);
    }
}
void RimuovereLibro(Libro *Libreria, int *N, char TitoloRimuovi[]){
    int trovato = 0;
    for(int i=0; i<*N; i++){
        if(strcmp(Libreria[i].Titolo, TitoloRimuovi) == 0){
            trovato = 1;
            for(int j=i; j<*N-1; j++){
                Libreria[j] = Libreria[j+1];
            }
            (*N)--;
            break;
        }
    }
    if(!trovato){
        printf("Libro non trovato.\n");
    }
}

int main(){
    Libro *Libreria;
    int N=0;
    int scelta=0;
    char TitoloRimuovi[40];

    do{
        printf("inserisci il numero dei libri da registrare(masiimo 15): ");
        scanf("%d", &N);
    }while(N<0 || N>15);

    Libreria=(Libro*)malloc(N*sizeof(Libro));
    if(Libreria == NULL){
        printf("Errore durante l'allocazione");
        exit(1);
    }

    printf("Scegli un'opzione:\n");
    printf("1. Inserire libri\n");
    printf("2. Stampare libri\n");
    printf("3. Rimuovere un libro\n");
    scanf("%d", &scelta);
    switch(scelta){
        case 1:
            InserimentoLibri(Libreria, N);
            break;
        case 2:
            StampamentoLibri(Libreria, N);
            break;
        case 3:
            RimuovereLibro(Libreria, &N, TitoloRimuovi);
            break;
        default:
            printf("scelta non valida.\n");
            break;
    }

    free(Libreria);
    return 0;
}