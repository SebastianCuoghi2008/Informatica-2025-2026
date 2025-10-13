/*Scrivi un programma in C che permetta di memorizzare il numero
  di capelli dei clienti di un parrucchiere*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *capelli;
    int N;

    printf("quanti clienti ci sono oggi? ");
    scanf("%d", &N);

    capelli=(int*)malloc(N * sizeof(int));

    if(capelli==NULL){
        printf("troppi clienti!");
        return 1;
    }
    free(capelli);
}