#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Esercizi.h"

#define MAX 100

int main()
{
    int scelta;
    char str[MAX];

    do{
        scelta = menu();
        fflush(stdin);

        switch(scelta){
            case 1:
                printf("Inserire una stringa: ");
                gets(str);
                break;
            case 0:
                break;
            default:
                printf("Valore non consentito!!");
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
    int sc=0;
    printf("0. Esci\n");
    printf("1. Leggere una stringa str\n");
    printf("Scelta -> ");
    scanf("%d",&sc);
    /*2 Contare il numero di consonanti e di vocali presenti in str\n
    3 Contare quante volte ogni lettera dell’alfabeto compare in str senza distinguere tra maiuscole e minuscole (str deve essere passata come parametro e la visualizzazione delle volte che le lettere compaiono deve essere effettuata all’interno della funzione)
    4 Raddoppiare le occorrenze delle vocali in str modificando str Es.: ciao → ciiaaoo (str passata come parametro deve poi essere visualizzata nel main)
    5 Cancellare le vocali presenti in una stringa modificando str Es.: ciao → c(str passata come parametro deve poi essere visualizzata nel main)
    6 Sostituire in str le occorrenze di un carattere preso in input con il carattere ‘&’ Es: str: pippo carattere in input: p str: &i&&0 (str passata come parametro deve poi essere visualizzata nel main)
    7 Visualizzare il codice ASCII di tutti i caratteri contenuti in str*/
    return sc;
}
