/*Scrivere un programma in C che gestisca un insieme di numeri interi usando un array dinamico.
Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l’array con realloc)
    2. Visualizzare tutti i numeri
    3. Cercare un numero specifico
    4. Ordinare i numeri in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int *numeri=NULL;  //array dinamico
    int dimensione=0;  //quanti elementi ci sono
    int scelta, N, i;
    int trovato=0;

    do{
        printf("\nscegli tramite menù: \n");
        printf("1) Aggiungere un numero (espandendo l’array con realloc)\n");
        printf("2) Visualizzare tutti i numeri\n");
        printf("3) Cercare un numero specifico\n");
        printf("4) Ordinare i numeri in ordine crescente\n");
        printf("5) Eliminare un numero scelto\n");
        printf("6) Uscire\n");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:{
                printf("numero da inserire: ");
                scanf("%d", &N);
                numeri=(int*)realloc(numeri, (dimensione+1)*sizeof(int));
                if(numeri==NULL){
                    printf("errore du allocazione\n");
                    return 1;
                }
                numeri[dimensione]=N;
                dimensione++;
                printf("numero aggiunto\n");
            }
            break;
            case 2:{
                printf("contenuto dell'array: ");
                if(dimensione==0){
                    printf("array vuoto");
                }
                else{
                    for(i=0; i<dimensione; i++){
                        printf("%d", numeri[i]);
                    }
                }              
            }
            break;
            case 3:{
                printf("numero da cercare: ");
                scanf("%d", &N);
                for(i=0; i<dimensione; i++){
                    if(numeri[i]==N){
                        trovato=1;
                        printf("numero trovato in posizione %d\n", i);
                    }
                }
                if(trovato==0){
                    printf("elemento non trovato\n");
                }
            }
            break;
            case 4:{

            }
            break;
            case 5:{

            }
            break;
            case 6:{

            }
            break;
            default:
                printf("scelta non autorizzata");
            break;
        }
    }while(scelta!=6);
}
