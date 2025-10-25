#include <stdio.h>
#include <stdlib.h>

int main() {
    char **words = malloc(3 * sizeof(char *));
    for(int i = 0; i < 3; i++){
        words[i] = malloc(10);
        fgets(words[i], 10, stdin);
        for(int j = 0; words[i][j] != '\0' && words[i][j] != '\n'; j++);
        int len = 0;
        while (words[i][len] != '\0' && words[i][len] != '\n') len++;
        for(int k = 0; k < len / 2; k++){
            char tmp = words[i][k];
            words[i][k] = words[i][len - k - 1];
            words[i][len - k - 1] = tmp;
        }
    }

    for(int i = 0; i < 3; i++){
        printf("%s", words[i]);
    }
    for (int i = 0; i < 3; i++){
        free(words[i]);
    }
    free(words);

    return 0;
}

/*
-Cosa viene stampato se l’utente inserisce le tre stringhe:
“uno”
“due”
“tre”
-Spiega il ruolo di words[i][len - k - 1].
-Cosa rappresenta words in memoria?
*/