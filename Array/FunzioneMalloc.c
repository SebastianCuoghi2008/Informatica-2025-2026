#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *array;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);

    // Alloco memoria per n interi
    array = (int *)malloc(n * sizeof(int));

    if (array == NULL) {
        printf("Errore di allocazione memoria!\n");
        return 1;
    }

    // Inserimento valori
    for (i = 0; i < n; i++) {
        printf("Inserisci valore %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Stampa valori
    printf("Hai inserito: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Libero la memoria
    free(array);

    return 0;
}
