/*Esempio di appertura file append*/

#include <stdio.h>

int main(){
    FILE *pFile;
    char Frase[200];
    char Scelta;

    //Apriamo il file in append:
    pFile = fopen("Righe.txt", "a");

    if(pFile == NULL){
        printf("Errore di apertura!\n");
        return;
    }

    do{
        printf("Inserisci una frase: ");
        fgets(Frase, sizeof(Frase), stdin);
        fprintf(pFile, "%s", Frase);

        printf("Vuoi inserire un'altra frase? (S/N) per rispondere: ");
        scanf("%c", &Scelta);
        getchar();
    }while(Scelta == 's' || Scelta == 'S');

    fclose(pFile);

    return 0;
}