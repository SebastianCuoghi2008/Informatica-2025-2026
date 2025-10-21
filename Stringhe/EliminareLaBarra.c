/* Eliminare gli spazi da una stringa */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char* String;

String compattaSpazi(String buffer, int len){
    for(int i=0; i<len; i++){
        if(buffer[i]==' '){
            for(int j=i; j<len-1; j++){
                buffer[j]=buffer[j+1];            
            }
            len--; 
        }
    }
    buffer=(String)realloc(buffer, (len+1) * sizeof(char));
    if(buffer==NULL){
        printf("Errore di allozione memoria\n");
        exit(1);
    }
    return buffer;    
}

int main(){
    char buffer[200];
    String frase;
    int len;

    printf("Inserisci una stringa: ");
    fgets(buffer, sizeof(buffer), stdin);
    len= strlen(buffer);
    compattaSpazi(buffer, len);
    frase = (String)malloc((len+1)*sizeof(char));

    if(frase==NULL){
        printf("C'è un errore\n");
        return 1;
    }

    strcpy(frase, buffer);
    printf("La stringa senza spazi e': %s\n", frase);
    free(frase);
}