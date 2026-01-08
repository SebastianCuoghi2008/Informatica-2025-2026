/*Classi studenti:
Cognome, Nome, classe, matricola
per ogni studente dotato di matricola, abbiamo le informazioni riguardante gli esami e il livello raggiunto:
1) Ricercare lo studente con più certificazioni.
*/

typedef struct{
    char Cognome[20];
    char Nome[20];
    char Classe[3];
    int Matricola;      //1000 - 99999
}Studente;

typedef struct{
    int Matricola;
    struct esame{
        char corso[20];
        int livello;    //(1 - 3)
    };
}Certificazione;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InserimentoStudenti(Studente *Registro, int N){
    for(int i=0; i<N; i++){
        printf("inserisci il cognome dello studente: ");
        scanf("%s", Registro[i].Cognome);
        fflush(stdin);
        printf("inserisci il nome dello studente: ");
        scanf("%s", Registro[i].Nome);
        fflush(stdin);
        printf("inserisci la classe dello studente: ");
        scanf("%s", Registro[i].Classe);
        fflush(stdin);
        do{
            printf("inserisci la matricola dello studente: ");
            scanf("%d", &Registro[i].Matricola);
            fflush(stdin);    
        }while(Registro[i].Matricola < 1000 || Registro[i].Matricola > 99999);
    }
}

void StampamentoStudenti(Studente *Registro, int N){
    for(int i=0; i<N; i++){
        printf("Cognome studente: %s\n", Registro[i].Cognome);
        printf("Nome studente: %s\n", Registro[i].Nome);
        printf("Classe studente: %s\n", Registro[i].Classe);
        printf("Matricola studente: %d\n", Registro[i].Matricola);
    }
}

void Ricerca_Studente_Certificazioni(Studente *Registro, Certificazione *Certificati, int N_Studenti, int N_Certificati){
    int max_certificati = 0;
    int matricola_max = -1;

    for(int i=0; i<N_Studenti; i++){
        int count = 0;
        for(int j=0; j<N_Certificati; j++){
            if(Registro[i].Matricola == Certificati[j].Matricola){
                count++;
            }
        }
        if(count > max_certificati){
            max_certificati = count;
            matricola_max = Registro[i].Matricola;
        }
    }

    if(matricola_max != -1){
        printf("Lo studente con più certificazioni ha la matricola: %d con %d certificazioni.\n", matricola_max, max_certificati);
    } else {
        printf("Nessuno studente ha certificazioni.\n");
    }
}

int main(){
    Studente *Registro;
    int N;

    do{
        printf("inserisci il numero degli studenti(max 50): ");
        scanf("%d", &N);
    }while(N<0 || N>50);

    Registro=(Studente*)malloc(N*sizeof(Studente));
    if(Registro == NULL){
        printf("Errore durante l'allocazione");
        exit(1);
    }

    InserimentoStudenti(Registro, N);
    StampamentoStudenti(Registro, N);
    Ricerca_Studente_Certificazioni(Registro, NULL, N, 0);

    free(Registro);
    return 0;
}