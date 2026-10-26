// Title: Implementation and Operations on a Binary Search Tree (BST)
//
// Problem statement:
// Construct a BST from an empty tree by inserting a sequence of values in the given order.
// Support inserting a new node, finding the number of nodes on the longest path from the root,
// finding the minimum value, mirroring the tree by swapping left and right pointers at every
// node, and searching for a value.

#if 1 // change 1 to 0 to use your full-program area below.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node *left, *right;
};

// PSEUDOCODE: write your steps here.
/*





*/

// PRACTICE: insert a value and return the root.
Node *insert(Node *root, int value){
    if(root == NULL){
        Node *node = malloc(sizeof *node);
        if(node == NULL){
            printf("Memory allocation failed.\n");
            return NULL;
        }
        node->data = value;
        node->left = node->right = NULL;
        return node;
    }
    if(value < root->data) root->left = insert(root->left, value);
    else if(value > root->data) root->right = insert(root->right, value);
    else printf("Value already exists.\n");
    return root;
}

// PRACTICE: return the number of nodes on the longest root-to-leaf path.
int height(Node *root){
    if(root == NULL) return 0;
    int left = height(root->left), right = height(root->right);
    return 1 + (left > right ? left : right);
}

// PRACTICE: put the minimum in *value and return 1; return 0 for an empty tree.
int minimum(Node *root, int *value){
    if(root == NULL){
        printf("Tree is empty.\n");
        return 0;
    }
    while(root->left) root = root->left;
    *value = root->data;
    return 1;
}

// PRACTICE: swap the left and right links at every node.
void mirror(Node *root){
    if(root == NULL) return;
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

// PRACTICE: return 1 if the value exists, otherwise 0.
int search(Node *root, int value){
    if(root == NULL) return 0;
    if(root->data == value) return 1;
    if(value < root->data) return search(root->left, value);
    return search(root->right, value);
}

// PRACTICE: free all the nodes.
void freeTree(Node *root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void){
    Node *root = NULL;
    int opt, value, result, mirrored = 0, ok = 1;

    do{
        printf("\n1: Insert  2: Longest path  3: Minimum  4: Mirror\n");
        printf("5: Search  6: Exit\n");
        if(scanf("%d", &opt) != 1){ ok = 0; break; }
        if(mirrored && (opt == 1 || opt == 3 || opt == 5)){
            printf("Mirror the tree back before using BST insert, minimum or search.\n");
        }else if(opt == 1){
            printf("Value to insert: ");
            if(scanf("%d", &value) != 1){ ok = 0; break; }
            root = insert(root, value);
        }else if(opt == 2){
            result = height(root);
            if(result >= 0) printf("Nodes on longest path: %d\n", result);
        }else if(opt == 3){
            if(minimum(root, &value)) printf("Minimum: %d\n", value);
        }else if(opt == 4){
            mirror(root);
            mirrored = !mirrored; // a mirrored tree is not normally ordered as a BST.
            printf("Tree mirrored.\n");
        }else if(opt == 5){
            printf("Value to search: ");
            if(scanf("%d", &value) != 1){ ok = 0; break; }
            result = search(root, value);
            if(result >= 0) printf(result ? "Found.\n" : "Not found.\n");
        }else if(opt != 6){
            printf("Invalid option.\n");
        }
    }while(opt != 6);
    freeTree(root);
    return ok ? 0 : 1;
}

#else

// FULL PROGRAM: write your complete program here when practising from scratch.

#endif
