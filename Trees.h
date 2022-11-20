//
// Created by Antoine Dupont on 29/10/2022.
//

#ifndef TEST_PROJET_TREES_H
#define TEST_PROJET_TREES_H

#include "functions.h"
#include "stdlib.h"

typedef struct s_node
{
    char letter; //The letter of the node
    struct s_node* f_letters[26]; // 26 pointers to the potential next values
    flexed* f; //Informations about the word added and some flexed form (often NULL as not every letter are the end of a word)
}t_node;

typedef struct s_tree
{
    t_node* root; //Pointer to the first node (always the type of word stored in it)
}t_tree;


int empty_spot(t_node);
t_node* new_values(char, t_tree*, t_node*);
void display_node(t_node);
void information(t_node*,word);
t_node* research(word A,t_tree t);
void forme_flechi(word A, t_node* n);

#endif //TEST_PROJET_TREES_H
