/*Date due strignhe, scrivere la stringa in alternat.
esempio:
CIAO
CASA
CCIAASOA*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char* Stringa;

void compatta(Stringa buffer, int len){
    if(len>0 && buffer[len-1]=='\n'){
        buffer[len-1] = '\0';
        len--;
    }
}
void alterna(Stringa s1, Stringa s2, Stringa s3){
	int i,j=0;
		
	for(i=0; i<strlen(s1) || i<strlen(s2); i++){
    	if(i<strlen(s1)){
    		s3[j]=s1[i];
    		j+=1;
    	}
    	if(i<strlen(s2)){
    		s3[j]=s2[i];
    		j+=1;
    	}
    }
    s3[j]='\0';
}

int main(){
    
    int i, j=0, len;
    Stringa s1 = (Stringa)malloc (50 * sizeof(char)); //prima stringa
	if (s1 == NULL) return 1;
	printf("Inserisci una stringa: ");
	fgets(s1, 50, stdin);
    len = strlen(s1);
	compatta(s1,len);
	
	Stringa s2 = (Stringa)malloc (50 * sizeof(char)); //seconda stringa
	if (s2 == NULL) return 1;
	printf("Inserisci una stringa: ");
	fgets(s2, 50, stdin);
    len = strlen(s2);
	compatta(s2,len);
	
	Stringa s3 = (Stringa)malloc (50 * sizeof(char)); //terza stringa
	if (s3 == NULL) return 1;
    alterna(s1,s2,s3);
  	
    printf("La parola alternata e\' %s",s3);
    return 0;
}