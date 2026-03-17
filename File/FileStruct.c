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
    Persona Persone[0];

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return 1;
    }
    
    for(int i = 0; i < 1; i++){
        printf("Inserisci il sospetto/a:\n");
        fgets(Persone[i].Nome, 30, stdin);
        Persone[i] = [sizeof(Persone->Nome) - 1] = '\0';
        fgets(Persone[i].Cogome, 30, stdin);
        Persone[i] = [sizeof(Persone->Cognome) - 1] = '\0';
        scanf("%d", &Persone[i].Eta);
        scanf("%c", &Persone[i].Sesso);
        fgets(Persone[i].Targa, 8, stdin);
        Persone[i]= [sizeof(Persone.Targa) - 1] = '\0';
    }

    fprintf(pFile, "%s\n %s\n %d\n %c\n %s\n", Persone->Nome, Persone->Cogome, Persone->Eta, Persone->Sesso, Persone->Targa);

    fclose(pFile);
    return 0;
}