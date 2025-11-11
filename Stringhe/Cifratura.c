/*Data una stringa iniziale e il fattore di cifratura, creare la stringa cifrata*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int FattoreCifratura;
    char Stringa[50];

    printf("inserisci la stringa perfavore: ");
    fgets(Stringa, 50, stdin);
    printf("inserisci il codice di cifratura perfavore:");
    scanf("%d", &FattoreCifratura);

    for(int i=0; Stringa[i]!='\n'; i++){
        if(Stringa[i]+FattoreCifratura>122 ||( Stringa[i]>='A' && Stringa[i]<='Z' && Stringa[i]+FattoreCifratura>90)){ //&& Stringa[i]+FattoreCifratura<97
            Stringa[i]-=26;
        }
        Stringa[i]+=FattoreCifratura;
    }
    printf("la stringa cifrata è: %s\n", Stringa);
}