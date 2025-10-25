#include <stdio.h>
#include <stdlib.h>

int main() {
    char **parole = NULL;
    int np = 0;
    char *tmp = malloc(30);
    int i = 0;
    char c;

    while ((c = getchar()) != '\n'){
        if (c != ' '){
            tmp[i++] = c;
        }else{
            tmp[i] = '\0';
            parole = realloc(parole, (np + 1) * sizeof(char *));
            parole[np] = malloc(i + 1);
            for (int k = 0; k <= i; k++)
                parole[np][k] = tmp[k];
            np++;
            i = 0;
        }
    }
    tmp[i] = '\0';
    parole = realloc(parole, (np + 1) * sizeof(char *));
    parole[np] = malloc(i + 1);
    for(int k = 0; k <= i; k++){
        parole[np][k] = tmp[k];
    }
    np++;

    printf("Totale parole: %d\n", np);
    for(int k = 0; k < np; k++){
        printf("%s\n", parole[k]);
    }
    for(int k = 0; k < np; k++){
        free(parole[k]);
    }
    free(parole);
    free(tmp);
    return 0;
}

/*
-Cosa stampa se si inserisce “uno due tre”?
-Qual è il ruolo di tmp e perché viene ricopiata ogni volta in parole[np]?
*/