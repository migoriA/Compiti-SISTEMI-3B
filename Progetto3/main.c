#include <stdio.h>
#include <stdlib.h>


#include "Esercizi.h"

int main()
{
    int scelta;
    char months[12][10]={"gennaio","febbraio","marzo","aprile","maggio","giugno","luglio","agosto","settembre","ottobre","novembre","dicembre"};
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int month,month2;
    int year,year2;
    int day,day2;
    int nDays;

    do{
        scelta=menu();
        fflush(stdin);
        switch(scelta){
            case 0:
                break;
            case 1:
                printf("Mese: ");
                scanf("%d",&month);
                printf("Anno: ");
                scanf("%d",&year);
                if(month>0 && month<=12 && year>1900 && year<=2022){
                    printMonth(month,year,months,days);
                }
                else{
                    printf("Inserisci un mese o un anno corretto");
                }
                break;
            case 2:
                printf("Anno: ");
                scanf("%d",&year);
                if(year>=1900 && year<=2022)
                    printYear(year,months,days);
                else
                    printf("Inserisci un'anno corretto\n");
                break;
            case 3:
                printf("Anno: ");
                scanf("%d",&year);
                printf("Mese: ");
                scanf("%d",&month);
                printf("Giorno: ");
                scanf("%d",&day);
                searchDay(year,month,day,months,days);
                break;
            case 4:
                break;
            default:
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
    printf("1 - Visualizza il calendario di un mese\n");
    printf("2 - Visualizza il calendario di un anno\n");
    printf("3 - Visualizza il giorno della settimana di una data\n");
    printf("4 - Visualizza la differenza in giorni di due date\n");
    printf("0 - Uscita\n");
    printf("Scelta: ");
    scanf("%d",&sc);
    return sc;
}
