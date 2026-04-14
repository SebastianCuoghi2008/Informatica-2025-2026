/*Creata una struct prodotto con nome, ID e prezzo,
Scrivere su un file binario una di serie di prodotti.
Modificare il prezzo di un prodotto dato il suo ID*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ID;
    char Nome[50];
    float Prezzo;
}Prodotto;

void Inserisci_prodotto(const char *File_nome){
    FILE *pFile = fopen(File_nome, "ab");
    int N;
    Prodotto prodotto;

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    printf("Quanti prodotti vuoi inserire?\n");
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        printf("Prodotto numero %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &prodotto.ID);
        getchar();
        printf("Nome: ");
        scanf("%[^\n]", prodotto.Nome);
        getchar();
        printf("Prezzo: ");
        scanf("%f", &prodotto.Prezzo);
        getchar();

        fwrite(&prodotto, sizeof(Prodotto), 1, pFile);

    }
    fclose(pFile);
}

void Stampa_prodotti(const char *File_nome){
    FILE *pFile = fopen(File_nome, "rb");
    Prodotto prodotto;

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }
    
    printf("\nElenco prodotti\n");
    while(fread(&prodotto, sizeof(Prodotto), 1, pFile) == 1){
        printf("ID: %d - Nome: %s - Prezzo: %.2f\n", prodotto.ID, prodotto.Nome, prodotto.Prezzo);
    }
    fclose(pFile);
}

void Cerca_prodotto(const char *File_nome, int _ID){
    FILE *pFile = fopen(File_nome, "rb");
    Prodotto prodotto;
    int Trovato = 0;

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    while(fread(&prodotto, sizeof(Prodotto), 1, pFile) == 1){
        if(prodotto.ID == _ID){
            printf("\nProdotto trovato, Nome: %s - Prezzo: %.2f", prodotto.Nome, prodotto.Prezzo);
            Trovato = 1;
            break;
        }
    }
    if(!Trovato){
        printf("\nProdotto non trovato");
    }
    fclose(pFile);
}

void Modifica_prdotto(const char *File_nome, int _ID, float N_prezzo){
    FILE *pFile = fopen(File_nome, "rb+");
    Prodotto prodotto;

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    while(fread(&prodotto, sizeof(Prodotto), 1, pFile) == 1){
        if(prodotto.ID == _ID){
            prodotto.Prezzo = N_prezzo;

            fseek(pFile, - sizeof(Prodotto), SEEK_CUR);

            fwrite(&prodotto, sizeof(Prodotto), 1, pFile);
        }
    }
    fclose(pFile);
}

int main(){
    const char *File = "Prodotti.dat";
    int Scelta;
    int ID;
    float Nuovo_prezzo;

    do{
        printf("\nMenu' prodotti: \n");
        printf("1. Aggiungi prodotto\n");
        printf("2. Visualizza elenco prodotti\n");
        printf("3. Modifica prezzo prodotto\n");
        printf("0. Esci\n");
        printf("Scegli: ");
        scanf("%d", &Scelta);
        getchar();

        switch(Scelta){
            case 1:
                Inserisci_prodotto(File);
                break;
            case 2:
                Stampa_prodotti(File);
                break;
            case 3:
                printf("\nInserisci l'ID del prodotto: ");
                scanf("%d", &ID);
                getchar();
                Cerca_prodotto(File, ID);
                printf("\nInserisci il nuovo prezzo: ");
                scanf("%f", &Nuovo_prezzo);
                getchar();
                Modifica_prdotto(File, ID, Nuovo_prezzo);
                break;
            case 0:
                printf("Esci dal programma ");
                break;
            default:
                printf("Scelta non valida\n");
        }
    }while(Scelta != 0);
}