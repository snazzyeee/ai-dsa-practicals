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

// Each node holds one number and pointers to its left and right children.
// In a normal BST, smaller values go left and larger values go right.
struct Node {
    int data; // Store the value in this tree node.
    Node *left, *right; // Point to smaller and larger child nodes.
};

// Follow the appropriate left/right child until reaching NULL, then allocate
// a new node there. Recursion returns each subtree's root to its parent.
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

// The longest path counts nodes, not edges: an empty tree is 0, and a
// single-node tree is 1. Recursively compare the left and right heights.
int height(Node *root){
    if(root == NULL) return 0; // An empty branch has height zero.
    int left = height(root->left), right = height(root->right); // Find both branch heights.
    return 1 + (left > right ? left : right); // Count this node plus the taller branch.
}

void minimum(Node *root){
    if(root == NULL){
        printf("Tree is empty.\n");
        return;
    }
    while(root->left) root = root->left; // The leftmost BST node is the minimum.
    printf("Minimum: %d\n", root->data);
}

// Swapping children at every node reverses the tree. Mirroring it a second
// time restores the original BST ordering used by insert and search.
void mirror(Node *root){
    if(root == NULL) return;
    Node *temp = root->left; // Save the old left child.
    root->left = root->right; // Move right child to left.
    root->right = temp; // Move saved left child to right.
    mirror(root->left); // Mirror the new left subtree.
    mirror(root->right); // Mirror the new right subtree.
}

// Compare at the root and use BST ordering to choose only one subtree.
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
        if(scanf("%d", &opt) != 1) break;
        if(mirrored && (opt == 1 || opt == 3 || opt == 5)){
            printf("Mirror the tree back before using BST insert, minimum or search.\n");
            continue;
        }
        switch(opt){
        case 1:
            printf("Value to insert: ");
            if(scanf("%d", &value) != 1){ opt = 6; break; }
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
            mirrored = !mirrored; // a mirrored tree is not normally ordered as a BST.
            printf("Tree mirrored.\n");
            break;
        case 5:
            printf("Value to search: ");
            if(scanf("%d", &value) != 1){ opt = 6; break; }
            if(search(root, value)) printf("Found.\n");
            else printf("Not found.\n");
            break;
        case 6: break;
        default: printf("Invalid option.\n");
        }
    }while(opt != 6);
    freeTree(root);
    return 0;
}

