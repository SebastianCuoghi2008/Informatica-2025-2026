#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n = 3, i;

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) return 1;

    for (i = 0; i < n; i++) array[i] = i + 1;

    printf("Array iniziale: ");
    for (i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    // Aumento la dimensione dell’array a 5
    n = 5;
    array = (int *)realloc(array, n * sizeof(int));
    if (array == NULL) return 1;

    array[3] = 100;
    array[4] = 200;

    printf("Array dopo realloc: ");
    for (i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    free(array);
    return 0;
}

