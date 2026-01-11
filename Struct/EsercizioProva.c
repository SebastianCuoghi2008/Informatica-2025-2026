#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    float PI;
    float Prezzo;
    float X;
    struct Numeri_Reali* Next;
}Numeri_Reali;

typedef struct Lista{
    Numeri_Reali* testa;
    int lunghezza;
}Lista;

Lista* Crea_Lista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->testa = NULL;
    lista->lunghezza = 0;
    return lista;
}

Lista* Inserimento_inizio(Lista* lista, float Valore){
    Numeri_Reali* Nuovo_Float = (Numeri_Reali*)malloc(sizeof(Numeri_Reali));
    Nuovo_Float->PI = Valore;
    Nuovo_Float->Prezzo = Valore;
    Nuovo_Float->X = Valore;
    Nuovo_Float->Next = lista->testa;
    lista->testa = Nuovo_Float;
    lista->lunghezza++;
}

int Ricerca_prezzo(Lista* lista, float Valore){
    Numeri_Reali* current = lista->testa;
    int posizione = 0;
    
    while(current != NULL){
        if (current->Prezzo == Valore){
            return posizione;
        }
        current = current->Next;
        posizione++;
    }
    return -1;  
}

int main(){
    Lista* lista = Crea_Lista();
    Inserimento_inizio(lista, 3.14);
    Inserimento_inizio(lista, 2.71);
    Inserimento_inizio(lista, 1.61);
    Printf("%f\n", lista->testa->PI);
    Printf("%f\n", lista->testa->Prezzo);
    Printf("%f\n", lista->testa->X);
    
    float valore_da_cercare = 2.71;
    int posizione = Ricerca_prezzo(lista, valore_da_cercare);
    
    if (posizione != -1){
        printf("Valore %.2f trovato alla posizione %d nella lista.\n", valore_da_cercare, posizione);
    } else {
        printf("Valore %.2f non trovato nella lista.\n", valore_da_cercare);
    }
    
    return 0;
}