/*L'utente scrive due parole. Unisci le due parole in una stringa sola due volte,
prima Parola1+Parola2 e poi viceversa Parola2+Parola1. Stampa a schermo i due risultati,
poi verifica che entrambi contengano le due parole iniziali
(ovviamente dovrebbero contenerle).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* Stringa;

void clear_buffer(){
    int c;
    while ((c = getchar()) != '\n'){}
}
int calcola_lunghezza_stringa(Stringa str){
    int Dim=0;
    while(str[Dim]!='\0'){
        Dim++;
    } 
    return Dim;
}
Stringa concatena_stringhe(Stringa S1, Stringa S2){
    int Dim1 = calcola_lunghezza_stringa(S1);
    int Dim2 = calcola_lunghezza_stringa(S2);
    int Dim3 = Dim1 + Dim2 + 1;
    Stringa S3 = (Stringa)malloc(Dim3 * sizeof(char));

    if(S3 == NULL){
        printf("Errore di allocazione \n");
        exit(1);
    }
    int i = 0;
    for(i = 0; i < Dim1; i++){
        S3[i] = S1[i];  
    }
    i=i-1;

    for(int j = 0; j < Dim2; j++){
        i++;
        S3[i] = S2[j];
        
    }
    S3[++i] = '\0';
    return S3;
}
int main(){
    char Parola1[50];
    char Parola2[50];
    int lunghezza=0;
    Stringa Unione1;
    Stringa Unione2;
    Stringa Controllo;
   
    printf("Inserisci la prima parola a piacere: ");
    fgets(Parola1,50,stdin);
    lunghezza=strlen(Parola1);
    Parola1[lunghezza-1]='\0';

    printf("Inserisci la seconda parola a piacere: ");
    fgets(Parola2,50,stdin);
    lunghezza=strlen(Parola2);
    Parola2[lunghezza-1]='\0';

    Unione1=concatena_stringhe(Parola1, Parola2);
    printf("l'unione delle due parole è: %s\n",Unione1);

    Unione2=concatena_stringhe(Parola2, Parola1);
    printf("l'unione delle due parole è: %s\n",Unione2);

    Controllo=strstr(Unione1, Parola1);
    if(Controllo == NULL){
        printf("la prima parola non è dentro la prima unione");
    }
    else{
        printf("la prima parola è dentro la prima unione");
    }

    free(Unione1);
    free(Unione2); 
    return 0;
}