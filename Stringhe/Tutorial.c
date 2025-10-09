#include <stdio.h>
#include <stdlib.h>

typedef char* Stringa;

int main() {
    Stringa str = NULL;
    int Dimensione = 0;     // lunghezza corrente
    int Capacità = 0;   // spazio allocato
    char c;

    printf("Inserisci una stringa (termina con invio):\n");

    while ((c = getchar()) != '\n' && c != EOF) {
        if (Dimensione + 1 >= Capacità) {
            Capacità += 10; // rialloco a blocchi di 10
            str = (Stringa) realloc(str, Capacità * sizeof(char));
            if (str == NULL) {
                printf("Errore di allocazione\n");
                return 1;
            }
        }
        str[Dimensione++] = c;
    }
    str[Dimensione] = '\0'; // aggiungo terminatore

    printf("Hai inserito: %s\n", str);

    free(str);
    return 0;
}