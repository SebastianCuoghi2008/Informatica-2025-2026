/*Data la struct pordotto:
-Nome
-Codice (int)
-Quntità
-Prezzo
Eseguire:
1. Inserire podotto
2. Stampare elenco prodotti
3. Cercare un prodotto per codice
4. Calcolare il valore totale del magazzino*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Prodotto{
	char Nome[50];
	int Codice;
	int Quantita;
    float Prezzo;
}Prodotto;

Prodotto* Inserimento_Prodotto(Prodotto* prodotto, int* N){
	
    prodotto = (Prodotto*)realloc(prodotto, ((*N) +1)*sizeof(prodotto));
    if(prodotto == NULL){
        printf("Errore di allocazione\n");
        exit(1);
    }
	
    printf("Inserisci il nome del prodotto: ");
    fgets(prodotto[*N].Nome, 50, stdin);
    printf("Inserisci il suo codice: ");
    scanf("%d", &prodotto[*N].Codice);
    printf("Inserisci la sua quantita': ");
    scanf("%d", &prodotto[*N].Quantita);
    printf("Inserisci il suo prezzo: ");
    scanf("%f", &prodotto[*N].Prezzo);
    
    (*N)++;
    return prodotto;
}

void Stampamento_Prodotto(Prodotto* prodotto, int N){
	
	printf("\n===Lista prodotti===\n\n");
    for(int i = 0; i < N; i++){
        printf("Prodotto %d: \n", i + 1);
        printf("Nome: %s \n", prodotto[i].Nome);
        printf("Codice: %d \n", prodotto[i].Codice);
        printf("Quantita': %d \n", prodotto[i].Quantita);
        printf("Prezzo: %.2f Euro\n", prodotto[i].Prezzo);
    }
}

void Cercare_prodotto(Prodotto* prodotto, int N){
    
    int Codice = 0;
    int Trovato = 0;

    printf("Inserisci il codice del prodotto: ");
    scanf("%d", &Codice);

    for(int i = 0; i < N; i++){
        if(Codice == prodotto[i].Codice){
            Trovato = 1;
            printf("Il prodotto e': %s", prodotto[i].Nome);
        }
    }
    if(Trovato == 0){
        printf("Prodotto non trovato\n");
    }
}

void Calcolare_valore_totale(Prodotto* prodotto, int N){

    float Valore_totale = 0;

    for(int i = 0; i < N; i++){
        Valore_totale += prodotto[i].Quantita * prodotto[i].Prezzo;
    }
    printf("Il valore totale del magazzino e': %.2f Euro\n", Valore_totale);
}

int main(){
	Prodotto *Magazzino = NULL;
	int N = 0;
	int Scelta = 0;
    char Carattere;
	
    do{
        printf("\n--- MAGAZZINO ---\n");
        printf("Scegli una opzione:\n");
        printf("1) Inserisci un nuovo prodotto\n");
        printf("2) Visualizza tutti i prodotti\n");
        printf("3) Cercare un prodotto per codice\n");
        printf("4) Calcola il valore totale del magazzino\n");
        printf("0) EXIT\n");
        printf("Scescli tra questi 5: \n");
        scanf("%d", &Scelta);
        while((Carattere = getchar()) != '\n'){}

        switch(Scelta){
            case 0:
                printf("Grazie di essere venuti nel nostro magazzino, arrivederci!\n");
                break;
            case 1:
                Magazzino = Inserimento_Prodotto(Magazzino, &N);
                break;
            case 2:
                Stampamento_Prodotto(Magazzino, N);
                break;
            case 3:
                Cercare_prodotto(Magazzino, N);
                break;
            case 4:
                Calcolare_valore_totale(Magazzino, N);
                break;
            default:
                printf("\nScelta non valida!");
        }

    }while(Scelta != 0);
}