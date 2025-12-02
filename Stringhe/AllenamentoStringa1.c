#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer(){
    int c;
    while ((c = getchar()) != '\n'){}
}

void CreaParola(char* Parola){
    Parola=(char*)malloc(sizeof(char)*100);
    if(Parola == NULL){
        printf("Errore di memoria!\n");
        exit(1);
    }
}

void LeggiParola(char* Parola){
    printf("Inserisci una parola che vuoi: ");
    if(fgets(Parola, 100, stdin) == NULL){
        printf("Errore di fgets!\n");
        exit(1);
    }
    clear_buffer();
}

int main(){
    int DimParola=0;
    int flag=0;
    char* Parola1;
    CreaParola(Parola1);
    char* Parola2;
    CreaParola(Parola2);

    LeggiParola(Parola1);
    LeggiParola(Parola2);

    printf("la prima parola e': %s", Parola1); 
    printf("la prima parola e': %s", Parola2);

    DimParola=(strlen (Parola1));
    DimParola=(strlen (Parola2));

    for(int i=0; i<DimParola; i++){
        if(Parola1[i] != Parola2[i]){
           flag=1;
        }
    }
    if(flag==1){
        printf("Le parole sono diverse");
    }
    else{
        printf("Le parole sono uguali");
    }

    return 0;
}