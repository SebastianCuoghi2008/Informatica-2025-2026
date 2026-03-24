/*Inserire le informazioni di uno studente:
Nome, eta, media voti.
Determinare lo studente con la media scolastica più alta*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Nome[35];
    int Eta;
    float Media;
}Studente;

void Scrive_studenti(char *Nome_file, int N_studenti){
    FILE *pFile;

    pFile = fopen(Nome_file, "ab");

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return;
    }
    for(int i = 0; i < N_studenti; i++){
        Studente Alunno;

        printf("Inserisci il nome dello studente %d", i+1);
        scanf("%34s", Alunno.Nome);
        printf("Inserisci l'eta' dello studente %d", i+1);
        scanf("%d", Alunno.Eta);
        printf("Inserisci la media dello studente %d", i+1);
        scanf("%f", Alunno.Media);
        getchar();
        fwrite(&Alunno, sizeof(Studente), 1, pFile);
    }
    fclose(pFile);

    if(ferror(pFile)){
        printf("Errore di chiusura!\n");
    }
}

Studente* Leggi_studenti(char *Nome_file, Studente *Array){
    FILE *pFile;
    int i = 0;

    pFile = fopen(Nome_file, "rb");

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return Array;
    }

    Array = (Studente*)realloc(Array, sizeof(Studente));

    if(Array == NULL){
        printf("Errore di allocazione!\n");
        return Array;
    }

    while(fread(&Array[i], sizeof(Studente), 1, pFile) != 0){
        i++;
        Array = (Studente*)realloc(Array, (i + 1) * sizeof(Studente));

        if(Array == NULL){
            printf("Errore di allocazione!\n");
            return Array;
        }
    }
    Array = (Studente*)realloc(Array, i * sizeof(Studente));

    if(Array == NULL){
        printf("Errore di allocazione!\n");
        return Array;
    }

    fclose(pFile);

    if(ferror(pFile)){
        printf("Errore di chiusura!\n");
    }
    return Array;
}

Studente Trova_migliore(Studente *Array){
    int Dimensione = sizeof(Array) / sizeof(Studente);
    Studente Migliore = {"", 0, 0};

    for(int i = 0; i < Dimensione; i++){
        if(Array[i].Media > Migliore.Media){
            Migliore.Media = Array[i].Media;
            Migliore.Eta = Array[i].Eta;
            strcpy(Migliore.Nome, Array[i].Nome);
        }
    }
    return Migliore;
}

int main(){
    
}