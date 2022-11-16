//
// Created by Antoine Dupont on 13/11/2022.
//


#include "Generator.h"

void menu(t_tree N, t_tree V, t_tree A, t_tree Av)
{
    int answer = 0;
    do{
        printf("What do you want to do next ?\n1 - Generate a sentence with only base word\n2 - Generate a sentence with the flexed forms\n3 - Search for a word in the tree\n");
        scanf("%d",&answer);
    }while(answer != 1 && answer != 2 && answer != 3);
    if (answer == 1)
    {
        generator(N,V,A,Av,0);
        menu(A,V,A,Av);
    }
    else
    {
        if (answer == 2)
        {
            generator(N,V,A,Av,1);
            menu(A,V,A,Av);
        }
        else
        {

            do {
                printf("Is your word a noun (type 1), a verb (type 2), an adjective (type 3) or an adverb (type 4)?");
                scanf("%d",&answer);
            }while(answer != 1 && answer != 2 && answer != 3 && answer != 4);
            if (answer == 1)
            {
                word W;
                printf("Write you word :");
                scanf("%s",&W.base_word);
                research(W,N);
                menu(A,V,A,Av);
            }
            else
            {
                if (answer == 2)
                {
                    word W;
                    printf("Write you word :");
                    scanf("%s",&W.base_word);
                    research(W,V);
                    menu(A,V,A,Av);
                }
                else
                {
                    if (answer == 3)
                    {
                        word W;
                        printf("Write you word :");
                        scanf("%s",&W.base_word);
                        research(W,A);
                        menu(A,V,A,Av);
                    }
                    else
                    {
                        if (answer == 4)
                        {
                            word W;
                            printf("Write you word :");
                            scanf("%s",&W.base_word);
                            research(W,Av);
                            menu(A,V,A,Av);
                        }
                        else
                        {
                            printf("We have an Issue here...");
                        }
                    }
                }
            }
        }
    }

}

int random (int n)
{
    int r;
    srand(time(0));
    r = (rand()%n); // Generate a random number
    return r;
}


void generator (t_tree N, t_tree V, t_tree A, t_tree Av, int full)
{
    int r, stop;
    char sentence[100];
    char nom1[100];
    char nom2[100];
    char adjectif[100];
    char verbe[100];
    char adverbe[100];

    t_node* temp;
    temp = N.root;

    if (full == 0)
    {
        word W;
        int i=0;
        while(temp->f_letters[0] != NULL){
            r = random(empty_spot(*temp));
            //printf("The random value is %d which represent the letter %c\n",r,temp->letter);
            nom1[i] = temp->letter;
            W.base_word[i] = temp->letter;
            temp = temp->f_letters[r];
            i++;
        }
        nom1[0] = ' ';
        printf("The First Noun is%s\n",nom1);

        i = 0;
        temp = V.root;
        while(temp->f_letters[0] != NULL){
            r = random(empty_spot(*temp));
            //printf("The random value is %d which represent the letter %c\n",r,temp->letter);
            verbe[i] = temp->letter;
            temp = temp->f_letters[r];
            i++;
        }
        verbe[0] = ' ';
        printf("The Verb is%s\n",verbe);

        int ctr;
        while(ctr != 0){
            i = 0;

            temp = N.root;
            while(temp->f_letters[0] != NULL){
                r = random(empty_spot(*temp));
                //printf("The random value is %d which represent the letter %c\n",r,temp->letter);
                nom2[i] = temp->letter;
                W.content[i] = temp->letter;
                temp = temp->f_letters[r];
                i++;
            }
            nom2[0] = ' ';

            ctr = ctr_calculator(W);
        }
        printf("The Second Noun is%s\n",nom2);

        i = 0;
        temp = A.root;
        while(temp->f_letters[0] != NULL){
            r = random(empty_spot(*temp));
            //printf("The random value is %d which represent the letter %c\n",r,temp->letter);
            adjectif[i] = temp->letter;
            temp = temp->f_letters[r];
            i++;
        }
        adjectif[0] = ' ';
        printf("The Adjectif is%s\n",adjectif);

        i = 0;
        temp = A.root;
        while(temp->f_letters[0] != NULL){
            r = random(empty_spot(*temp));
            //printf("The random value is %d which represent the letter %c\n",r,temp->letter);
            adverbe[i] = temp->letter;
            temp = temp->f_letters[r];
            i++;
        }
        adverbe[0] = ' ';
        printf("The Adverbe is%s\n",adverbe);

        r = random(3); //Choose the model
        if (r==0) //Modèle n°1 : nom – adjectif – verbe – nom
        {
            printf("%s%s%s%s",nom1,adjectif,verbe,nom2);
        }
        else
        {
            if (r==2) //Modèle n°2 : nom – ‘qui’ – verbe – nom – adjectif

            {
                printf("%s qui%s%s%s",nom1,verbe,adjectif,nom2);
            }
            else //Modèle n°3 : adverbe - nom - verbe - adjectif - nom
            {
                printf("%s%s%s%s%s",adverbe,nom1,verbe,adjectif,nom2);
            }
        }
    }
    else
    {
        printf("WORK IN PROGRESS\n");
    }
}
