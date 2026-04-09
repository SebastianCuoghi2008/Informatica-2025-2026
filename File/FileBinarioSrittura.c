/*Aprire/Creare un file binario: */

#include <stdio.h>

int main(){

    FILE *pFile = fopen("Numeri.bin", "wb");
    int Numeri[3] = {10, 20, 30};

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return 1;
    }

    fwrite(Numeri, sizeof(int), 3, pFile);

    fclose(pFile);
}