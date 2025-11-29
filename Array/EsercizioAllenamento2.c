/*Fai inserire all'utente un numero intero X a piacere. Crea un array lungo X,
e ci metti dentro i numeri pari a partire da 0 in su, poi lo stampi a schermo.
Dopodiché, fai un array che sia il contrario del primo, quindi sempre lungo X ma con i numeri pari a scendere,
fino a 0 che sarà l'ultimo; stampa a schermo anche questo.
Come ultima cosa, fai un terzo array lungo X con la somma dei vari elementi dei primi due (primo col primo, secondo col secondo, terzo col terzo, eccetera).
Lo stampi a schermo, e dovrebbe venire un array con tutti i numeri uguali. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int NumeroX;

    printf("Inserisci un numero a piacere intero positivo: ");
    scanf("%d", &NumeroX);
    if(NumeroX < 0){
        printf("Errore, non inserire roba a caso perfavore.\n");
        return 1;
    }

    int* Array1 = (int*)malloc(NumeroX * sizeof(int));
    int* Array2 = (int*)malloc(NumeroX * sizeof(int));
    int* Array3 = (int*)malloc(NumeroX * sizeof(int));

    for(int i = 0; i < NumeroX; i++){   
        Array1[i] = i * 2;      //Metodo per stampare i numeri pari crescenti
    }
    printf("Primo array, i numeri pari crescenti:\n");
    for(int i = 0; i < NumeroX; i++){
        printf("%d ", Array1[i]);
    }
    printf("\n");

    for(int i = 0; i < NumeroX; i++){
        Array2[i] = (NumeroX - 1 - i) * 2;      //Metodo per stampare i numeri pari decrescenti
    }
    printf("Secondo array, i numeri pari decrescenti:\n");
    for(int i = 0; i < NumeroX; i++){
        printf("%d ", Array2[i]);
    }
    printf("\n");

    
    for(int i = 0; i < NumeroX; i++){
        Array3[i] = Array1[i] + Array2[i];      //Metodo per sommare due array
    }
    printf("Terzo array, la somma dei primi due:\n");
    for(int i = 0; i < NumeroX; i++){
        printf("%d ", Array3[i]);
    }
    printf("\n");

    free(Array1);
    free(Array2);
    free(Array3);
    return 0;
}