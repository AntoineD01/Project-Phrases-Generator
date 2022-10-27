//
// Created by Antoine Dupont on 27/10/2022.
//

#ifndef PROJECT_PHRASES_GENERATOR_TREES_H
#define PROJECT_PHRASES_GENERATOR_TREES_H

struct s_node
{
    char letter;
    struct s_node *left, *right;
    struct s_node *variations; //Ne pas stocker dans l'arbre
};

typedef struct s_node t_node, *p_node;


typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

#endif //PROJECT_PHRASES_GENERATOR_TREES_H
