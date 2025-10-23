/*Verificare se una stringa è palindroma
    Es: anna è palindroma
    Es: ciao non è palindroma 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

int Lunghezza(Stringa S){
    int i=0;

    while(S[i] != '\0'){
        i++;
    }
    return i-1;
}

int _Palindroma(Stringa S, int Dim){
    int flag=0;
    int i, j;

    for(int i=0, j=Dim-1; i<Dim/2; i++, j--){
        if(S[i]!=S[j]){
            flag=1;
        }
    }
    return flag;
}
    
int main(){
    int Dim=0;
    int Palindroma=0;

    Stringa S=(Stringa)malloc(50*sizeof(char));
    if(S==NULL){
        printf("Errore di allocazione di memoria\n");
        return 1;
    }
    printf("inserisci una stringa: ");
    fgets(S, 50, stdin);
    printf("\n%s", S);

    Dim=Lunghezza(S);
    printf("\n%d", Dim);

    Palindroma=_Palindroma(S, Dim);
    if(Palindroma==1){
        printf("\nLa frase non è palindroma:");
    }else{
        printf("\nLa frase è palindroma");
    }
}