/*Lettura di un file binario: */

#include <stdio.h>

int main(){

    FILE *pFile = fopen("Numeri.bin", "rb");
    int Numeri[3];

    if(pFile == NULL){
        printf("Errore nella apertura del file\n");
        return 1;
    }

    fread(Numeri, sizeof(int), 3, pFile);

    for(int i = 0; i < 3; i++){
        printf("%d\n", Numeri[i]);
    }
    
    fclose(pFile);
}