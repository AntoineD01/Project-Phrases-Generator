//
// Created by Antoine Dupont on 13/11/2022.
//


#include "Generator.h"

void menu(t_tree N, t_tree V, t_tree A, t_tree Av)
{
    int answer = 0;
    do{
        printf("Welcome to Random Word Generator !\nPress 1 to create the Tree.\n");
        scanf("%d",&answer);
    }while(answer != 1);

    generator(N,V,A,Av);
}

int random (int n)
{
    int r;
    srand(time(0));
    r = (rand()%n); // Generate a random number
    return r;
}

//Modèle n°1 : nom – adjectif – verbe – nom
//Modèle n°2 : nom – ‘qui’ – verbe – nom – adjectif
//Modèle n°3 : adjectif - nom - verbe - adjectif - nom

void generator (t_tree N, t_tree V, t_tree A, t_tree Av)
{
    int r, stop;
    r = random(3); //Choose the model
    char sentence[100];
    char nom[100];
    char adjectif[100];
    char verbe[100];
    char adverbe[100];

    t_node* temp;
    stop = random(2);
    printf("%d",stop);
    r = random(26); //Choose the model
    temp = N.root;
    temp = N.root->f_letters[r];

    for (int i=0; i<100; i++)
    {
        r = random(empty_spot(*temp)-1); //Choose the model
        temp = temp->f_letters[r];
    }
}
