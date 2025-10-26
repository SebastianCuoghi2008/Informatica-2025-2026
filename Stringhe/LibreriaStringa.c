#include "LibreriaStringa.h"
#include <stdio.h>
#include <stdlib.h>

void clear_buffer(){
    int c;
    while ((c = getchar()) != '\n'){}
}

Stringa crea_stringa_dimensionata(int N){
    Stringa c = (Stringa)malloc(N * sizeof(char));
    if(c == NULL){
        printf("Errore di allocazione!\n");
        exit(1);
    }
    fgets(c, N, stdin); //n=5 "ciao oggi è proprio divertente"
    clear_buffer();
    return c;
}

Stringa crea_stringa_dinamica(char terminatore){
    Stringa str = NULL;
    int Dim = 0;       // lunghezza corrente della stringa
    int capacità = 0;   // spazio totale allocato
    char c;

    printf("Inserisci una stringa (termina con %c):\n", terminatore);

    while ((c = getchar()) != terminatore && c != EOF) {  // finchè l'utente non inserisce il carattere terminatore o non si raggiunge la fine di un file
        if (Dim + 1 >= capacità) {
            capacità += 10; // rialloco a blocchi di 10
            str = (Stringa) realloc(str, capacità * sizeof(char));
            if (str == NULL) {
                printf("Errore di allocazione\n");
                exit(1);
            }
        }
        str[Dim++] = c;
    }
    str[Dim] = '\0'; // aggiungo terminatore della stringa

    return str;
}

int calcola_lunghezza_stringa(Stringa s){
    int Dim=0;
    while(s[Dim]!='\0'){
        Dim++;
    } 
    return Dim;
}
Stringa concatena_stringhe(Stringa S1, Stringa S2, char separatore){
    int Dim1 = calcola_lunghezza_stringa(S1);
    int Dim2 = calcola_lunghezza_stringa(S2);
    int Dim3 = Dim1 + Dim2 + 2;
    Stringa S3 = (Stringa)malloc(Dim3 * sizeof(char));

    if(S3 == NULL){
        printf("Errore di allocazione \n");
        exit(1);
    }
    int i = 0;
    for(i = 0; i < Dim1; i++){
      S3[i] = S1[i];  
    }
    S3[i] = separatore;

    for(int j = 0; j < Dim2; j++){
        i++;
        S3[i] = S2[j];
        
    }
    S3[++i] = '\0';
    return S3;
}

int conta_occorrenze(Stringa S1, char carattere){
    int Dim = 0;
    int cnt_carattere = 0;
    while(S1[Dim] != '\0'){
        if(S1[Dim] == carattere){
            cnt_carattere++;
        }
        Dim++;
    }
    return cnt_carattere;

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

char** dividi_stringa(Stringa S1, char separatore){
    char** risultato = NULL;
    int lunghezza_totale = calcola_lunghezza_stringa(S1);
    int lunghezza1 = 0, lunghezza2 = 0;
    int i = 0;
    risultato = (char**) malloc(2 * sizeof(Stringa));
    //S1 "ciao,belli"\0
    while(S1[i]!=separatore){
        i++;
    }
    lunghezza1 = i+1; //5
    lunghezza2 = lunghezza_totale - lunghezza1;
    risultato[0] = (Stringa) malloc(lunghezza1 * sizeof(char));
    risultato[1] = (Stringa) malloc(lunghezza2 * sizeof(char));

    for(int j = 0; j < lunghezza1-1; j++){
        risultato[0][j] = S1[j];
    }
    risultato[0][lunghezza1] = '\0';
    int cnt = 0;
    for(int j=lunghezza1; j<lunghezza_totale; j++){
        risultato[1][cnt] = S1[j];
        cnt++;
    }
    risultato[1][lunghezza2] = '\0';

    return risultato;
}

Stringa crea_copia(Stringa S1){
    Stringa S2;
    int lung=calcola_lunghezza_stringa(S1)+1;
    S2=(Stringa)malloc(lung *sizeof(char));
    for(int i=0; i<lung; i++){
        S2[i]=S1[i];
    }
    return S2;
}

int equivalenti(Stringa S1, Stringa S2){
    int lung1=calcola_lunghezza_stringa(S1)+1;
    int lung2=calcola_lunghezza_stringa(S2)+1;
    if(lung1==lung2){
        for(int i=0; i<lung1; i++){
            if(S1[i]!=S2[i]){
                return 0;
            }
        }return 1;
    }else return 0;
}

void maiuscole_minuscole(Stringa S1, int maiusc_to_minusc){
    int i=0;
    int diff = 'a' - 'A'; //32
    if(maiusc_to_minusc){
        while(S1[i] != '\0'){
            if(S1[i]>='A' && S1[i] <= 'Z'){
                S1[i]+=diff;
            }
            i++;
        }
    }else{
        while(S1[i] != '\0'){
            if(S1[i]>='a' && S1[i] <= 'z'){
                S1[i]-=diff;
            }
            i++;
        }      
    }
}