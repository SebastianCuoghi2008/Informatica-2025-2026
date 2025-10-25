/*Scrivi un programma in C che permetta di far scrivere un messaggio 
di lunghezza variabile all'utente.*/

#include <stdio.h>
#include <stdlib.h>

typedef char* Stringa;

int main(){
    Stringa frase = NULL;
    int cnt = 0;
    int capacità = 0;
    char c;
    c = getchar();

    while(c != '\n') {
        if(cnt + 1 > capacità){
            capacità += 10;
            frase = (Stringa) realloc(frase, capacità * sizeof(char));
            if(frase == NULL){
                printf("Ahia ahia :(");
                return 1;
            }
        }      
        frase[cnt] = c;
        cnt++;
        c = getchar();
    }
    frase[cnt] = '\0';
    
    printf("%s", frase);
    free(frase);

    return 0;
}