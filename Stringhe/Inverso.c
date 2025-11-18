/*Data una stringa, scriverla all'inverso scambiando gli elementi*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Inverso(char* Stringa, int Lung){
    char temp;
    for(int i=0; i<Lung/2; i++){
        temp=Stringa[i];
        Stringa[i]=Stringa[Lung-i-2];
        Stringa[Lung-i-2]=temp;
    }
}

int main(){
    char* Stringa=(char*)malloc(50*sizeof(char));
    int Lung;
    if (Stringa==NULL)
    {
        printf("Errore di allocazione");
        return 1; 
    }
    
    printf("inserisci una stringa: ");
    fgets(Stringa, 50, stdin);
    Inverso(Stringa, strlen(Stringa));
    printf("La stringa inversa e': %s", Stringa);
    free(Stringa);
    return 0;
}
