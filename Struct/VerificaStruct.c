#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

typedef struct Data{
	int Giorno;
	int Mese;
	int Anno;
}Data;

typedef struct Libro{
    char Titolo[50];
    char Autore[50];
    int ISBN;
    int Copie_totali;
    int Copie_disponibili;
    Data Data_prestito;			
    Data Data_restituzione;
}Libro;

void Compatta(Stringa Buffer, int Lunghezza){
    if(Lunghezza > 0 && Buffer[Lunghezza - 1] == '\n'){
        Buffer[Lunghezza - 1] = '\0';
        Lunghezza --;
    }
}

Libro* Inserimento_libro(Libro* libro, int* N){
	
    libro = (Libro*)realloc(libro, ((*N) +1)*sizeof(libro));
    if(libro == NULL){
        printf("Errore di allocazione\n");
        exit(1);
    }
	
    printf("Inserisci il titolo: ");
    fgets(libro[*N].Titolo, 50, stdin);
    printf("Inserisci l'autore': ");
    fgets(libro[*N].Autore, 50, stdin);
    printf("Inserisci ISBN: ");
    scanf("%d", &libro[*N].ISBN);
    printf("Inserisci le copie totali: ");
    scanf("%d", &libro[*N].Copie_totali );
    libro[*N].Copie_disponibili = libro[*N].Copie_totali;
    libro[*N].Data_prestito.Giorno = 0;
    libro[*N].Data_prestito.Mese = 0;
    libro[*N].Data_prestito.Anno = 0;
    libro[*N].Data_restituzione.Giorno = 0;
    libro[*N].Data_restituzione.Mese = 0;
    libro[*N].Data_restituzione.Anno = 
    
    (*N)++;
    return libro;
}

void Stampamento_libro(Libro* libro, int N){
	
	printf("\n===Lista Libri===\n\n");
    for(int i = 0; i < N; i++){
        printf("Libro %d: \n", i + 1);
        printf("Titolo: %s \n", libro[i].Titolo);
        printf("Autore: %s \n", libro[i].Autore);
        printf("ISBN: %d \n", libro[i].ISBN);
        printf("Copie totali: %d \n", libro[i].Copie_totali);
        printf("Copie disponibili: %d \n", libro[i].Copie_disponibili);
        printf("Data prestito: %d/%d/%d \n", libro[i].Data_prestito.Giorno, libro[i].Data_prestito.Mese, libro[i].Data_prestito.Anno);
        printf("Data restituzione: %d/%d/%d \n", libro[i].Data_restituzione.Giorno, libro[i].Data_restituzione.Mese, libro[i].Data_restituzione.Anno);
    }
}

void Registrazione_libro(Libro* libro, int N){
    int ISBN = 0;
    int Trovato = 0;

    printf("Inserisci L'ISBN del libro: ");
    scanf("%d", &ISBN);

    for(int i = 0; i < N; i++){
        if(ISBN == libro[i].ISBN){
            if(libro[i].Copie_disponibili != 0){
                Trovato = 1;
                libro[i].Copie_disponibili -= 1;
                printf("\nInserisci la data del prestito: ");
                scanf("%d", &libro->Data_prestito.Giorno);
                scanf("%d", &libro->Data_prestito.Mese);
                scanf("%d", &libro->Data_prestito.Anno);
                printf("\nInserisci la data della restituzione: ");
                scanf("%d", &libro->Data_restituzione.Giorno);
                scanf("%d", &libro->Data_restituzione.Mese);
                scanf("%d", &libro->Data_restituzione.Anno);
            }
            else{
                printf("\nMidispiace, Copie non disponibili");
            }
        }
    }
    if(!Trovato){
        printf("\nMidispiace, libro non trovato");
    }
}

void Stampamento_libro_prestito(Libro* libro, int N){
    
    for(int i = 0; i < N; i++){
        if(libro[i].Copie_disponibili < libro[i].Copie_totali){
            printf("Il libro in prestito e': %s", libro[i].Titolo);
        }
    }
}

void Stampamento_prestito_scaduto(Libro* libro, int N){

    int Giorni_trascorsi;

    for(int i = 0; i < N; i++){
        Giorni_trascorsi = 30*(libro[i].Data_restituzione.Mese - libro[i].Data_prestito.Mese) + libro[i].Data_restituzione.Giorno + (30 - libro[i].Data_prestito.Giorno);
        if(Giorni_trascorsi > 40){
            printf("\nTitolo: %s", libro[i].Titolo);
            printf("\nAutore: %s", libro[i].Autore);
        }
    }
}
 	
int main(){
	Libro *Biblioteca = NULL;
	int N = 0;
	int Scelta = 0;
    char Carattere;
	
    do{
        printf("\n--- BIBLIOTECA ---\n");
        printf("Scegli una opzione:\n");
        printf("1) Inserisci un nuovo libro\n");
        printf("2) Visualizza tutti i libri\n");
        printf("3) Registrare il prestito\n");
        printf("4) Visualizza i libri in prestito\n");
        printf("5) Stampare il libro con il prestito scaduto\n");
        printf("0) EXIT\n");
        printf("Scescli tra questi 6: \n");
        scanf("%d", &Scelta);
        while((Carattere = getchar()) != '\n'){}

        switch(Scelta){
            case 0:
                printf("Grazie di essere venuti nella nostra bibblioteca, arrivederci!\n");
                break;
            case 1:
                Biblioteca = Inserimento_libro(Biblioteca, &N);
                break;
            case 2:
                Stampamento_libro(Biblioteca, N);
                break;
            case 3:
                Registrazione_libro(Biblioteca, N);
                break;
            case 4:
                Stampamento_libro_prestito(Biblioteca, N);
                break;
            case 5:
                Stampamento_prestito_scaduto(Biblioteca, N);
                break;
            default:
                printf("\nScelta non valida!");
        }

    }while(Scelta != 0);
}