/*Scrivi un programma che memorizzi i voti di uno studente.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float *voti = NULL;
    int Numero = 0;
    
    printf("quanti voti vuoi aggiungere? ");
    scanf("%d", &Numero);
    voti = (float*) malloc(Numero * sizeof(float));
    
    if(voti == NULL){
        printf("Errore di allocazione memoria!!!!!!! :(((");
        return 1;
    }
    for(int i = 0; i < Numero; i++){
        printf("Inserisci il voto %d: ", i+1);
        scanf("%f", &voti[i]);
    }
    voti = (float*)realloc(voti, (Numero+1)*sizeof(float));
    if(voti == NULL){
        printf("Errore di allocazione memoria!!!!!!! :(((");
        return 1;
    }
    Numero++;
    printf("Inserisci il voto %d: ", Numero);
    scanf("%f", &voti[Numero-1]);

    free(voti);
    voti = NULL;
}