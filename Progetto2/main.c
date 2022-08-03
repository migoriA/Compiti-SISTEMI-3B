#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Esercizi.h"

#define MAX 100

int main()
{
    int scelta;
    int c,v;
    char str[MAX];
    char car=' ';

    do{
        scelta = menu();
        fflush(stdin);

        switch(scelta){
            case 1:
                printf("Inserire una stringa: ");
                gets(str);
                break;
            case 2:
                contaConsonantiVocali(str, &c, &v);
                printf("Le consonanti sono: %d\nLe vocali sono: %d",c,v);
                break;
            case 3:
                contaLettere(str);
                break;
            case 4:
                raddoppiaVocali(str);
                printf("Frase modificata -> %s",str);
                break;
            case 5:
                rimuoviVocali(str);
                printf("Frase modificata -> %s",str);
                break;
            case 6:
                printf("Inserire il carattere da sostituire: ");
                scanf("%c",&car);
                sostituireCarattereInInput(str,car);
                printf("Frase modificata -> %s",str);
                break;
            case 7:
                printf("Codice ASCII -> ");
                stampaCodiceASCII(str);
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
    printf("2. Contare il numero di consonanti e di vocali presenti in str\n");
    printf("3. Contare quante volte ogni lettera dell’alfabeto compare in str senza distinguere tra maiuscole e minuscole\n");
    printf("4. Raddoppiare le occorrenze delle vocali in str modificando str Es.: ciao → ciiaaoo\n");
    printf("5. Cancellare le vocali presenti in una stringa modificando str Es.: ciao → c\n");
    printf("6. Sostituire in str le occorrenze di un carattere preso in input con il carattere ‘&'\n");
    printf("7. Visualizzare il codice ASCII di tutti i caratteri contenuti in str\n");
    printf("Scelta -> ");
    scanf("%d",&sc);
    return sc;
}
