/* Scrivere un linguaggio C che:
    1. Allochi un array iniziale di numeri;
    2. Inserimento dei valori;
    3. Stampa array;
    4. Calcoli la somma degli elementi multipli di 3;
    5. Creare un nuovo array contenente solo valori dispari;
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vettore=NULL;
    int N=0;
    int scelta;

    do{
        printf("\n--- MENU ---\n");
        printf("Allocare un array iniziale di numeri\n");
        printf("Inserimento dei valori\n");
        printf("Stampa array\n");
        printf("Calcoli la somma degli elementi multipli di 3\n");
        printf("Creare un nuovo array contenente solo valori dispari\n");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:

            
            break;
            case 2:

            
            break;
            case 3:

            
            break;
            case 4:

            
            break;
            case 5:

            
            break;
            default:
                printf("scelta non autorizzata");
            break;
        }
    }while(scelta!=5);

    vettore = (int*)malloc(N * sizeof(int));
    vettore = (int*)realloc(vettore, (N+1)*sizeof(int));
}
