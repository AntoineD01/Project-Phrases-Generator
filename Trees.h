//
// Created by Antoine Dupont on 29/10/2022.
//

#ifndef TEST_PROJET_TREES_H
#define TEST_PROJET_TREES_H

#include "functions.h"
#include "stdlib.h"

typedef struct s_node //structure du noeud 
{
    char letter;
    struct s_node* f_letters[26];
    flexed* f;
}t_node;

typedef struct s_tree //structure de l'arbre
{
    t_node* root;
}t_tree;


//prototypes
int empty_spot(t_node);
t_node* new_values(char, t_tree*, t_node*);
void display_node(t_node);
void information(t_node*,word);
t_node* research(word A,t_tree t);
void forme_flechi(word A, t_node* n);

#endif //TEST_PROJET_TREES_H
