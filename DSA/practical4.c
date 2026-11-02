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
    int prn; 
    char name[31]; 
    struct node *next; 
};



// Keep the president first and secretary last.
struct node *addMember(struct node *head, int prn, char name[], int role){
    struct node *current = head;

    
    if(role == 2 && (head == NULL || head->next == NULL)){
        printf("Add a president and secretary first.\n");
        return head;
    }
    if(role == 3 && head == NULL){
        printf("Add a president first.\n");
        return head;
    }

    
    struct node *newNode = malloc(sizeof *newNode); 
    newNode->prn = prn; 
    strcpy(newNode->name, name); 
    newNode->next = NULL; 

    if(role == 1){ 
        newNode->next = head;
        return newNode;
    }
    if(role == 3){ 
        while(current->next != NULL) current = current->next;
        current->next = newNode;
    }else{ 
        while(current->next->next != NULL) current = current->next;
        newNode->next = current->next; 
        current->next = newNode; 
    }
    return head;
}



struct node *deleteMember(struct node *head, int prn){
    struct node *current = head, *previous = NULL; 
    while(current && current->prn != prn){
        previous = current; 
        current = current->next; 
    }
    if(current == NULL){
        printf("Member not found.\n");
        return head;
    }
    if(previous) previous->next = current->next; 
    else head = current->next; 
    free(current); 
    printf("Member deleted.\n");
    return head;
}

void displayMembers(struct node *head){
    int count = 0; 
    for(struct node *current = head; current; current = current->next){
        printf("%d: %s", current->prn, current->name);
        if(current == head) printf(" (president)");
        else if(current->next == NULL) printf(" (secretary)");
        printf("\n");
        count++; 
    }
    printf("Total members: %d\n", count);
}



struct node *concatenate(struct node *first, struct node *second){
    if(first == NULL) return second; 
    struct node *current = first;
    while(current->next) current = current->next; 
    current->next = second; 
    return first;
}

void freeList(struct node *head){
    while(head){ 
        struct node *next = head->next; 
        free(head); 
        head = next; 
    }
}

int main(void){
    struct node *lists[2] = {NULL, NULL};
    int opt, division, prn, role;
    char name[31];

    do{
        printf("\n1: Add member  2: Delete member  3: Display and count\n");
        printf("4: Join divisions  5: Exit\n");
        scanf("%d", &opt);
        switch(opt){
        case 1:
        case 2:
        case 3: 
            printf("Division (1 or 2): ");
            scanf("%d", &division);

            division--; 
            if(opt == 1){
                printf("Role (1: president, 2: member, 3: secretary): ");
                scanf("%d", &role);

                printf("PRN and name (one word): ");
                scanf("%d %30s", &prn, name);
                lists[division] = addMember(lists[division], prn, name, role);
            }else if(opt == 2){
                printf("PRN to delete: ");
                scanf("%d", &prn);
                lists[division] = deleteMember(lists[division], prn);
            }else displayMembers(lists[division]);
            break;
        case 4:
            lists[0] = concatenate(lists[0], lists[1]);
            lists[1] = NULL;
            printf("Divisions joined; first and last nodes are president and secretary.\n");
            break;
        case 5: break;

        }
    }while(opt != 5);

    freeList(lists[0]);
    freeList(lists[1]);
    return 0;
}


