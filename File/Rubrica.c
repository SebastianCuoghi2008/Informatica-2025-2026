/*Creare una rubrica che gestisca la memorizzazione dei contatti e ne visualizzi l'elenco*/

#include <stdio.h>

typedef struct{
    char Nome[30];
    char Telefono[15];
}Contatto;

void Aggiungo_contatto(){

    FILE *pFile = fopen("Contatti.bin", "ab");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Contatto C;

    printf("Inserisci il nome: ");
    scanf("%[^n]", C.Nome);
    printf("Inserisci il numero telefono: ");
    scanf("%[^n]", C.Telefono);

    fwrite(&C, sizeof(Contatto), 1, pFile);

    fclose(pFile);
}

void Stampa_contatti(){
    FILE *pFile = fopen("Contatti.bin", "rb");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Contatto C;

    printf("\n----RUBRICA----\n");
    while(fread(&C, sizeof(Contatto), 1, pFile) == 1){
        printf("Nome: %s, Telefono %s\n", C.Nome, C.Telefono);
    }
    
    fclose(pFile);
}

int main(){
    int Scelta;

    do{
        printf("\nMenu' rubrica: \n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("0. Esci\n");
        printf("Scegli: ");
        scanf("%d", &Scelta);

        switch(Scelta){
            case 1:
                Aggiungo_contatto();
                break;
            case 2:
                Stampa_contatti();
                break;
            case 0:
                printf("Esci dal programma ");
                break;
            default:
                printf("Scelta non valida\n");
        }

        
    }while(Scelta != 0);
}