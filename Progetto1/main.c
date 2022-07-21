#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Esercizi.h"

#define MAX 50

int main()
{
    int scelta;
    int a[MAX];
    int lung;
    int somma,media;
    int max,min;
    int somP,somN;
    int pari[MAX], dispari[MAX];
    int speculare[10];

    int j,k;
    do{
        scelta=menu();
        fflush(stdin);

        switch(scelta){
            case 1:
                lung=caricaVet(a);
                break;
            case 2:
                stampaVet(a,lung);
                break;
            case 3:
                calcolaSommaMedia(a,lung,&media,&somma);
                printf("Somma: %d \t Media: %d",somma,media);
                break;
            case 4:
                cercaMinMax(a,lung,&max,&min);
                printf("Max: %d \t Min: %d", max, min);
                break;
            case 5:
                if(sommaPSommaN(a,lung,&somP,&somN)==1){
                    printf("E' maggiore la somma dei numeri positivi");
                }
                else{
                    printf("E' maggiore la somma dei numeri negativi");
                }
                break;
            case 6:
                pariDispari(a, lung, pari, dispari, &j, &k);
                stampaVetPD('P',pari,k);
                stampaVetPD('D',dispari,j);
                break;
            case 7:
                if(vettoreSpeculare(speculare)==0){ ///Il vettore se è di lunghezza pari non potrà mai essere speculare
                    printf("Il vettore non e' speculare!");
                }
                else{
                    printf("Il vettore e' speculare!");
                }
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 0:
                break;
            default:
                printf("Valore non disponibile");
                break;
        }
        fflush(stdin);
        getchar();
        fflush(stdin);
        system("@cls||clear");
    }while(scelta!=0);
    return 0;
}

int menu(){
    int sc;

    printf("0. Esci");
    printf("\n1. Caricamento di un vettore A");
    printf("\n2. Visualizzazione del vettore A");
    printf("\n3. Calcolo della somma e della media degli elementi del vettore A");
    printf("\n4. Ricerca del valore minimo e del valore massimo degli elementi contenuti nel vettore A");
    printf("\n5. Calcolo della somma degli elementi positivi e della somma degli elementi negativi del vettore A");
    printf("\n6. Creare i vettori PARI e DISPARI formati rispettivamente dagli elementipari e dispari presenti in A");
    printf("\n7. Verificare se un vettore di 10 numeri interi, preso in input all’interno della funzione, è speculare");
    /*printf("\n8. Ordinare il vettore A passato come parametro e visualizzarlo nel main.");
    printf("\n9. Cercare nel vettore A un numero preso in input nel main e passato come parametro (visualizzare nel main quante volte è contenuto nel vettore)");
    printf("\n10. Contare quanti valori del vettore A, presi in valore assoluto, sono primi (La funzione deve eseguire il conteggio su un vettore qualsiasi e restituisce quanti numeri primi sono contenuti)");*/

    printf("\nInserire un'opzione: ");
    scanf("%d",&sc);
    return sc;
}

void stampaVetPD(char vet,int a[],int n){
    int i;
    printf("\nStampa del vettore %c: ",vet);
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
}

