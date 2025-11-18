/* Eliminare gli spazi da una stringa */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char* Stringa;

void eliminaSpazi(Stringa S){
	int i,j;
	for(i=0; S[i]!='\0'; i++){
		if(S[i]==' '){
			for(j=i; S[j] != '\0'; j++){
				S[j]=S[j+1];
			}			
			S[j]='\0';
		}
	}
}


int main(){
	Stringa S = (Stringa)malloc(50 * sizeof(char));
	if (S == NULL) return 1;
	
	printf("Inserisci una stringa: ");
	fgets(S, 50, stdin);
	eliminaSpazi(S);
	printf("\n%s", S);		
}

