#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

#include "Esercizio.h"

int main()
{
    int cart1[15], cart2[15], cart3[15], cart4[15];
    char name1[MAX], name2[MAX], name3[MAX], name4[MAX];
    srand(time(NULL));

    printf("Nome del primo giocatore: ");
    gets(name1);
    printf("Nome del secondo giocatore: ");
    gets(name2);
    printf("Nome del terzo giocatore: ");
    gets(name3);
    printf("Nome del quarto giocatore: ");
    gets(name4);

    //This function load the number in the folders

    loadVet(cart1,cart2,cart3,cart4);

    printf("========\n");
    printf("CARTELLE\n");
    printf("========\n");

    printFolders(cart1,name1);
    printFolders(cart2,name2);
    printFolders(cart3,name3);
    printFolders(cart4,name4);

    fflush(stdin);
    getchar();

    play(cart1,cart2,cart3,cart4,name1,name2,name3,name4);
    return 0;
}
