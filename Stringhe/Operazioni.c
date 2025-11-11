/*
Provare la libreria string.h per le seguenti operazioni:
1. Calcolo lunghezza stringa
2. Controllo stringhe uguali
3. Copiare una stringa
4. Cercare un carattere e comunicare la frequenza
5. Concatenare due stringhe
6. Ricerca di una stringa nell'altra
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

int calcola_lunghezza_stringa(Stringa S1){
    int Dim=0;
    while(S1[Dim]!='\0'){
        Dim++;
    } 
    return Dim;
}

int conta_occorrenze(Stringa S1, char carattere){
    int Dim = 0;
    int cnt_carattere = 0;
    while(S1[Dim] != '\0'){
        if(S1[Dim] == carattere){
            cnt_carattere++;
        }
        Dim++;
    }
    return cnt_carattere;

}

int main(){
    char S1[]="amore";
    char S2[]="vero";
    char S3[50];
    char S4[50]= "l'";
    char S5[]="l'amore è speciale e importante nella vita";
    char S6[]="con l'amore non sei mai solo";

    //lunghezza stringa
    printf("la prima stringa è lunga %zu caratteri, mentre la seconda è lunga %zu caratteri.\n", strlen(S1), strlen(S2));

    //stringhe uguali
    if(strcmp(S1,S2)==0){
        printf("La prima stringa è uguale alla seconda.\n");
    }else{
        printf("la prima stringa non è ugale alla seconda.\n");
    }

    //copiare stringa
    strcpy(S3, S1);
    printf("la stringa è stata copiata: %s\n", S3);
    strcpy(S3, S2);
    printf("la stringa è stata copiata: %s\n", S3);
    
    //cercare carrattere e frequenza
    printf("la lettera A in questa stringa appare %d volte.\n",conta_occorrenze(S5, 'a'));
    printf("la lettera E in questa stringa appare %d volte.\n",conta_occorrenze(S5, 'e'));
    printf("la lettera I in questa stringa appare %d volte.\n",conta_occorrenze(S5, 'i')); 

    //concatenare
    strcat(S4, "amore è romantico♥");
    printf("%s\n", S4);

    //ricerca stringa
    char *posizione = strchr(S6, 'a');
    if(posizione != NULL){
        printf("Il carattere 'a' si trova alla posizione: %ld\n\n", posizione - S6);
    }
    else{
        printf("Il carattere 'a' non è stato trovato.\n\n");
    }
    return 0;
}

