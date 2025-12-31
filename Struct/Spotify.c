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