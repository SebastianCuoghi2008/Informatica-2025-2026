/*Data una stringa, trovare un sottostringa senza utilizzare la libreria string.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* Stringa;

int calcola_lunghezza_stringa(Stringa S){
    int Dim=0;
    while(S[Dim]!='\0'){
        Dim++;
    } 
    return Dim;
}
int stringa_in_stringa(Stringa S1, Stringa S2){
    int Dim1 = calcola_lunghezza_stringa(S1);
    int Dim2 = calcola_lunghezza_stringa(S2);
    int flag = 0;
    int cnt = 0;

    for(int i = 0; i <= Dim1-Dim2+1; i++){
        if(S1[i] == S2[0]){
            flag = 1;
            for(int j = 1; j < Dim2; j++){
                if(S1[i+j] != S2[j]){
                flag = 0;
                break;
                }
            }
            cnt += flag;
        }
    }
    return cnt;
}

int main(){
    Stringa S1 = (Stringa)malloc(50 * sizeof(char)); //prima stringa
    if (S1 == NULL) return 1;
    printf("Inserisci la prima stringa: ");
    fgets(S1, 50, stdin);
    
    Stringa S2 = (Stringa)malloc(50 * sizeof(char)); //seconda stringa
    if (S2 == NULL) return 1;
    printf("Inserisci la seconda stringa: ");
    fgets(S2, 50, stdin);
    
    printf("La stringa comapre %d volte in %s", stringa_in_stringa(S1, S2), S1);
}