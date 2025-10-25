
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s = malloc(10);
    fgets(s, 10, stdin);

    char *p = s;
    while (*(p + 1) != '\0' && *(p + 1) != '\n') {
        if(*p > *(p + 1)){
            char tmp = *p;
            *p = *(p + 1);
            *(p + 1) = tmp;
        }
        p++;
    }

    printf("%s", s);
    free(s);
    return 0;
}

/*
-Se si inserisce dbca, cosa stampa?
-Qual è la logica del confronto if (*p > *(p + 1))?
-Perché p viene incrementato a ogni iterazione?
*/
