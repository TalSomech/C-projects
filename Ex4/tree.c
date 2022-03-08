//
// Created by tal on 11/01/2021.
//
#include <string.h>
#include <stdio.h>
#include "tree.h"
#include <ctype.h>
#include <stdlib.h>

#define NUM_LETTERS ((int)26)


node_p  addNode(char lst, node_p cur) {
    node_p nw = newNode();
    if(!nw)
        return NULL;
    cur->children[lst - 'a'] = nw;
    nw->letter=lst;
    return nw;
}

void static printFreq(node_p root, int t, char *wrd, int d) {
    int i = 0;
    if (t)
        i = NUM_LETTERS-1;
    if(root->count!=0){
        printf("%s %lu\n",wrd,root->count);
    }
    for (; t ? i >= 0 : i < NUM_LETTERS; t ? i-- : i++) {
        if (root->children[i] != NULL) {
            wrd[d-1] = i + 'a';
            wrd[d]='\0';
            printFreq((root->children[i]), t, wrd, d + 1);
        }
    }
    free(root);
}

node* newNode(){
    node_p nd=(node_p) malloc(sizeof(struct node));
    if(!nd)
        return NULL;
    nd->letter='\0';
    nd->count=0;
    int i;
    for (i = 0; i < NUM_LETTERS; ++i) {
        nd->children[i]=NULL;
    }
    return nd;
}
void static destRootRec(node_p root){
    int i=0;
    for(;i<NUM_LETTERS-1;++i) {
        if (root->children[i] != NULL) {
            destRootRec((root->children[i]));
        }
    }
    free(root);
}
int main(int argc, char *argv[]) {
    node_p root = newNode();
    if(!root){
        exit(0);
    }
    node_p temp = root;
    char cur;
    int i = 0;
    int max=0;
    while ((cur = fgetc(stdin)) != EOF) {
        cur = tolower(cur);
        if (temp != root &&(cur == '\n' || cur == ' ' || cur == '\t' || cur == '\r')) {
            max=max<i?i:max;
            i=0;
            temp->count++;
            temp = root;
            continue;
        }
        if (cur < 'a' || cur > 'z')
            continue;
        if (temp->children[cur - 'a'] != NULL) {
            temp = temp->children[cur - 'a'];
            continue;
        } else {
            temp = addNode(cur, temp);
            if(!temp){
                destRootRec(root);
                exit(0);
            }
            i++;
        }
    }
    max=max<i?i:max;
    int t=0;
    if(argc==2&&argv[1][0]=='r')
        t=1;
   char *word=(char*)malloc(max* sizeof(char)+1);
   if(!word){
       destRootRec(root);
       exit(0);
   }
   printFreq(root,t,word,1);
   free(word);
   exit(0);
}