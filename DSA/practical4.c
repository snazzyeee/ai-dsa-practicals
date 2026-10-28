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

struct node{
    int prn; // Store the member's PRN.
    char name[31]; // Store a one-word member name.
    struct node *next; // Point to the next member.
};

struct node *addMember(struct node *head, int prn, const char name[], int role){
    struct node *current = head; // Start checking at the first member.
    while(current){ // Check every existing member for a duplicate PRN.
        if(current->prn == prn){
            printf("PRN already exists.\n");
            return head;
        }
        current = current->next; // Move to the next member.
    }

    if((role == 1 && head != NULL) ||
       (role == 2 && (head == NULL || head->next == NULL)) ||
       (role == 3 && (head == NULL || head->next != NULL))){
        printf("Add a president first, then a secretary; add members between them.\n");
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

    if(head == NULL) return newNode; // The first node becomes the president.
    if(role == 3){
        head->next = newNode; // Add the secretary after the president.
    }else{
        current = head;
        while(current->next->next != NULL) current = current->next; // Stop before secretary.
        newNode->next = current->next; // Connect the new member to secretary.
        current->next = newNode; // Connect the previous member to the new member.
    }
    return head;
}

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
    int opt, division, prn, role, ok = 1;
    char name[31];

    do{
        printf("\n1: Add member  2: Delete member  3: Display and count\n");
        printf("4: Join divisions  5: Exit\n");
        if(scanf("%d", &opt) != 1){ ok = 0; break; }
        if(opt >= 1 && opt <= 3){
            printf("Division (1 or 2): ");
            if(scanf("%d", &division) != 1){ ok = 0; break; }
            if(division < 1 || division > 2){
                printf("Invalid division.\n");
                continue;
            }
            division--;
            if(opt == 1){
                printf("Role (1: president, 2: member, 3: secretary): ");
                if(scanf("%d", &role) != 1){ ok = 0; break; }
                if(role < 1 || role > 3){ printf("Invalid role.\n"); continue; }
                printf("PRN and name (one word): ");
                if(scanf("%d %30s", &prn, name) != 2){ ok = 0; break; }
                lists[division] = addMember(lists[division], prn, name, role);
            }else if(opt == 2){
                printf("PRN to delete: ");
                if(scanf("%d", &prn) != 1){ ok = 0; break; }
                lists[division] = deleteMember(lists[division], prn);
            }else displayMembers(lists[division]);
        }else if(opt == 4){
            lists[0] = concatenate(lists[0], lists[1]);
            lists[1] = NULL;
            printf("Divisions joined; first and last nodes are president and secretary.\n");
        }else if(opt != 5) printf("Invalid option.\n");
    }while(opt != 5);

    freeList(lists[0]);
    freeList(lists[1]);
    return ok ? 0 : 1;
}


