#include <stdio.h>

typedef struct{
    char Nome[30];
    char Cogome[30];
    int Eta;
    char Sesso;
    char Targa[8];
}Persona;

int main(){
    FILE *pFile = fopen("Struct.txt", "w");
    Persona Persone[2];

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return 1;
    }
    
    for(int i = 0; i < Persone; i++){
        printf("Inserisci il sospetto/a:\n");
        fgets(Persone[i].Nome, 30, stdin);
        fgets(Persone[i].Cogome, 30, stdin);
        scanf("%d", &Persone[i].Eta);
        scanf("%c", &Persone[i].Targa);
        fgets(Persone[i].Nome, 8, stdin);
    }

    fprintf(pFile, "%s\n %s\n %d\n %s\n %s\n", Persone->Nome, Persone->Cogome, Persone->Eta, Persone->Sesso, Persone->Targa);

    fclose(pFile);
    return 0;
}