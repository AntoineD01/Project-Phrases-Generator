//
// Created by Antoine Dupont on 29/10/2022.
//

#ifndef TEST_PROJET_FUNCTIONS_H
#define TEST_PROJET_FUNCTIONS_H

#include <string.h>
#include <stdio.h>

typedef struct
{
    char content[100];
    char base_word[100];
    int nature;
    int genre;
    int nombre;
    int temps;
    int personne;
}word;

typedef struct flexed
{
    word* himself;
    word* f_flechie[50];
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
