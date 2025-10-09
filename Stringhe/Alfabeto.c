/*Scrivi un programma in C che chieda all'utente un numero intero N compreso tra
 1 e 26, quindi crea una stringa composta da tutte le prime N lettere 
 dell'alfabeto.
 Es: se l'utente inserisce 4, verrà creata la stringa "abcd".*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    char lettera='a';
    char* str=NULL;

    do{
        printf("inserisci un numero: ");
        scanf("%d",&N);
    }while(N<=0||N>26);

    str=(char*)malloc((N+1)*sizeof(char));
    for(int i=0; i<N;i++){
        str[i]=lettera++;
    }
    str[N]='\0';
    printf("%s", str);
}