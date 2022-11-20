//
// Created by Antoine Dupont on 29/10/2022.
//
#include "Trees.h"

t_node* new_values(char letter, t_tree *Tree, t_node* leaf) //Add nodes to the tree and return it
{
    t_node* n_node;
    n_node = malloc(sizeof(t_node));
    if (empty_spot(*leaf) == 0) //If no child yet
    {
        leaf->f_letters[0] = n_node; //The first child of the leaf will be this node
        n_node->letter = letter;
        for (int i=0; i<26; i++)
        {
            n_node->f_letters[i] = NULL;
        }
        return n_node;
    }
    else
    {
        int exist=0;
        int index;
        for (int i=0; i<empty_spot(*leaf); i++)
        {
            if (letter == leaf->f_letters[i]->letter) //If the letter is already in the tree
            {
                exist = 1;
                index = i;
                break;
            }
        }
        if (exist == 0) //If the letter is not in the tree
        {
            printf("The letter is not in the tree.\n");
            leaf->f_letters[empty_spot(*leaf)] = n_node; //Add the node in the first empty pointer
            n_node->letter = letter;
            for (int i=0; i<26; i++)
            {
                n_node->f_letters[i] = NULL;
            }
            return n_node;
        }
        else //If the letter is already in the tree
        {
            printf("The letter is in the tree.\n");
            free(n_node);
            return leaf->f_letters[index]; //In this case we return the node that have the letter we have been working on
        }
    }
}


void display_node(t_node n) //Display the node and its children
{
    printf("The letter in this node is %c and have %d child.\n\n",n.letter, empty_spot(n)); //Display the node
    for (int i=0; i< empty_spot(n); i++)
    {
        printf("The value at index %d is %c.\n",i,n.f_letters[i]->letter); //Display children of the node
    }
}


int empty_spot(t_node n) //Find the first empty spot in the pointer spot
{
    int i = 0;
    while(n.f_letters[i] != NULL)
    {
        i++;
    }
    return i;
}

void information(t_node* n, word A) //Put the information of the word in the right spot of the structure
{
    word* infos= malloc(sizeof(word));
    flexed* fle = malloc(sizeof(flexed));
    infos->nature = A.nature;
    if (infos->nature == 1 || infos->nature == 3) //Noun and Adjective
    {
        infos->genre = A.genre;
        infos->nombre = A.nombre;
        fle->himself = infos;
        n->f = fle;
    }
    else
    {
        if(infos->nature == 2) //Verb
        {
            infos->temps = A.temps;
            fle->himself = infos;
            n->f = fle;
        }
        else
        {
            if(infos->nature == 4) //Adverb
            {
                infos->nombre = A.nombre;
                fle->himself = infos;
                n->f = fle;
            }
            else
            {
                if(infos->nature == -1)
                {
                    free(infos);
                    free(fle);
                    printf("Do nothing\n");
                }
            }
        }
    }
}

t_node* research(word A,t_tree t) //Look for a word in the tree and return a pointer to it last node
{
    t_node* temp;
    int index=0;
    int ctr=0;
    temp = t.root;
    if (temp->f_letters[0] == NULL) //If the tree has no node
    {
        printf("This word is not in the tree.\n");
        return 0;
    }

    for (int j=0; j<strlen(A.base_word); j++)
    {
        for (int i=0; i<empty_spot(*temp); i++)
        {
            if (A.base_word[index] == temp->f_letters[i]->letter && empty_spot(*temp) != 0 && index!=strlen(A.base_word)) //Check if every letter are the letter of the word we search for
            {
                temp = temp->f_letters[i];
                index++;
                ctr++;
            }
            else
            {
                break;
            }
        }
    }

    if (ctr == strlen(A.base_word)) //If the counter is as long as the length of the word we are searching
    {
        printf("This word is in the tree.\n\n");
        return temp;
    }
    else
    {
        printf("This word is not in the tree.\n\n");
        return NULL;
    }
}

void forme_flechi(word A, t_node* n) //This function did not work and that's why it is not used in the main
{
    printf("The letter is %c.",n->letter);

    int index = 0;

    if(n->f->f_flechie[index] == NULL)
    {
        printf("%d",index);
        index++;
    }
    else
    {
        printf("The first empty spot is %d.",index);
    }
}
