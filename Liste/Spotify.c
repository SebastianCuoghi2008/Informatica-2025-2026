/*Scrivere un programma in C che simuli una versione molto semplificata di Spotify.

Il programma deve gestire:
-Una lista lineare di canzoni disponibili.
-Una playlist che funziona come lista circolare.

Ogni canzone è memorizzata tramite una struttura che contiene:
titolo (stringa);
artista (stringa);
durata in secondi (int);
id univoco (assegnato automaticamente; ogni nuova canzone incrementa l’ID);
puntatore alla canzone successiva;

Funzioni da implementare per la lista delle canzoni:

-void stampa_canzone(Canzone *c)
Stampa a video tutti i campi della canzone.
-void set_canzone(Canzone *c)
Chiede all’utente i dati della canzone (tranne l’ID, che viene generato dal programma).
-Lista* crea_lista()
Crea e inizializza una lista lineare vuota di canzoni.
-void stampa_lista(Lista *l)
Stampa tutti gli elementi della lista delle canzoni disponibili.
-void inserisci_canzone_lista(Lista *l)
Crea una nuova canzone tramite set_canzone() e la inserisce in testa alla lista.
-void ricerca_canzone_artista(Lista *l, char* artista)
Cerca e stampa tutte le canzoni dell’artista indicato.
-void libera_memoria(Lista* l)
Libera correttamente la memoria di tutte le canzoni nella lista.

Funzioni da implementare per la playlist (lista circolare):
La playlist è realizzata usando una lista circolare: quando si arriva all’ultima canzone,
la successiva è di nuovo la prima.

-void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist)
Chiede all’utente un ID, Se esiste una canzone con quell’ID nella lista delle canzoni disponibili,
la aggiunge in fondo alla playlist circolare.
-void stampa_playlist(Lista* playlist)
Stampa tutti gli elementi della playlist, facendo attenzione alla natura circolare della lista.
-void cancella_canzone_playlist(Lista *playlist)
Chiede un ID all’utente e, se presente nella playlist, lo rimuove correttamente dalla lista circolare.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- Definizione struct necessarie ---- */
typedef struct Canzone{
    int id;
    char titolo[50];
    char artista[50];
    int durata;
    struct Canzone* Prossimo;
}Canzone;

typedef struct Lista{
    Canzone* Testa;
    int lunghezza;
}Lista;

/* ---- Variabile globale per gestire l'id univoco delle canzoni ---- */
int id_univoco = 0;

/* ---- Funzioni lista di canzoni disponibili ---- */
void stampa_canzone(Canzone *c);
void set_canzone(Canzone *c);
Lista* crea_lista();
void stampa_lista(Lista *l);
void inserisci_canzone_lista(Lista *l);
void ricerca_canzone_artista(Lista *l, char* artista);
void libera_memoria(Lista* l);

/* ---- Funzioni playlist (lista circolare) ---- */
void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist);
void stampa_playlist(Lista* playlist);
void cancella_canzone_playlist(Lista *playlist);

/* ---- MAIN ---- */
int main(){
    Lista* lista_canzoni = crea_lista();
    Lista* playlist = crea_lista();

    int Scelta;
    char artista[50];

    do{
        printf("\n===== SPOTIFY 0.0.0.1 =====\n");
        printf("1. Inserisci nuova canzone nella lista\n");
        printf("2. Stampa lista canzoni\n");
        printf("3. Cerca canzoni per artista\n");
        printf("4. Aggiungi canzone alla playlist\n");
        printf("5. Stampa playlist\n");
        printf("6. Cancella canzone dalla playlist\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &Scelta);
        getchar(); // pulisci buffer input

        switch(Scelta){
            case 1:
                inserisci_canzone_lista(lista_canzoni);
                break;
            case 2:
                stampa_lista(lista_canzoni);
                break;
            case 3:
                printf("Inserisci artista da cercare: ");
                fgets(artista, 50, stdin);
                ricerca_canzone_artista(lista_canzoni, artista);
                break;
            case 4:
                inserisci_canzone_playlist(lista_canzoni, playlist);
                break;
            case 5:
                stampa_playlist(playlist);
                break;
            case 6:
                cancella_canzone_playlist(playlist);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }

    }while(Scelta != 0);

    libera_memoria(lista_canzoni);
    libera_memoria(playlist);
    return 0;
}

/* =======================================================================================
   Qui sotto vanno implementate le funzioni.
======================================================================================= */
void stampa_canzone(Canzone *c){ 
    printf("ID: %d\n", c->id);
    printf("Titolo: %s", c->titolo);
    printf("Artista: %s", c->artista);
    printf("Durata: %d secondi\n", c->durata);
}

void set_canzone(Canzone *c){
    c->id = id_univoco++;
    printf("Inserisci titolo della canzone: ");
    fgets(c->titolo, 50, stdin);
    printf("Inserisci artista della canzone: ");
    fgets(c->artista, 50, stdin);
    printf("Inserisci durata della canzone (in secondi): ");
    scanf("%d", &c->durata);
    getchar(); 
}

Lista* crea_lista(){
    Lista* nuova_lista = (Lista*)malloc(sizeof(Lista));
    nuova_lista->Testa = NULL;
    nuova_lista->lunghezza = 0;
    return NULL; //modificare valore di ritorno
}

void stampa_lista(Lista *l){
    Canzone* Attuale = l->Testa;
    while(Attuale != NULL){
        stampa_canzone(Attuale);
        Attuale = Attuale->Prossimo;
    }
}

void inserisci_canzone_lista(Lista *l){
    Canzone* nuova_canzone = (Canzone*)malloc(sizeof(Canzone));
    set_canzone(nuova_canzone);
    nuova_canzone->Prossimo = l->Testa;
    l->Testa = nuova_canzone;
    l->lunghezza++;
}

void ricerca_canzone_artista(Lista *l, char* artista){
    Canzone* Attuale = l->Testa;
    int trovate = 0;
    while(Attuale != NULL){
        if(strcmp(Attuale->artista, artista) == 0){
            stampa_canzone(Attuale);
            trovate++;
        }
        Attuale = Attuale->Prossimo;
    }
    if(trovate == 0){
        printf("Nessuna canzone trovata per l'artista: %s\n", artista);
    }
}

void libera_memoria(Lista* l){
    Canzone* Attuale = l->Testa;
    Canzone* temp;
    while(Attuale != NULL){
        temp = Attuale;
        Attuale = Attuale->Prossimo;
        free(temp);
    }
    free(l);
}

void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist){
    int id_cercato;
    printf("Inserisci l'ID della canzone da aggiungere alla playlist: ");
    scanf("%d", &id_cercato);
    getchar(); 

    Canzone* Attuale = lista_canzoni->Testa;
    while(Attuale != NULL){
        if(Attuale->id == id_cercato){
            Canzone* nuova_canzone = (Canzone*)malloc(sizeof(Canzone));
            *nuova_canzone = *Attuale; 
            nuova_canzone->Prossimo = NULL;

            if(playlist->Testa == NULL){
                playlist->Testa = nuova_canzone;
                nuova_canzone->Prossimo = nuova_canzone; 
            }else{
                Canzone* temp = playlist->Testa;
                while(temp->Prossimo != playlist->Testa){
                    temp = temp->Prossimo;
                }
                temp->Prossimo = nuova_canzone;
                nuova_canzone->Prossimo = playlist->Testa; 
            }
            playlist->lunghezza++;
            printf("Canzone aggiunta alla playlist.\n");
            return;
        }
        Attuale = Attuale->Prossimo;
    }
    printf("Canzone con ID %d non trovata nella lista delle canzoni disponibili.\n", id_cercato);
}

void stampa_playlist(Lista* playlist){
    if(playlist->Testa == NULL){
        printf("La playlist è vuota.\n");
        return;
    }
    Canzone* Attuale = playlist->Testa;
    do{
        stampa_canzone(Attuale);
        Attuale = Attuale->Prossimo;
    }while (Attuale != playlist->Testa);
    
}

void cancella_canzone_playlist(Lista *playlist){
    if(playlist->Testa == NULL){
        printf("La playlist è vuota.\n");
        return;
    }
    int id_cercato;
    printf("Inserisci l'ID della canzone da rimuovere dalla playlist: ");
    scanf("%d", &id_cercato);
    getchar(); 

    Canzone* Attuale = playlist->Testa;
    Canzone* Precedente = NULL;

    do{
        if(Attuale->id == id_cercato){
            if(Precedente == NULL){ 
                if(Attuale->Prossimo == playlist->Testa){ 
                    free(Attuale);
                    playlist->Testa = NULL;
                }else{
                    Canzone* temp = playlist->Testa;
                    while (temp->Prossimo != playlist->Testa){
                        temp = temp->Prossimo;
                    }
                    temp->Prossimo = Attuale->Prossimo;
                    playlist->Testa = Attuale->Prossimo;
                    free(Attuale);
                }
            }else{
                Precedente->Prossimo = Attuale->Prossimo;
                free(Attuale);
            }
            playlist->lunghezza--;
            printf("Canzone rimossa dalla playlist.\n");
            return;
        }
        Precedente = Attuale;
        Attuale = Attuale->Prossimo;
    }while(Attuale != playlist->Testa);

    printf("Canzone con ID %d non trovata nella playlist.\n", id_cercato);
}

//Ho voluto cambiare alcune variabili inglesi in italiano come next in prossimo, current in attuale ecc... 
//così era più semplice per me da scrivere, leggere e assegnare
