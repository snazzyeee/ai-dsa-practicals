// Title: Club Member Management Using a Singly Linked List
//
// Problem statement:
// Maintain Pinnacle Club membership for second-, third-, and final-year students using a singly
// linked list storing PRN and name. Reserve the first node for the president and the last for the
// secretary. Support adding and deleting members (including the president and secretary),
// counting and displaying members, and concatenating the lists of two divisions.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Each node is one member. The head points to the first node, and the
// last node's next pointer is NULL to mark the end of the list.
struct node{
    int prn; // Store the member's PRN.
    char name[31]; // Store a one-word member name.
    struct node *next; // Point to the next member.
};

// Return the head because inserting a president changes the first node.
// The president goes first, secretary last, and members go in between.
struct node *addMember(struct node *head, int prn, const char name[], int role){
    struct node *current = head;

    // A regular member must go between an existing president and secretary.
    if(role == 2 && (head == NULL || head->next == NULL)){
        printf("Add a president and secretary first.\n");
        return head;
    }
    if(role == 3 && head == NULL){
        printf("Add a president first.\n");
        return head;
    }

    struct node *newNode = malloc(sizeof *newNode); // Allocate memory for the new member.
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->prn = prn; // Save the PRN in the new node.
    strcpy(newNode->name, name); // Copy the member name into the node.
    newNode->next = NULL; // New nodes initially have no following node.

    if(role == 1){ // A president goes at the beginning.
        newNode->next = head;
        return newNode;
    }
    if(role == 3){ // A secretary goes at the end.
        while(current->next != NULL) current = current->next;
        current->next = newNode;
    }else{ // A member goes just before the secretary.
        while(current->next->next != NULL) current = current->next;
        newNode->next = current->next; // Connect the new member to secretary.
        current->next = newNode; // Connect the previous member to the new member.
    }
    return head;
}

// Find the matching PRN and reconnect the previous node to the following one.
// If the first node is deleted, return the new first node instead.
struct node *deleteMember(struct node *head, int prn){
    struct node *current = head, *previous = NULL; // Track current and previous nodes.
    while(current && current->prn != prn){
        previous = current; // Remember the current node before moving.
        current = current->next; // Move forward through the list.
    }
    if(current == NULL){
        printf("Member not found.\n");
        return head;
    }
    if(previous) previous->next = current->next; // Skip a middle or last node.
    else head = current->next; // Move head when deleting the president.
    free(current); // Release the deleted node's memory.
    printf("Member deleted.\n");
    return head;
}

void displayMembers(struct node *head){
    int count = 0; // Count members while displaying them.
    for(struct node *current = head; current; current = current->next){
        printf("%d: %s", current->prn, current->name);
        if(current == head) printf(" (president)");
        else if(current->next == NULL) printf(" (secretary)");
        printf("\n");
        count++; // Include this member in the total.
    }
    printf("Total members: %d\n", count);
}

// Join the last node of the first division to the first of the second.
// The combined list's first and last nodes take the two leadership roles.
struct node *concatenate(struct node *first, struct node *second){
    if(first == NULL) return second; // A blank first list becomes the second list.
    struct node *current = first;
    while(current->next) current = current->next; // Find first list's last node.
    current->next = second; // Attach the second division.
    return first;
}

void freeList(struct node *head){
    while(head){ // Continue until every node is freed.
        struct node *next = head->next; // Save next before freeing current node.
        free(head); // Release current node memory.
        head = next; // Move to the saved next node.
    }
}

int main(void){
    struct node *lists[2] = {NULL, NULL};
    int opt, division, prn, role;
    char name[31];

    do{
        printf("\n1: Add member  2: Delete member  3: Display and count\n");
        printf("4: Join divisions  5: Exit\n");
        if(scanf("%d", &opt) != 1) break;
        switch(opt){
        case 1:
        case 2:
        case 3: // These operations first need a division.
            printf("Division (1 or 2): ");
            if(scanf("%d", &division) != 1){ opt = 5; break; }
            if(division < 1 || division > 2){ printf("Invalid division.\n"); break; }
            division--; // Convert division 1 or 2 to array index 0 or 1.
            if(opt == 1){
                printf("Role (1: president, 2: member, 3: secretary): ");
                if(scanf("%d", &role) != 1){ opt = 5; break; }
                if(role < 1 || role > 3){ printf("Invalid role.\n"); break; }
                printf("PRN and name (one word): ");
                if(scanf("%d %30s", &prn, name) != 2){ opt = 5; break; }
                lists[division] = addMember(lists[division], prn, name, role);
            }else if(opt == 2){
                printf("PRN to delete: ");
                if(scanf("%d", &prn) != 1){ opt = 5; break; }
                lists[division] = deleteMember(lists[division], prn);
            }else displayMembers(lists[division]);
            break;
        case 4:
            lists[0] = concatenate(lists[0], lists[1]);
            lists[1] = NULL;
            printf("Divisions joined; first and last nodes are president and secretary.\n");
            break;
        case 5: break;
        default: printf("Invalid option.\n");
        }
    }while(opt != 5);

    freeList(lists[0]);
    freeList(lists[1]);
    return 0;
}


