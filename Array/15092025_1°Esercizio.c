/*Data una matrice di valori scambiare gli elementi della diagonale principale con la diagonale secondaria.*/

#include <stdio.h>
#include <stdlib>
#include <time.h>
#define N 4

void CaricaMatrice(int (*_matrice)[N]){
    printf("Carichiamo la matrice: ");
    for (int i=0; i<N; i++){
        for(int j=0 j<N; j++){
            _matrice[i][j]=rand()%10 + 1;
        }
    }
}

void StampaMatrice(int (*_matrice)[]){
    for (int i=0; i<N; i++){
        for(int j=0 j<N; j++){
            printf("%d\t", _matrice[i][j]);
            printf("\n");
        }
        printf("\n");
    }    
}

void ScambioMatrice(int (*_matrice)[N]){
    int temp;

    for(int i=0; i<N; i++){
        temp=_matrice[i][j];
    }
}


int main(){
    srand(time(NULL));
    int matrice[N][N]={0};

    //caricamento matrice
    CaricaMatrice(matrice);

    //stampa matrice
    StampaMatrice(matrice);

    //scambio matrice
    ScambioMDiagonale(matrice);

    //stampa matrice
    StampaMatrice(matrice);
}    