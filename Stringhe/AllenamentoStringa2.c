/*In una stringa creata dinamicamente carica "supercalifragilistichespiralodoso".
Stampa a schermo quanto è lunga questa parola. Dopodiché, verifica se le parole "che",
"chi", "di", "a", "da", "su" sono all'interno della stringa iniziale,
stampando a schermo quali ci sono e quali no.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

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

int main(){
    Stringa parola;

    parola=(Stringa)malloc(sizeof(char)*40);
    if(parola == NULL){
        printf("Errore di memoria!\n");
        exit(1);
    }
    strcpy(parola, "supercalifragilistichespiralodoso");
    printf("La parola è: %s\n", parola);
    printf("La lunghezza della parola è: %zu caratteri\n", strlen(parola));
    
    printf("la parola CHE in questa stringa appare %d volte.\n",conta_occorrenze(parola, 'che'));
    printf("la parola DI in questa stringa appare %d volte.\n",conta_occorrenze(parola, 'di'));
    printf("la parola A in questa stringa appare %d volte.\n",conta_occorrenze(parola, 'a'));
    printf("la parola DA in questa stringa appare %d volte.\n",conta_occorrenze(parola, 'da'));
    printf("la parola SU in questa stringa appare %d volte.\n",conta_occorrenze(parola, 'su'));

    free(parola);
    return 0;
}


