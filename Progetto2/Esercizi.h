#ifndef ESERCIZI_H_INCLUDED
#define ESERCIZI_H_INCLUDED

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

#endif // ESERCIZI_H_INCLUDED
