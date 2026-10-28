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
    int data; // Store the value in this tree node.
    Node *left, *right; // Point to smaller and larger child nodes.
};

Node *insert(Node *root, int value){
    if(root == NULL){
        Node *node = malloc(sizeof *node); // Allocate one new tree node.
        if(node == NULL){
            printf("Memory allocation failed.\n");
            return NULL;
        }
        node->data = value; // Save the inserted value.
        node->left = node->right = NULL; // New nodes start without children.
        return node;
    }
    if(value < root->data) root->left = insert(root->left, value); // Insert smaller values left.
    else if(value > root->data) root->right = insert(root->right, value); // Insert larger values right.
    else printf("Value already exists.\n");
    return root;
}

int height(Node *root){
    if(root == NULL) return 0; // An empty branch has height zero.
    int left = height(root->left), right = height(root->right); // Find both branch heights.
    return 1 + (left > right ? left : right); // Count this node plus the taller branch.
}

int minimum(Node *root, int *value){
    if(root == NULL){
        printf("Tree is empty.\n");
        return 0;
    }
    while(root->left) root = root->left; // The leftmost BST node is the minimum.
    *value = root->data; // Give the minimum back through the pointer.
    return 1;
}

void mirror(Node *root){
    if(root == NULL) return;
    Node *temp = root->left; // Save the old left child.
    root->left = root->right; // Move right child to left.
    root->right = temp; // Move saved left child to right.
    mirror(root->left); // Mirror the new left subtree.
    mirror(root->right); // Mirror the new right subtree.
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

