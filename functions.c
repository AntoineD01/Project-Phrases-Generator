//
// Created by Antoine Dupont on 29/10/2022.
//


#include "functions.h"

int define_type(char type[]) // Define the nature of the word => 1 if Nom, 2 if Verb, 3 if Adjective, 4 if Adverb
{
    if (type[0] == 'N')
    {
        return 1;
    }
    else
    {
        if (type[0] == 'V')
        {
            return 2;
        }
        else
        {
            if (type[0] == 'A' && type[2] == 'j')
            {
                return 3;
            }
            else
            {
                if (type[0] == 'A' && type[2] == 'v')
                {
                    return 4;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
}

int define_genre(char type[]) // Define the gender of the word =>1 if Masculine, 2 if Feminine, 3 if Invariable
{
    if (type[4] == 'M')
    {
        return 1;
    }
    else
    {
        if (type[4] == 'F')
        {
            return 2;
        }
        else
        {
            if (type[4] == 'I')
            {
                return 3;
            }
            else
            {
                return -1;
            }
        }
    }
}

int define_temps(char type[]) // Define the time of the verb =>1 if présent de l’indicatif, 2 if imparfait de l’indicatif, 3 if présent du subjonctif, 4 if infinitif
{
    if (type[4] == 'I' && type[5] == 'P' && type[6] == 'r')
    {
        return 1;
    }
    else
    {
        if (type[4] == 'I' && type[5] == 'I')
        {
            return 2;
        }
        else
        {
            if (type[4] == 'S' && type[5] == 'P')
            {
                return 3;
            }
            else
            {
                if(type[4] == 'I' && type[5] == 'n')
                {
                    return 4;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
}

int define_nombre(char type[])// Define the number of the word => 1 if singulier, 2 if pluriel
{
    if (define_type(type) == 1)
    {
        if (type[8] == 'S')
        {
            return 1;
        }
        else
        {
            if (type[8] == 'P')
            {
                return 2;
            }
            else
            {
                if (type[8] == 'I')
                {
                    return 3;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
    else
    {
        if(define_type(type) == 2)
        {
            if (type[9] == 'S')
            {
                return 1;
            }
            else
            {
                if (type[9] == 'P')
                {
                    return 2;
                }
            }
        }
        else
        {
            if (define_type(type) == 3)
            {
                if (define_genre(type) != 3)
                {
                    if (type[8] == 'S')
                    {
                        return 1;
                    }
                    else
                    {
                        if (type[8] == 'P')
                        {
                            return 2;
                        }
                        else
                        {
                            if (type[8] == 'I')
                            {
                                return 3;
                            }
                            else
                            {
                                return -1;
                            }
                        }
                    }
                }
                else
                {
                    if (type[11] == 'S')
                    {
                        return 1;
                    }
                    else
                    {
                        if (type[11] == 'P')
                        {
                            return 2;
                        }
                        else
                        {
                            if (type[11] == 'I')
                            {
                                return 3;
                            }
                            else
                            {
                                return -1;
                            }
                        }
                    }
                }
            }
            else
            {
                return -1;
            }
        }
    }
}

int define_personne(char type[]) // Define the person of the word => either 1st, 2nd or 3rd
{
    if (type[13] == '1')
    {
        return 1;
    }
    else
    {
        if (type[13] == '2')
        {
            return 2;
        }
        else
        {
            if (type[13] == '3')
            {
                return 3;
            }
        }
    }
}

void type_def(word* A, char type[])
{
    A->nature = define_type(type);
    if (A->nature == 1)// NOM
    {
        A->genre = define_genre(type);
        A->nombre = define_nombre(type);
    }
    else
    {
        if (A->nature == 2) //VERBE
        {
            A->temps = define_temps(type);
            A->nombre = define_nombre(type);
            A->personne = define_personne(type);
        }
        else
        {
            if (A->nature == 3) // ADJECTIF
            {
                A->genre = define_genre(type);
                A->nombre = define_nombre(type);
            }
            else
            {
                if (A->nature == 4) //ADVERBE
                {
                    A->genre = 3;
                    A->nombre = 3;
                }
            }
        }
    }
}

void display_type(word A) //Using the 'word' structure, display the information of the word
{
    if (A.nature == 1)// NOM
    {
        if(A.genre == 1)// Masculin
        {
            if (A.nombre == 1) // Singulier
            {
                printf("%s is a NOM Masculin Singulier\n", A.content);
            }
            else // Pluriel
            {
                printf("%s is a NOM Masculin Pluriel\n", A.content);
            }
        }
        else// Féminin
        {
            if (A.nombre == 1) // Singulier
            {
                printf("%s is a NOM Féminin Singulier\n", A.content);
            }
            else // Pluriel
            {
                printf("%s is a NOM Féminin Pluriel\n", A.content);
            }
        }
    }
    else
    {
        if(A.nature == 2)//VERBE
        {
            if (A.temps == 1) // Indicatif Present
            {
                if (A.personne == 1)
                {
                    if(A.nombre == 1)// Singulier
                    {
                        printf("%s is VERBE is in Indicatif Present 1ere personne du Singulier\n",A.content);
                    }
                    else {
                        printf("%s is VERBE is in Indicatif Present 1ere personne du Pluriel\n",A.content);
                    }
                }
                else
                {
                    if (A.personne == 2)
                    {
                        if(A.nombre == 1)// Singulier
                        {
                            printf("%s is VERBE is in Indicatif Present 2eme personne du Singulier\n",A.content);
                        }
                        else {
                            printf("%s is VERBE is in Indicatif Present 2eme personne du Pluriel\n",A.content);
                        }
                    }
                    else
                    {
                        if(A.nombre == 1)// Singulier
                        {
                            printf("%s is VERBE is in Indicatif Present 3eme personne du Singulier\n",A.content);
                        }
                        else {
                            printf("%s is VERBE is in Indicatif Present 3eme personne du Pluriel\n",A.content);
                        }
                    }
                }
            }
            else
            {
                if(A.temps == 2) // Indicatif Imparfait
                {
                    if (A.personne == 1)
                    {
                        if(A.nombre == 1)// Singulier
                        {
                            printf("%s is VERBE is in Indicatif Imparfait 1ere personne du Singulier\n",A.content);
                        }
                        else {
                            printf("%s is VERBE is in Indicatif Imparfait 1ere personne du Pluriel\n",A.content);
                        }
                    }
                    else
                    {
                        if (A.personne == 2)
                        {
                            if(A.nombre == 1)// Singulier
                            {
                                printf("%s is VERBE is in Indicatif Imparfait 2eme personne du Singulier\n",A.content);
                            }
                            else {
                                printf("%s is VERBE is in Indicatif Imparfait 2eme personne du Pluriel\n",A.content);
                            }
                        }
                        else
                        {
                            if(A.nombre == 1)// Singulier
                            {
                                printf("%s is VERBE is in Indicatif Imparfait 3eme personne du Singulier\n",A.content);
                            }
                            else {
                                printf("%s is VERBE is in Indicatif Imparfait 3eme personne du Pluriel\n",A.content);
                            }
                        }
                    }
                }
                else
                {
                   if (A.temps == 3) // Subjonctif Present
                   {
                       if (A.personne == 1)
                       {
                           if(A.nombre == 1)// Singulier
                           {
                               printf("%s is VERBE is in Subjonctif Present 1ere personne du Singulier\n",A.content);
                           }
                           else {
                               printf("%s is VERBE is in Subjonctif Present 1ere personne du Pluriel\n",A.content);
                           }
                       }
                       else
                       {
                           if (A.personne == 2)
                           {
                               if(A.nombre == 1)// Singulier
                               {
                                   printf("%s is VERBE is in Subjonctif Present 2eme personne du Singulier\n",A.content);
                               }
                               else {
                                   printf("%s is VERBE is in Subjonctif Present 2eme personne du Pluriel\n",A.content);
                               }
                           }
                           else
                           {
                               if(A.nombre == 1)// Singulier
                               {
                                   printf("%s is VERBE is in Subjonctif Present 3eme personne du Singulier\n",A.content);
                               }
                               else {
                                   printf("%s is a VERBE is in Subjonctif Present 3eme personne du Pluriel\n",A.content);
                               }
                           }
                       }
                   }
                   else
                   {
                       if (A.temps == 4) // Infinitif
                       {
                           printf("%s is a VERBE is in Infinitif\n",A.content);
                       }
                       else
                       {
                           printf("%s will not be stored\n",A.content);
                       }
                   }
                }
            }
        }
        else // ADJECTIF
        {
            if (A.nature == 3)
            {
                if(A.genre == 1)// Masculin
                {
                    if (A.nombre == 1) // Singulier
                    {
                        printf("%s is an ADJECTIF Masculin Singulier\n", A.content);
                    }
                    else // Pluriel
                    {
                        printf("%s is an ADJECTIF Masculin Pluriel\n", A.content);
                    }
                }
                else// Féminin
                {
                    if (A.nombre == 1) // Singulier
                    {
                        printf("%s is an ADJECTIF Féminin Singulier\n", A.content);
                    }
                    else // Pluriel
                    {
                        printf("%s is an ADJECTIF Féminin Pluriel\n", A.content);
                    }
                }
            }
            else
            {
                printf("%s is an ADVERBE and is Invariable\n",A.content);
            }
        }
    }
}

int ctr_calculator(word A) //Check if the base_word and the content of the 'word' structure are the same
{
    int ctr=0;
    int size = strlen(A.content);

    for (int i=0; i<size; i++)
    {
        if (A.content[i] == A.base_word[i])
        {
            ctr++;
        }
    }
    if (size != strlen(A.base_word))
    {
        ctr = 0;
    }
    return ctr;
}
