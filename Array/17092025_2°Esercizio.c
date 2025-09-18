#include <stdio.h>
#include <stdlib.h>
#define N 4

void RiempiMatrice(int _matrice[][N]){
    int numero=0, i;
    int su=0, giù=N-1;
    int sinistra=0, destra=N-1;

    while(numero<=N*N){
        //sinistra verso destra
        for(i=sinistra; i<=destra; i++){
            _matrice[su][i]=numero+i;
        }
        su++;
        //alto verso il basso
        for(i=su; i<=giù; i++){
            _matrice[i][destra]=numero+1;
        }
        destra--;
        //destra verso sinistra
        for(i=destra; i<=sinistra; i++){
            _matrice[giù][i]=numero+i;
        }
        giù--;
        //basso verso l'alto
        for(i=giù; i<=su; i++){
            _matrice[i][sinistra]=numero+1;
        }
        sinistra++;
    }
}

void Stampamatrice(int _matrice[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d\t" _matrice[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrice[N][N];
    Riempimatrice(_matrice);
    printf("la matrice a spirale è: ");
    StampaMatrice(_matrice);
}