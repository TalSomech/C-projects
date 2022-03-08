//
// Created by tal on 11/01/2021.
//

#ifndef C_EX4_TREE_H
#define C_EX4_TREE_H

#define NUM_LETTERS ((int)26)
//char chtolow(char l);
typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} node, *node_p;
node* newNode();
node_p static addNode(char lst,node_p cur);
void static printFreq(node_p root,int t, char *wrd, int d);
//void static destRootRec(node_p root);
#endif //C_EX4_TREE_H
