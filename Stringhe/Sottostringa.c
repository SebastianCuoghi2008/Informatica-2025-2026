/*Data una stringa, trovare un sottostringa senza utilizzare la libreria string.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

void compatta(Stringa buffer, int len){

        if(len>0 && buffer[len-1]=='\n'){
            buffer[len-1] = '\0';
            len--;
        }
}

int cerca(Stringa _str, Stringa _word){
	int i=0, j=0, trovata=0;
	
	while( _str[i]!='\0' && _word[j]!='\0' && !trovata){
		while( _str[i] == _word[j] &&  _word[j]!='\0'){
			i+=1; j+=1;
		}
		
		if ( _word[j] =='\0')
			trovata=1;
		else
			trovata=0;		
		i+=1; j=0;
	}
	
	return trovata;
}
int main(){
	int N, len;
	Stringa S = (Stringa)malloc (50 * sizeof(char));
	if (S == NULL) return 1;
	printf("Inserisci una parola o frase: ");
	fgets(S, 50, stdin); 
	len = strlen(S);
	compatta(S,len);
	//inserisci la parola
	Stringa parola = (Stringa)malloc(50 * sizeof(char));
	if (parola == NULL) return 1;
	printf("Inserisci una parola o frase: ");
	fgets(parola, 50, stdin);
	len = strlen(parola);
	compatta(parola,len);
	
	N = cerca (S, parola);
	if(N){
		printf("\nParola trovata");
    }
	else{
		printf("\nParola non trovata");
    }
}