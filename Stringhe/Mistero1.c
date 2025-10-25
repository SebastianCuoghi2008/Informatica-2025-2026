#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Qual è l'output se in input fossero passati i parametri
//s = "conoscere il c mi farà diventare ricco"
//c = 'c'

char* mistero_1(char *s, char c){    
    int len = strlen(s);
    char *risultato = malloc((len + 1) * 
    sizeof(char));
    if (risultato == NULL){
        return NULL;
    }
    char *str1 = s;
    char *str2 = risultato;
    int idx1 = 0, idx2 = 0;
    while(str1[idx1] != '\0'){
        if(str1[idx1] != c){   
        str2[idx2] = str1[idx1];  
        idx2++;
        }
        idx1++;
    }
    str2[idx2] = '\0';
    risultato = realloc(risultato, strlen(str2) + 1 * sizeof(char)); 
    printf("%s", risultato);
    return risultato;
}

//"i l  c  m i  f a r à  r i c c o "
//c = 'c'
