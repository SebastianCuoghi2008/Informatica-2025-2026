/*Creare una rubrica che gestisca la memorizzazione dei contatti e ne visualizzi l'elenco*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Nome[30];
    char Telefono[15];
    char Sesso;
}Contatto;

void Aggiungo_contatto(){

    FILE *pFile = fopen("Rubriche.dat", "ab");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Contatto C;

    printf("Inserisci il nome: ");
    scanf(" %[^\n]", C.Nome);
    getchar();
    printf("Inserisci il numero telefono: ");
    scanf(" %[^\n]", C.Telefono);
    getchar();
    printf("Inserisci il sesso: ");
    scanf("%c", &C.Sesso);
    getchar();

    fwrite(&C, sizeof(Contatto), 1, pFile);
    fclose(pFile);

    printf("Contatto aggiunto\n");
}

void Stampa_contatti(){
    FILE *pFile = fopen("Rubriche.dat", "rb");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Contatto C;

    printf("\n----RUBRICA----\n");
    while(fread(&C, sizeof(Contatto), 1, pFile) == 1){
        printf("Nome: %s, Telefono %s, Sesso: %c\n", C.Nome, C.Telefono, C.Sesso);
    }
    
    fclose(pFile);
    printf("---------------\n");
}

void Elimina_contatto(){

    FILE *pFile = fopen("Rubriche.dat", "rb");
    FILE *pFile_tmp = fopen("Tmp.dat", "wb");
    char Cerca[30];

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }
    if(pFile_tmp == NULL){
        printf("Errore nella apertura del file temopraneo\n");
        return;
    }

    Contatto C;

    printf("Inserisci il nome: ");
    scanf(" %[^\n]", Cerca);
    getchar();

    while(fread(&C, sizeof(Contatto), 1, pFile)){
        if(strcmp(C.Nome, Cerca) == 0){
            printf("Trovato!\n");
            printf("L'elemento sara' eliminato ");
            printf("\n");
        }
        else{
            fwrite(&C, sizeof(Contatto), 1, pFile_tmp);
        }
    }

    fclose(pFile);
    fclose(pFile_tmp);

    pFile = fopen("Tmp.dat", "rb");
    pFile_tmp = fopen("Rubriche.dat", "wb");

    while(fread(&C, sizeof(Contatto), 1, pFile)){
        fwrite(&C, sizeof(Contatto), 1, pFile_tmp);
    }

    fclose(pFile);
    fclose(pFile_tmp);
}

void Separa_contatti(){

    FILE *pFile = fopen("Rubriche.dat", "rb");
    FILE *pFile_F = fopen("Femmine.dat", "wb");
    FILE *pFile_M = fopen("Maschi.dat", "wb");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }
    if(pFile_F == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }
    if(pFile_M == NULL){
        printf("Errore nella apertura del file\n");
        return;
    }

    Contatto C;

    while(fread(&C, sizeof(Contatto), 1, pFile)){
        if(C.Sesso == 'f' || C.Sesso == 'F'){
            fwrite(&C, sizeof(Contatto), 1, pFile_F);
        }
        else if(C.Sesso == 'm' || C.Sesso == 'M'){
            fwrite(&C, sizeof(Contatto), 1, pFile_M);
        }
        else{
            printf("Carattere non valido!\n");
            return;
        }
    }

    fclose(pFile);
    fclose(pFile_F);
    fclose(pFile_M);

    pFile_F = fopen("Femmine.dat", "rb");
    pFile_M = fopen("Maschi.dat", "rb");

    printf("\n -----Rubrica femmine-----\n");
    while(fread(&C, sizeof(Contatto), 1, pFile_F)){
        printf("Nome: %s, Telefono %s, Sesso: %c\n", C.Nome, C.Telefono, C.Sesso);
    }

    printf("\n -----Rubrica maschi-----\n");
    while(fread(&C, sizeof(Contatto), 1, pFile_M)){
        printf("Nome: %s, Telefono %s, Sesso: %c\n", C.Nome, C.Telefono, C.Sesso);
    }

    fclose(pFile_F);
    fclose(pFile_M);
}

int main(){
    
    int Scelta;

    do{
        printf("\nMenu' rubrica: \n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("3. Elimina contatto\n");
        printf("4. Separa i contatti in base al sesso\n");
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
            case 3:
                Elimina_contatto();
                break;
            case 4:
                Separa_contatti();
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