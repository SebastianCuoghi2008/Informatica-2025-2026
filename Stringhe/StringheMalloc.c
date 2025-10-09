/* Stringhe con malloc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *buffer;   //puntatore alla stringa buffer
    int lunghezza;

    printf("Inserisci una stringa: ");
    scanf("%d", &lunghezza);

    //Alloco lo spazio in memoria alla stringa
    buffer = (char *)malloc((lunghezza + 1) *sizeof(char));
    if(buffer == NULL){
        return 1;
    }
    printf("Inserisci una stringa: ");
    if(fgets(buffer, (lunghezza+1), stdin) != NULL){
        printf("Hai inserito: %s", buffer);
    }
    free(buffer);
}