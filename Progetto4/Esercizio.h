#ifndef ESERCIZION_H_INCLUDED
#define ESERCIZION_H_INCLUDED

void loadVet(int cart1[],int cart2[],int cart3[],int cart4[]){
    int ver[90];
    int exit=0;
    int random;
    int i=0;
    int j=1;

    for(i=0;i<90;i++)
        ver[i]=j++;
    for(i=0;i<15;i++){
        do{
            random = rand() % 90;
            if(ver[random]!=0)
            {
                exit=1;
                ver[random]=0;
            }
        }while(exit==0);
        exit=0;
        cart1[i]=random+1;
    }
    for(i=0;i<15;i++){
        do{
            random = rand() % 90;
            if(ver[random]!=0)
            {
                exit=1;
                ver[random]=0;
            }
        }while(exit==0);
        exit=0;
        cart2[i]=random+1;
    }
    for(i=0;i<15;i++){
        do{
            random = rand() % 90;
            if(ver[random]!=0)
            {
                exit=1;
                ver[random]=0;
            }
        }while(exit==0);
        exit=0;
        cart3[i]=random+1;
    }
    for(i=0;i<15;i++){
        do{
            random = rand() % 90;
            if(ver[random]!=0)
            {
                exit=1;
                ver[random]=0;
            }
        }while(exit==0);
        exit=0;
        cart4[i]=random+1;
    }
}

void printFolders(int cart[], char name[]){
    printf("Cartella di %s\n",name);
    int cnt=0;
    int i=0;
    cnt=0;
    for(i=0;i<15;i++){
        if(cnt%5==0)
            printf("\n");
        printf("%d\t",cart[i]);
        cnt++;
    }
    printf("\n\n");
}

void play(int cart1[],int cart2[],int cart3[],int cart4[],char name1[],char name2[],char name3[],char name4[]){
    int tombola = 0; //boolean
    int vinciteMinori = 2;
    int aus[90]; //boolean array
    int exit = 0; //boolean
    int i=0;
    int numeroEstratto;

    for(i=0;i<90;i++){
        aus[i]=0;
    }

    while(tombola == 0){
        do{
            numeroEstratto=rand() % 91+1;
            if(aus[numeroEstratto-1] == 0){
                exit = 1;
                aus[numeroEstratto-1] = 1;
            }
        }while(exit == 0);
        exit = 0;
        printf("NUMERO ESTRATTO: %d\n",numeroEstratto);
        printf("========\n");
        check(cart1,cart2,cart3,cart4,&numeroEstratto,&vinciteMinori,&tombola,name1,name2,name3,name4);
        fflush(stdin);
        printf("========\nPremi un tasto per continuare\n");
        getchar();
    }
}

void check(int cart1[],int cart2[],int cart3[],int cart4[],int *numeroEstratto,int *vinciteMinori,int *tombola,char name1[],char name2[],char name3[],char name4[]){
    int cnt = 0;
    int vincite[4];
    int vincita = 0;
    char names[4][MAX];
    char victorysName[4][10]={"Ambo","Terna","Quaterna","Cinquina"};

    for(int i=0;i<4;i++){
        vincite[i] = 0;
    }
    //it's checking if the number is there or not in the folder
    for(int i=0;i<15;i++){
        if(cart1[i] == (*numeroEstratto)){
            cart1[i]=0;
        }
        if(cart1[i]==0){
            cnt++;
        }
        if(i==4 || i==9 || i==14){
            if(cnt == (*vinciteMinori)){
                vincite[0] = 1;
            }
            cnt=0;
        }
    }
    cnt=0;
    for(int i=0;i<15;i++){
        if(cart2[i] == (*numeroEstratto)){
            cart2[i] = 0;
        }
        if(cart2[i]==0){
            cnt++;
        }
        if(i==4 || i==9 || i==14){
            if(cnt == (*vinciteMinori)){
                vincite[1] = 1;
            }
            cnt = 0;
        }
    }
    cnt = 0;
    for(int i=0;i<15;i++){
        if(cart3[i] == (*numeroEstratto)){
            cart3[i] = 0;
        }
        if(cart3[i]==0){
            cnt++;
        }
        if(i==4 || i==9 || i==14){
            if(cnt==(*vinciteMinori)){
                vincite[2] = 1;
            }
            cnt = 0;
        }
    }
    cnt = 0;
    for(int i=0;i<15;i++){
        if(cart4[i] == (*numeroEstratto)){
            cart4[i] = 0;
        }
        if(cart4[i]==0){
            cnt++;
        }
        if(i==4 || i==9 || i==14){
            if(cnt==(*vinciteMinori)){
                    vincite[3] = 1;
            }
            cnt = 0;
        }
    }
    printFolders(cart1, name1);
    printFolders(cart2, name2);
    printFolders(cart3, name3);
    printFolders(cart4, name4);
    //It's checking if it have made something or not like two numbers or triplet
    strcpy(names[0],name1);
    strcpy(names[1],name2);
    strcpy(names[2],name3);
    strcpy(names[3],name4);

    for(int i=0;i<4;i++){
        if(vincite[i]==1){
            vincita = 1;
            printf("%s: %s\n",victorysName[(*vinciteMinori)-2],names[i]);
        }
    }
    if(vincita==1 && (*vinciteMinori)!=6){
        (*vinciteMinori)+=1;
    }
    else if(vincita==0 && (*vinciteMinori)!=6){
        printf("%s: Nessuno\n",victorysName[(*vinciteMinori)-2]);
    }
    else{
        checkTombola(cart1,&tombola,name1);
        checkTombola(cart2,&tombola,name2);
        checkTombola(cart3,&tombola,name3);
        checkTombola(cart4,&tombola,name4);
        if(tombola==0){
            printf("Tombola: nessuno\n");
        }

    }
}

void checkTombola(int cart[],int *tombola,char nome[])
{
    int cnt=0;
    for(int i=0;i<15;i++){
        if(cart[i]==0){
            cnt++;
        }
    }

    if(cnt==15){
        (*tombola) = 1;
        printf("Tombola: %s\n",nome);
    }

}
#endif // ESERCIZION_H_INCLUDED
