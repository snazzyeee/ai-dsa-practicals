// Title: Simulation of a Job Queue in a Pizza Parlour Using a Queue
//
// Problem statement:
// Simulate a pizza parlour that accepts at most M pending orders and serves them in first-come,
// first-served (FCFS) order. Implement enqueue, serve/delete (dequeue), and queue-status display
// operations, handling queue overflow and underflow.

#include <stdio.h>
#define MAX 10

typedef struct{
    int orders[MAX];
    int front, rear, count;
} Queue;

void enqueue(Queue *q, int order, int capacity){
    if(q->count==capacity){
        printf("Overflow.");
        return;
    }

    q->orders[q->rear] = order;
    q->rear = (q->rear + 1) % capacity;
    q->count++
    printf("Order %d added", order);

}
void dequeue(){}

void status(){}

int main(){



}