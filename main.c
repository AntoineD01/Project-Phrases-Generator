#include <stdio.h>
#include "functions.h"
#include "Trees.h"
#include "Generator.h"

int main () {
    int answer;
    do{
        printf("Welcome to Random Word Generator !\nPress 1 to create the Tree.\n");
        scanf("%d",&answer);
    }while(answer != 1);
    FILE *fp;
    char str[5000];
    char type[100];

    t_tree Noun, Verb, Adj, Adv;
    t_node* tempN, *tempV, *tempA, *tempAv;
    t_node tempN1, tempV1, tempA1, tempAv1;
    t_node firstN, firstV, firstA, firstAv;
    tempN = &tempN1;
    tempV = &tempV1;
    tempA = &tempA1;
    tempAv = &tempAv1;

    Noun.root = NULL;
    Verb.root = NULL;
    Adj.root = NULL;
    Adv.root = NULL;

    fp = fopen("dico_reducted.txt" , "r"); // Open the file in read mode "r"

    if(fp == NULL) {
        perror("Error opening file");
        return(-1); // test if the file is not empty or if there is any issue
    }

    Noun.root = &firstN;
    firstN.letter = 'N';
    firstN.f_letters[0] = tempN;
    for (int i=0; i<26; i++)
    {
        firstN.f_letters[i] = NULL;
    }

    Verb.root = &firstV;
    firstV.letter = 'V';
    firstV.f_letters[0] = tempV;
    for (int i=0; i<26; i++)
    {
        firstV.f_letters[i] = NULL;
    }

    Adj.root = &firstA;
    firstA.letter = 'A';
    firstA.f_letters[0] = tempA;
    for (int i=0; i<26; i++)
    {
        firstA.f_letters[i] = NULL;
    }

    Adv.root = &firstAv;
    firstAv.letter = 'A';
    firstAv.f_letters[0] = tempAv;
    for (int i=0; i<26; i++)
    {
        firstAv.f_letters[i] = NULL;
    }


    while (fgets (str, sizeof(str), fp)!=NULL) {
        word A;
        sscanf(str,"%s\t%s\t%s",&A.content, &A.base_word, &type); //Put every information from the text in the right spot
        type_def(&A,type); // Define information from the previous line

        for (int i=0; i<26; i++)
        {
            tempN->f_letters[i] = NULL;
            tempV->f_letters[i] = NULL;
            tempA->f_letters[i] = NULL;
            tempAv->f_letters[i] = NULL;
        }
        int size = strlen(A.content);
        int ctr =  ctr_calculator(A);
        if (ctr == size) // If the word is a base word
        {
            if (A.nature == 1) //Nom
            {

                for (int i=0; i<size+1; i++)
                {
                    if (i==0) //First letter of the word
                    {
                        tempN = new_values(A.content[i], &Noun, &firstN);
                        display_node(*tempN);
                    }
                    else
                    {
                        if(i==size) //Last letter of the word
                        {
                            tempN = new_values(A.content[i], &Noun, tempN);
                            display_node(*tempN);
                            information(tempN, A);
                            printf("genre = %d\nnombre = %d\n\n",tempN->f->himself->genre,tempN->f->himself->nombre);
                        }
                        else //Letters of the word
                        {
                            tempN = new_values(A.content[i], &Noun, tempN);
                            display_node(*tempN);
                        }
                    }
                }
                printf("%s has been added\n",A.content);
            }
            else
            {
                if(A.nature == 2) //Verbe
                {
                    for (int i=0; i<size+1; i++)
                    {
                        if (i==0)
                        {
                            tempV = new_values(A.content[i], &Verb, &firstV);
                            display_node(*tempV);
                        }
                        else
                        {
                            if(i==size)
                            {
                                tempV = new_values(A.content[i], &Verb, tempV);
                                display_node(*tempV);
                                information(tempV, A);
                                printf("temps = %d\n\n",tempV->f->himself->temps,tempV->f->himself->personne, tempV->f->himself->nombre);
                            }
                            else
                            {
                                tempV = new_values(A.content[i], &Verb, tempV);
                                display_node(*tempV);
                            }


                        }
                    }
                    printf("%s has been added\n",A.content);
                }
                else
                {
                    if(A.nature == 3) //Adjectif
                    {
                        for (int i=0; i<size+1; i++)
                        {
                            if (i==0)
                            {
                                tempA = new_values(A.content[i], &Adj, &firstA);
                                display_node(*tempA);
                            }
                            else
                            {
                                if(i==size)
                                {
                                    tempA = new_values(A.content[i], &Adj, tempA);
                                    display_node(*tempA);
                                    information(tempA, A);
                                    printf("genre = %d\nnombre = %d\n\n",tempA->f->himself->genre,tempA->f->himself->nombre);
                                }
                                else
                                {
                                    tempA = new_values(A.content[i], &Adj, tempA);
                                    display_node(*tempA);
                                }

                            }
                        }
                        printf("%s has been added\n",A.content);
                    }
                    else
                    {
                        if(A.nature == 4) // Adverbe
                        {
                            for (int i=0; i<size+1; i++)
                            {
                                if (i==0)
                                {
                                    tempAv = new_values(A.content[i], &Adv, &firstAv);
                                    display_node(*tempAv);
                                }
                                else
                                {
                                    if(i==size)
                                    {
                                        tempAv = new_values(A.content[i], &Adv, tempAv);
                                        display_node(*tempAv);
                                        information(tempAv, A);
                                        printf("nombre = %d\n\n",tempAv->f->himself->nombre);
                                    }
                                    else
                                    {
                                        tempAv = new_values(A.content[i], &Adv, tempAv);
                                        display_node(*tempAv);
                                    }

                                }
                            }
                            printf("%s has been added\n",A.content);
                        }
                        else
                        {
                            if(A.nature == -1)
                            {
                                printf("%s will not be added\n",A.content);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("The word : %s is a flexed form of %s.\n",A.content,A.base_word);
            if (A.nature == 1)
            {
                t_node* ptr = NULL;
                ptr = research(A,Noun);
                if (ptr != NULL)
                {
                    //printf("%c\n",ptr->letter);
                    //forme_flechi(A,ptr);
                }
            }
            else
            {
                if (A.nature == 2)
                {

                    t_node* ptr = NULL;
                    ptr = research(A,Verb);
                    if (ptr != NULL)
                    {
                        //printf("%c\n",ptr->letter);
                        //forme_flechi(A,ptr);
                    }
                }
                else
                {
                    if (A.nature == 3)
                    {
                        t_node* ptr = NULL;
                        ptr = research(A,Adj);
                        if (ptr != NULL)
                        {
                            //printf("%c\n",ptr->letter);
                            //forme_flechi(A,ptr);
                        }
                    }
                    else
                    {
                        t_node* ptr = NULL;
                        ptr = research(A,Adv);
                        if (ptr != NULL)
                        {
                            //printf("%c",ptr->letter);
                            //forme_flechi(A,ptr);
                        }
                    }
                }
            }
        }
    }

    fclose(fp); // Close the file

    generator(Noun,Verb, Adj, Adv,0);
    //menu(Noun,Verb, Adj, Adv);


    return 0;
}
