// Title: Implementation and Operations on a Binary Search Tree (BST)
//
// Problem statement:
// Construct a BST from an empty tree by inserting a sequence of values in the given order.
// Support inserting a new node, finding the number of nodes on the longest path from the root,
// finding the minimum value, mirroring the tree by swapping left and right pointers at every
// node, and searching for a value.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;



struct Node {
    int data; 
    Node *left, *right; 
};



Node *insert(Node *root, int value){
    if(root == NULL){
        
        Node *node = malloc(sizeof *node); 
        node->data = value; 
        node->left = node->right = NULL; 
        return node;
    }
    if(value < root->data) root->left = insert(root->left, value); 
    else if(value > root->data) root->right = insert(root->right, value); 
    else printf("Value already exists.\n");
    return root;
}



int height(Node *root){
    if(root == NULL) return 0; 
    int left = height(root->left), right = height(root->right); 
    return 1 + (left > right ? left : right); 
}

void minimum(Node *root){
    if(root == NULL){
        printf("Tree is empty.\n");
        return;
    }
    while(root->left) root = root->left; 
    printf("Minimum: %d\n", root->data);
}



// Swap both children at every node.
void mirror(Node *root){
    if(root == NULL) return;
    Node *temp = root->left; 
    root->left = root->right; 
    root->right = temp; 
    mirror(root->left); 
    mirror(root->right); 
}


int search(Node *root, int value){
    if(root == NULL) return 0;
    if(root->data == value) return 1;
    if(value < root->data) return search(root->left, value);
    return search(root->right, value);
}

void freeTree(Node *root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void){
    Node *root = NULL;
    int opt, value, mirrored = 0;

    do{
        printf("\n1: Insert  2: Longest path  3: Minimum  4: Mirror\n");
        printf("5: Search  6: Exit\n");
        scanf("%d", &opt);
        if(mirrored && (opt == 1 || opt == 3 || opt == 5)){
            printf("Mirror the tree back before using BST insert, minimum or search.\n");
            continue;
        }
        switch(opt){
        case 1:
            printf("Value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Nodes on longest path: %d\n", height(root));
            break;
        case 3:
            minimum(root);
            break;
        case 4:
            mirror(root);
            mirrored = !mirrored; 
            printf("Tree mirrored.\n");
            break;
        case 5:
            printf("Value to search: ");
            scanf("%d", &value);
            if(search(root, value)) printf("Found.\n");
            else printf("Not found.\n");
            break;
        case 6: break;

        }
    }while(opt != 6);
    freeTree(root);
    return 0;
}

