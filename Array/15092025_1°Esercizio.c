/*Data una matrice di valori scambiare gli elementi della diagonale principale con la diagonale secondaria.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

void caricaMatrice(int (*_matrice)[N]){
    printf("Carichiamo la matrice: ");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            _matrice[i][j]=rand()%30 +1;
        }
    }
}

void stampaMatrice(int (*_matrice)[N]){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d\t", _matrice[i][j]);
        }
        printf("\n");
    }       
}

void scambioDiagonale(int (*_matrice)[N]){
    int tmp;

    for(int i=0;i<N; i++){
        tmp=_matrice[i][i];
        _matrice[i][i]=_matrice[i][N-i-1];
        _matrice[i][N-i-1]=tmp;
    }
}

int main(){
    int matrice[N][N]={0};
    srand(time(NULL));

    //cariamento matrice
    caricaMatrice(matrice);
    //stampa matrice
    stampaMatrice(matrice);
    //scambio diagonali
    scambioDiagonale(matrice);
    //stampa matrice
    stampaMatrice(matrice);
}