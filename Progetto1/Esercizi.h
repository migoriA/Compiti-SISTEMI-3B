#ifndef ESERCIZI_H_INCLUDED
#define ESERCIZI_H_INCLUDED
#include <math.h>

int caricaVet(int a[]){
    int lung;
    int i;
    srand(time(NULL));
    printf("Inserire la lunghezza del vettore: ");
    scanf("%d", &lung);

    for(i=0;i<lung;i++){
        a[i]=rand()%41-20;
    }
    return lung;
}

void stampaVet(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ,",a[i]);
    }
}

void calcolaSommaMedia(int a[], int n, int *media, int *somma){
    int i;
    (*somma)=0;
    (*media)=0;
    for(i=0;i<n;i++){
        (*somma)+=a[i];
    }
    (*media)=(*somma)/n;
}

void cercaMinMax(int a[],int n,int *max,int *min){
    int i;
    (*max)=0;
    (*min)=30;

    for(i=0;i<n;i++){
        if(a[i]>(*max)){
            (*max)=a[i];
        }
        if(a[i]<(*min)){
            (*min)=a[i];
        }
    }
}

int sommaPSommaN(int a[],int n,int *somP,int *somN){
    int i;
    (*somN)=0;
    (*somP)=0;
    for(i=0;i<n;i++){
        if(a[i]>0){
            (*somP)+=a[i];
        }
        else{
            (*somN)+=a[i];
        }
    }
    if((*somP)>abs(*somN)){
        return 1;
    }
    else{
        return 0;
    }
}
#endif // ESERCIZI_H_INCLUDED
