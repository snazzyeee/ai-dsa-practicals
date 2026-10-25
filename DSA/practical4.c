// Title: Club Member Management Using a Singly Linked List
//
// Problem statement:
// Maintain Pinnacle Club membership for second-, third-, and final-year students using a singly
// linked list storing PRN and name. Reserve the first node for the president and the last for the
// secretary. Support adding and deleting members (including the president and secretary),
// counting and displaying members, and concatenating the lists of two divisions.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};



int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    // Allocate memory for LL in heap
    head = malloc(sizeof *head);
    second = malloc(sizeof *second);
    third = malloc(sizeof *third);

    //link head with second
    head->data = 7;
    head->next = second;

    //link second with third
    second->data = 8;
    second->next = third;

    //third node is end of LL
    third->data = 9;
    third->next = NULL;

    return 0;
}


