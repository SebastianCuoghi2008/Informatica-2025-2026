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
#include <libArray.c>
#define N 4

int main(){
    int scelta;
    int numero[N];
    
    do{
        printf("scegli tramite menù: ");
        printf("1) Aggiungere un numero (espandendo l’array con realloc)");
        printf("2) Visualizzare tutti i numeri");
        printf("3) Cercare un numero specifico");
        printf("4) Ordinare i numeri in ordine crescente");
        printf("5) Eliminare un numero scelto");
        printf("6) Uscire");

        switch(scelta){
            case 1:{
                stampaVettore(numero, N);
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                riempiVettoreOrdinatoCasuale(numero, N);
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            default:
            break;
        }
    }while(scelta!=0);
}
void stampaVettore(int vettore[], int dim, char sep){
    for(int i=0; i<dim; i++){
        printf("%d%c", vettore[i], sep);
    }
    printf("\n");
}

void riempiVettoreOrdinatoCasuale(int vett[], int dim, int minimo, int massimo) {
    
    int num, pos;
    vett[0] = rand()%(massimo-minimo+1)+minimo;
    for(int i=1; i<dim; i++){
        num = rand()%(massimo-minimo+1)+minimo;
        pos = trovaPosizione(vett, i, num); 
        shiftDx(vett, i, pos);
        vett[pos] = num;
    }
}