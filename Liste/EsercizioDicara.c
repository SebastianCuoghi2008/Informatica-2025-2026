#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

typedef struct {
    Nodo* testa;
    int lunghezza;
} Lista;

Lista* creaLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->testa = NULL;
    lista->lunghezza = 0;
    return lista;
}

void inserisciFine(Lista* lista, int valore) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->dato = valore;
    nuovoNodo->next = NULL;
    
    if (lista->testa == NULL) {
        lista->testa = nuovoNodo;
    } else {
        Nodo* current = lista->testa;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nuovoNodo;
    }
    lista->lunghezza++;
}

void stampaLista(Lista* lista) {
    Nodo* current = lista->testa;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->dato);
        current = current->next;
    }
    printf("NULL\n");
}

void liberaLista(Lista* lista) {
    Nodo* current = lista->testa;
    while (current != NULL) {
        Nodo* temp = current;
        current = current->next;
        free(temp);
    }
    free(lista);
}

int main() {
    Lista* lista = creaLista();
    
    inserisciFine(lista, 10);
    inserisciFine(lista, 20);
    inserisciFine(lista, 30);
    
    stampaLista(lista);
    
    liberaLista(lista);
    return 0;
}