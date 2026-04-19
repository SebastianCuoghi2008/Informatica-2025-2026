/*Aggiunta a un file binario: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *pFile = NULL;
    int Numeri[10];

    pFile = fopen("Numeri-A.bin", "ab");

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return 1;
    }
    else{
        printf("File aperto con successo!\n");
    }

    for(int i = 0; i < 10; i++){
        Numeri[i] = (i + 1) * 10;
    }

    fwrite(Numeri, sizeof(int), 10, pFile);

    fclose(pFile);
    pFile = NULL;

    return 0;
}
