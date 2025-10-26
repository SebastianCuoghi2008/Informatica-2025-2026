#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

int main() {
    Stringa frase;
    int size = 20;

    frase = (Stringa)malloc(size * sizeof(char));
    if(frase == NULL){
       return 1; 
    }

    strcpy(frase, "C è bello");

    // Aggiungo testo ridimensionando
    size += 20;
    frase = (Stringa)realloc(frase, size * sizeof(char));
    if(frase == NULL){
        return 1;
    }

    strcat(frase, " ma anche difficile!");

    printf("%s\n", frase);

    free(frase);
    return 0;
}
