/*In una stringa dinamicamente creata inserisci la parola "lavastoviglie".
Stampa a schermo, la parola contenuta nei primi 4 caratteri,e la parola contenuta
nei primi 5 caratteri saltando i primi 2. Dovrebbe stampare "lava" e "vasto".*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

void clear_buffer(){
    int c;
    while ((c = getchar()) != '\n'){}
}
int CercaSottostringa(Stringa str, Stringa frase){ //funzione che cerca una sottostringa(presa da un vecchio essercizio)
	int i=0;
    int j=0;
    int trovata=0;
	
	while( str[i]!='\0' && frase[j]!='\0' && !trovata){
		while(str[i] == frase[j] &&  frase[j]!='\0'){
			i+=1; j+=1;
		}		
		if(frase[j] =='\0'){
            trovata=1;
        }
		else{
			trovata=0;		
	        i+=1;
            j=0;
        }
	}
	return trovata;
}

int main(){
    Stringa parola;
    Stringa str;
    int NumeroCaratteri=0;
    int lunghezza=0;

    str=(Stringa)malloc(sizeof(char)*20); //allocazione memoria per la stringa
    if(str == NULL){
        printf("Errore di memoria!\n");
        exit(1);
    }
    printf("Inserisci la parola o frase che è riferito alla stringa lavastoviglie: ");
    fgets(str,20,stdin);
    lunghezza=strlen(str);
    str[lunghezza-1]='\0';

    parola=(Stringa)malloc(sizeof(char)*20); //allocazione memoria per la parola o frase
    if(parola == NULL){
        printf("Errore di memoria!\n");
        exit(1);
    }
    printf("Inserisci la parola o frase che è riferito alla stringa lavastoviglie: ");
    fgets(parola,20,stdin);
    lunghezza=strlen(parola);
    parola[lunghezza-1]='\0';

    NumeroCaratteri = CercaSottostringa(str, parola); //operazione di ricerca sottostringa
	if(NumeroCaratteri){
		printf("\nParola trovata");
    }
	else{
		printf("\nParola non trovata");
    }
}