/*Cerca di usare le funzioni sugli array che avete visto nelle slide per questo (malloc e compagnia).
Crea un array di numeri interi, di lunghezza 6, con tutti gli elementi a zero. Negli elementi di indice pari
mettici il numero 2. Nell'elemento di indice 3 mettici il numero 3. Stampa quindi l'array,
che dovrebbe risultare [ 2 , 0 , 2 , 3 , 2 , 0 ].
Crea poi un altro array vuoto, sempre di lunghezza 6, e copia ciascun elemento del primo array in questo nuovo array.
Stampa quindi l'array che dovrebbe essere uguale a quello di prima [ 2 , 0 , 2 , 3 , 2 , 0 ].
Infine, allarga il secondo array che hai fatto, da lungo 6 diventa lungo 12. Nei nuovi 6 elementi aggiunti
inseriscici di nuovo il primo array che abbiamo fatto. Dopodiché, il primo array dev'essere rimosso dalla memoria.
Infine, stampa l'array lungo 12, che dovrebbe essere [ 2 , 0 , 2 , 3 , 2 , 0 , 2 , 0 , 2 , 3 , 2 , 0 ].*/

#include <stdio.h> 
#include <stdlib.h>

void StampamentoArray(int *Array){
    for(int i=0; i<6; i++){
        Array[i] = 0;
        if(i % 2 == 0){
            Array[i] = 2;
        }
        if(i == 3){
            Array[i] = 3;
        }
        printf("%d\t", Array[i]);
    }
}
int main(){
    int *Array1;
    int *Array2;

    Array1 = (int*)malloc(sizeof(int)*6);
    StampamentoArray(Array1);
    printf("\n");

    Array2 = (int*)malloc(sizeof(int)*6);
    StampamentoArray(Array2);
    printf("\n");

    Array2 = (int*)realloc(Array2, sizeof(int)*12);
    for(int i=0; i<6; i++){
        Array2[i+6] = Array1[i];
    }
    for(int i=0; i<12; i++){
        printf("%d\t", Array2[i]);
    }
    free(Array1);

    return 0;
}