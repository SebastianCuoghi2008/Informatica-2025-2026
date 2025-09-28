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
    int dimensione=0;
    int scelta, N;

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
                for(int i=0; i<N; i++){
                    printf("inserisci il valore: ");
                    scanf("%d", &vettore[i]);
                }
            break;
            case 3:
                for(int i=0; i<N; i++){
                    printf("%d", vettore[i]);
                }
                printf("\n");
            break;
            case 4:

            
            break;
            case 5:
                printf("vettore da inserire: ");
                scanf("%d", &N);
                vettore=(int*)realloc(vettore, (dimensione+1)*sizeof(int));
                if(vettore==NULL){
                    printf("errore du allocazione\n");
                    return 1;
                }
                vettore[dimensione]=N;
                dimensione++;
                printf("numero aggiunto\n");

                if(*vettore% 2 == 0){
                    printf("il numero è pari");
                }
                else{
                    printf("%d, il numero è dispari", *vettore);
                }
            break;
            default:
                printf("scelta non autorizzata");
            break;
        }
    }while(scelta!=5);

    vettore = (int*)malloc(N * sizeof(int));
    vettore = (int*)realloc(vettore, (N+1)*sizeof(int));
}
