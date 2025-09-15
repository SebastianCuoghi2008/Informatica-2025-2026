/*Data una matrice di valori scambiare gli elementi della diagonale principale con la diagonale secondaria.*/

#include <stdio.h>
#include "libArray.c"
#define Righe 10
#define Colonne 8

int main(){
    srand(time(NULL));
    int mat[Righe][Colonne];

    for(int i=0; i<Righe; i++){
        for(int j=0; j<Colonne; j++){
            mat[i][j] = i;
        }
    }
    for(int i=0; i<Righe; i++){
        for(int j=0; j<Colonne; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    riempiVettoreCasuale(mat[0], Colonne, 0, 20);
    for(int i=0; i<Righe; i++){
        for(int j=0; j<Colonne; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<Righe; i++){
        riempiVettoreCasuale(mat[i], Colonne, 0, 100);
        stampaVettore(mat[i], Colonne, '\t');
        bubbleSort(mat[i], Colonne);
    }
    printf("\n\n\n");
    for(int i=0; i<Righe; i++){
        for(int j=0; j<Colonne; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}