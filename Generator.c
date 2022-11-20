//
// Created by Antoine Dupont on 13/11/2022.
//


#include "Generator.h"

void menu(t_tree N, t_tree V, t_tree A, t_tree Av) //Display a menu and call every function needed
{
    int answer = 0;
    do{
        printf("\nWhat do you want to do next ?\n1 - Generate a sentence with only base word\n2 - Generate a sentence with the flexed forms\n3 - Search for a word in the tree\n");
        scanf("%d",&answer);
    }while(answer != 1 && answer != 2 && answer != 3);
    if (answer == 1) //Generate a sentence with only base word
    {
        generator(N,V,A,Av,0);
        menu(A,V,A,Av);
    }
    else
    {
        if (answer == 2) // Generate a sentence with the flexed forms (NOT DONE)
        {
            generator(N,V,A,Av,1);
            menu(A,V,A,Av);
        }
        else // Search for a word in the tree
        {

            do {
                printf("Is your word a noun (type 1), a verb (type 2), an adjective (type 3) or an adverb (type 4)?");
                scanf("%d",&answer); //Ask for the type of the word we are searching to look in the right tree
            }while(answer != 1 && answer != 2 && answer != 3 && answer != 4);
            if (answer == 1) //NOUN
            {
                word W;
                printf("Write you word :");
                scanf("%s",&W.base_word);
                research(W,N);
                menu(A,V,A,Av);
            }
            else
            {
                if (answer == 2) //VERB
                {
                    word W;
                    printf("Write you word :");
                    scanf("%s",&W.base_word);
                    research(W,V);
                    menu(A,V,A,Av);
                }
                else
                {
                    if (answer == 3) //ADJECTIVE
                    {
                        word W;
                        printf("Write you word :");
                        scanf("%s",&W.base_word);
                        research(W,A);
                        menu(A,V,A,Av);
                    }
                    else
                    {
                        if (answer == 4) //ADVERB
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

int random (int n) //Generate a random value using the time
{
    int r;
    srand(time(0));
    r = (rand()%n); // Generate a random number
    return r;
}


void generator (t_tree N, t_tree V, t_tree A, t_tree Av, int full) //Generate a full sentences using word from the trees
{
    int r;
    char nom1[100];
    char nom2[100];
    char adjectif[100];
    char verbe[100];
    char adverbe[100];

    t_node* temp;
    temp = N.root;

    if (full == 0) //Base word case
    {
        word W;
        int i=0; //FIRST NOUN
        while(temp->f_letters[0] != NULL){ //While it is not a leaf of the tree
            r = random(empty_spot(*temp)); //generate a random value
            nom1[i] = temp->letter; //Put as a letter of the word the letter of the tree
            W.base_word[i] = temp->letter; //Also put this letter in a structure
            temp = temp->f_letters[r]; //Go to the next letter using the random value as index
            i++;
        }
        nom1[0] = ' '; //Delete the first letter which is the type of the word
        printf("The First Noun is%s\n",nom1);

        i = 0; //VERB
        temp = V.root;
        while(temp->f_letters[0] != NULL){
            r = random(empty_spot(*temp));
            verbe[i] = temp->letter;
            temp = temp->f_letters[r];
            i++;
        }
        verbe[0] = ' ';
        printf("The Verb is%s\n",verbe);

        int ctr; //SECOND NOUN
        while(ctr != 0){
            i = 0;

            temp = N.root;
            while(temp->f_letters[0] != NULL){
                r = random(empty_spot(*temp));
                nom2[i] = temp->letter;
                W.content[i] = temp->letter;
                temp = temp->f_letters[r];
                i++;
            }
            nom2[0] = ' ';

            ctr = ctr_calculator(W);
        }
        printf("The Second Noun is%s\n",nom2);

        i = 0; //ADJECTIVE
        temp = A.root;
        while(temp->f_letters[0] != NULL){
            r = random(empty_spot(*temp));
            adjectif[i] = temp->letter;
            temp = temp->f_letters[r];
            i++;
        }
        adjectif[0] = ' ';
        printf("The Adjective is%s\n",adjectif);

        i = 0; //ADVERB
        temp = A.root;
        while(temp->f_letters[0] != NULL){
            r = random(empty_spot(*temp));
            adverbe[i] = temp->letter;
            temp = temp->f_letters[r];
            i++;
        }
        adverbe[0] = ' ';
        printf("The Adverb is%s\n",adverbe);

        r = random(3); //Choose the model
        if (r==0) //Model n°1 : nom – adjective – verb – nom
        {
            printf("%s%s%s%s\n",nom1,adjectif,verbe,nom2);
        }
        else
        {
            if (r==2) //Model n°2 : nom – ‘qui’ – verb – nom – adjective

            {
                printf("%s qui%s%s%s\n",nom1,verbe,adjectif,nom2);
            }
            else //Model n°3 : adverb - nom - verb - adjective - nom
            {
                printf("%s%s%s%s%s\n",adverbe,nom1,verbe,adjectif,nom2);
            }
        }
    }
    else
    {
        printf("Looking for Flexed form is not done yet\n");
    }
}
