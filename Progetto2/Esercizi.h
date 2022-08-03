#ifndef ESERCIZI_H_INCLUDED
#define ESERCIZI_H_INCLUDED

#define MAX 100

void contaConsonantiVocali(char str[], int *c, int *v){
    int n=0;
    int pos;
    int i;
    int cont[26];
    (*c)=0;
    (*v)=0;

    for(i=0;i<26;i++){
        cont[i]=0;
    }

    n=strlen(str);

    for(i=0;i<n;i++){
        if(str[i]>='A' && str[i]<='Z'){
            pos=str[i]-'A';
            cont[pos]++;
        }
        else{
            if(str[i]>='a' && str[i]<='z'){
                pos=str[i]-'a';
                cont[pos]++;
            }
        }
    }
    (*v)=cont['A'-'A']+cont['E'-'A']+cont['I'-'A']+cont['O'-'A']+cont['U'-'A'];
    for(i=0;i<26;i++){
        (*c)+=cont[i];
    }
    (*c)-=(*v);
}

void contaLettere(char str[]){
    int n;
    int pos;
    int i;
    int cont[26];

    n=strlen(str);

    for(i=0;i<26;i++){
        cont[i]=0;
    }

    for(i=0;i<n;i++){
        if(str[i]>='A' && str[i]<='Z'){
            pos=str[i]-'A';
            cont[pos]++;
        }
        else{
            if(str[i]>='a' && str[i]<='z'){
                pos=str[i]-'a';
                cont[pos]++;
            }
        }
    }
    printf("\nA B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");

    for(i=0;i<26;i++){
        printf("%d ",cont[i]);
    }
}

void raddoppiaVocali(char str[]){
    int i=0,j=0;
    char str2[MAX];

    while(str[i] != '\0'){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            str2[j++] = str[i];
        str2[j++] = str[i++];
    }
    str2[j] = '\0';
    strcpy(str,str2);
}

void rimuoviVocali(char str[]){
    int i=0,j=0;
    char str2[MAX];

    while(str[i] != '\0'){
        if(!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'))
            str2[j++] = str[i];
        i++;
    }
    str2[j] = '\0';
    strcpy(str,str2);
}
#endif // ESERCIZI_H_INCLUDED
