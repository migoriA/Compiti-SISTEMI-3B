#ifndef ESERCIZI_H_INCLUDED
#define ESERCIZI_H_INCLUDED

void printMonth(int month, int year, char months[12][10], int days[]){
    int offsetAnno = 0;
    int nDays=0;
    int giorniPassati=0;
    int offsetMese = 0;
    int aus = 0;
    int cont = 1;
    int i = 0;

    printf("== Mese di %s %d\n",months[month-1],year);
    printf("LU\tMA\tME\tGI\tVE\tSA\tDO\n");

    offsetAnno = ((year-1900)%7+((((year-1)-1900)/4)%7));

    for(i=0;i<month-1;i++){
        giorniPassati+=days[i];
        if(i==1 && year%4==0 && year%100!=0 || year%400==0){
            giorniPassati++;
        }
    }
    if(year%4==0 && month==2 && year%100!=0 || year%400==0){
        nDays = days[month-1]+1;
    }
    else{
        nDays = days[month-1];
    }

    offsetMese = (offsetAnno+giorniPassati)%7;
    aus=offsetMese;

    for(i=0;i<offsetMese;i++){
        printf("\t");
    }

    for(cont=1;cont<=nDays;cont++){
        printf("%d\t",cont);
        aus++;
        if(aus==7){
            aus=0;
            printf("\n");
        }
    }
}

void printYear(int year,char months[12][10],int days[]){
    for(int i=1;i<=12;i++){
        printMonth(i,year,months,days);
        printf("\n\n");
    }
}

void searchDay(int year,int month,int day,char months[12][10],int days[]){
    int nDays=0;
    char nameDays[7][3]={"LU","MA","ME","GI","VE","SA","DO"};
    int offsetAnno=0;
    int giorniPassati=0;
    int i=0;
    int j=0;

    if(year%4==0 && month==2 && year%100!=0 || year%400==0){
        nDays=days[month-1]+1;
    }
    else{
        nDays=days[month-1];
    }
    if(year>=1900 && year<=2022 && month>0 && month<=12 && day>0 && day<=nDays){
        offsetAnno = ((year-1900)%7+((((year-1)-1900)/4)%7));
        for(i=0;i<month-1;i++){
            giorniPassati+=days[i];
            if(i==1 && year%4==0 && year%100!=0 || year%400==0){
                giorniPassati++;
            }
        }
        j=(giorniPassati+offsetAnno+(day-1))%7;
        printf("E' un %s\n",nameDays[j]);
    }
    else
        printf("Data non trovata\n");
}


#endif // ESERCIZI_H_INCLUDED
