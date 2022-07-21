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

void pariDispari(int a[],int n,int pari[],int dispari[],int *j, int *k){
    int i;
    (*k)=0;
    (*j)=0;
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            pari[(*k)]=a[i];
            (*k)+=1;
        }
        else{
            dispari[(*j)]=a[i];
            (*j)+=1;
        }
    }
}

int vettoreSpeculare(int s[]){
    int i;
    int n=10;
    int j=9;
    int spec=0;
    for(i=0;i<10;i++){
        printf("\nInserire il valore in pos. %d: ",i);
        scanf("%d",&s[i]);
    }
    i=0;
    while(i!=n/2){
        if(s[i]==s[j]){
            spec=1;
            j--;
            i++;
        }
        else{
            return 0;
        }
    }
}

void ordinaVet(int a[], int n){
    int i;
    int j;
    int posMin;
    int aus;

    for(i=0;i<n-1;i++){
        posMin=i;
        for(j=i+1;j<n;j++){
            if(a[posMin]>a[j]){
                posMin=j;
            }
        }
        if(posMin!=i){
            aus=a[i];
            a[i]=a[posMin];
            a[posMin]=aus;
        }
    }
}

int cercaNumero(int a[],int n,int nCercare){
    int i;
    int cnt;
    cnt=0;
    for(i=0;i<n;i++){
        if(a[i]==nCercare){
            cnt++;
        }
    }
    return cnt;
}
#endif // ESERCIZI_H_INCLUDED
