// Title: Implementation and Operations on a Binary Search Tree (BST)
//
// Problem statement:
// Construct a BST from an empty tree by inserting a sequence of values in the given order.
// Support inserting a new node, finding the number of nodes on the longest path from the root,
// finding the minimum value, mirroring the tree by swapping left and right pointers at every
// node, and searching for a value.

#if 1 // change 1 to 0 to use your full-program area below.

#include <stdio.h>

typedef struct Node Node;

// PRACTICE: define the BST node here, including left and right links.

// PSEUDOCODE: write your steps here.
/*





*/

// PRACTICE: insert a value and return the root.
Node *insert(Node *root, int value){
    (void)value;
    printf("TODO: insert a node.\n");
    return root;
}

// PRACTICE: return the number of nodes on the longest root-to-leaf path.
int height(Node *root){
    (void)root;
    printf("TODO: calculate the longest path.\n");
    return -1;
}

// PRACTICE: put the minimum in *value and return 1; return 0 for an empty tree.
int minimum(Node *root, int *value){
    (void)root; (void)value;
    printf("TODO: find the minimum.\n");
    return 0;
}

// PRACTICE: swap the left and right links at every node.
void mirror(Node *root){
    (void)root;
    printf("TODO: mirror the tree.\n");
}

// PRACTICE: return 1 if the value exists, otherwise 0.
int search(Node *root, int value){
    (void)root; (void)value;
    printf("TODO: search the tree.\n");
    return -1;
}

// PRACTICE: free all the nodes.
void freeTree(Node *root){
    (void)root;
    printf("TODO: free the tree.\n");
}

int main(void){
    Node *root = NULL;
    int opt, value, result, mirrored = 0;

    do{
        printf("\n1: Insert  2: Longest path  3: Minimum  4: Mirror\n");
        printf("5: Search  6: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;
        if(mirrored && (opt == 1 || opt == 3 || opt == 5)){
            printf("Mirror the tree back before using BST insert, minimum or search.\n");
        }else if(opt == 1){
            printf("Value to insert: ");
            if(scanf("%d", &value) != 1) return 1;
            root = insert(root, value);
        }else if(opt == 2){
            result = height(root);
            if(result >= 0) printf("Nodes on longest path: %d\n", result);
        }else if(opt == 3){
            if(minimum(root, &value)) printf("Minimum: %d\n", value);
        }else if(opt == 4){
            mirror(root);
            mirrored = !mirrored; // a mirrored tree is not normally ordered as a BST.
        }else if(opt == 5){
            printf("Value to search: ");
            if(scanf("%d", &value) != 1) return 1;
            result = search(root, value);
            if(result >= 0) printf(result ? "Found.\n" : "Not found.\n");
        }else if(opt != 6){
            printf("Invalid option.\n");
        }
    }while(opt != 6);
    freeTree(root);
    return 0;
}

#else

// FULL PROGRAM: write your complete program here when practising from scratch.

#endif
