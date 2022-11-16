//
// Created by Antoine Dupont on 27/10/2022.
//

#include "Trees.h"


t_node* new_values(char letter, t_tree *Tree, t_node* leaf)
{
    t_node* n_node;
    n_node = malloc(sizeof(t_node));
    //printf("First empty spot of %c : %d\n",leaf->letter,empty_spot(*leaf));
    if (empty_spot(*leaf) == 0) //If no child yet
    {
        //printf("This letter has no child yet\n");
        leaf->f_letters[0] = n_node;
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
            //printf("The letter is not in the tree \n");
            leaf->f_letters[empty_spot(*leaf)] = n_node;
            n_node->letter = letter;
            for (int i=0; i<26; i++)
            {
                n_node->f_letters[i] = NULL;
            }
            return n_node;
        }
        else //If the letter is already in the tree
        {
            //printf("The letter is in the tree\n");
            free(n_node);
            return leaf->f_letters[index];
        }
    }
}


void display_node(t_node n)
{
    printf("The letter in this node is %c and have %d child.\n\n",n.letter, empty_spot(n));
    for (int i=0; i< empty_spot(n); i++)
    {
        printf("The value at index %d is %c\n",i,n.f_letters[i]->letter);
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

void information(t_node* n, word A)
{
    word* infos= malloc(sizeof(word));
    flexed* fle = malloc(sizeof(flexed));
    infos->nature = A.nature;
    if (infos->nature == 1 || infos->nature == 3) //Nom and Adjectif
    {
        infos->genre = A.genre;
        infos->nombre = A.nombre;
        fle->himself = infos;
        n->f = fle;
    }
    else
    {
        if(infos->nature == 2) //Verbe
        {
            infos->temps = A.temps;
            fle->himself = infos;
            n->f = fle;
        }
        else //Adverbe
        {
            if(infos->nature == 4)
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

t_node* research(word A,t_tree t)
{
    t_node* temp;
    temp = malloc(sizeof(t_node));
    int index=0;
    int ctr=0;
    temp = t.root;
    if (temp->f_letters[0] == NULL)
    {
        printf("This word is not in the tree.\n");
        return 0;
    }

    for (int j=0; j<strlen(A.base_word); j++)
    {
        for (int i=0; i<empty_spot(*temp); i++)
        {
            if (A.base_word[index] == temp->f_letters[i]->letter && empty_spot(*temp) != 0 && index!=strlen(A.base_word))
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

    if (ctr == strlen(A.base_word))
    {
        printf("We've found the word.\n");
        return temp;
    }
    else
    {
        printf("We've not found the word.\n");
        return NULL;
    }
}

void forme_flechi(word A, t_node* n) //TO BE DONE
{
    word* infos= malloc(sizeof(word));
    flexed* fle = malloc(sizeof(flexed));
    infos->nature = A.nature;
    if (infos->nature == 1 || infos->nature == 3) //Nom and Adjectif
    {
        infos->genre = A.genre;
        infos->nombre = A.nombre;
        int i;
        for (i=0; i<50; i++)
        {
            if (fle->f_flechie[i] != NULL)
            {
                printf("The first empty spot is %d",i);
                break;
            }
        }
        fle->f_flechie[i] =
        n->f = fle;
    }
    else
    {
        if(infos->nature == 2) //Verbe
        {
            infos->temps = A.temps;
            fle->himself = infos;
            n->f = fle;
        }
        else //Adverbe
        {
            if(infos->nature == 4)
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

