//
// Created by Antoine Dupont on 29/10/2022.
//

#ifndef TEST_PROJET_FUNCTIONS_H
#define TEST_PROJET_FUNCTIONS_H

#include <string.h>
#include <stdio.h>

typedef struct
{
    char content[100]; //The word
    char base_word[100]; //Its basic form
    int nature; //The nature of the word
    int genre; //The gender of the word
    int nombre; //The number of the word
    int temps; //The temps of the verb
    int personne; //The person of the verb
}word;

typedef struct flexed
{
    word* himself; //The information of the word actually in the tree
    word* f_flechie[50]; //Flexed form of this word
}flexed;

int define_type(char type[]);
int define_genre(char type[]);
int define_temps(char type[]);
int define_nombre(char type[]);
int define_personne(char type[]);
void type_def(word* A, char type[]);
void display_type(word A);
int ctr_calculator(word A);


#endif //TEST_PROJET_FUNCTIONS_H

