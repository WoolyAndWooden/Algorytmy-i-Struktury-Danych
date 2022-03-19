//In this file is implementation of binary tree using structs in C language
//This application is intended for building binary tree, removing nodes and printing the structure

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int key;
    struct Node * right;
    struct Node * left;
    struct Node * parent;
    bool root;
    int repeats;
};

struct Node * createTree(int n){
    struct Node * node = malloc(sizeof(struct Node));
    node->key = n;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;
    node->root = true;
    node->repeats = 0;
    return node;
}
bool addNode(int n, struct Node * tree){
    struct Node * temp = tree;
    while(true){
        if(n > temp->key){
            if(temp->right == NULL){
                temp->right = malloc(sizeof(struct Node));
                temp->right->parent = temp;
                temp = temp->right;
                temp->left = NULL;
                temp->right = NULL;
                temp->key = n;
                temp->repeats = 0;
                temp->root == false;
                return true;
            }
            else temp=temp->right;
        }
        else if(n < temp->key){
            if(temp->left == NULL){
                temp->left = malloc(sizeof(struct Node));
                temp->left->parent = temp;
                temp = temp->left;
                temp->right = NULL;
                temp->left = NULL;
                temp->key = n;
                temp->repeats = 0;
                temp->root == false;
                return true;
            }
            else temp=temp->left;
        }
        else{
            temp->repeats += 1;
            return true;
        }
    }
    return false;
}

void findNode(struct Node * tree, int n, int level){
    if(tree == NULL) printf("\nKey not found\n");
    else{
        if(tree->key == n){
                if(!tree->root) printf("\nKey %d found on level %d, under parent %d. Was repeated %d times\n", n, level, tree->parent->key, tree->repeats);
                else printf("\nKey %d found on as root. Was repeated %d times\n", n, tree->repeats);
        }
        else if(n < tree->key) findNode(tree->left, n, level + 1);
        else findNode(tree->right, n, level+1);
    }
}

void printTree (struct Node * tree, int level, int parent) {
    if(tree != NULL) {
        printTree(tree->left, level + 1, tree->key);
        printf("%d | Count: %d |", tree->key, tree->repeats);
        if (level > 0) {
            printf(" Parent: %d | ", parent);
        }
        else {
            printf(" It's root | ");
        }
        printf(" Poziom %d\n", level);
        printTree(tree->right, level + 1, tree->key);
    }
}

bool deleteNode(struct Node * tree, int n){
    if(tree->key == n){
        if(tree->repeats > 0){
            tree->repeats--;
            return true;
        }
        if(tree->root){
            if(tree->right == NULL){
                if(tree->left == NULL){
                    tree = NULL;
                    return true;
                }
                tree->left->parent = NULL;
                tree->left->root = true;
                tree = tree->left;
                return true;
            }
            struct Node * temp = tree;
            while(temp->left != NULL){
                temp=temp->left;
            }
            tree->key = temp->key;
            tree->repeats = temp->repeats;
            temp->parent->left = NULL;
            return true;
        }
    }
}

int main()
{
    struct Node * tree = createTree(18);
    addNode(18, tree);
    addNode(11, tree);
    addNode(6, tree);
    addNode(30, tree);
    addNode(21, tree);
    addNode(19, tree);
    addNode(8, tree);
    addNode(22, tree);
    addNode(23, tree);
    addNode(5, tree);
    addNode(20, tree);
    addNode(26, tree);
    addNode(17, tree);
    printf("\n-----\n");
    printTree(tree, 0, 0);

    findNode(tree, 22, 0);
    findNode(tree, 18, 0);

    deleteNode(tree, 18);
    printf("\n-----\n");

    printTree(tree, 0, 0);
    printf("\n-----\n");

    deleteNode(tree, 18);
    printf("\n-----\n");
    printTree(tree, 0, 0);
    printf("\n-----\n");

    return 0;
}
