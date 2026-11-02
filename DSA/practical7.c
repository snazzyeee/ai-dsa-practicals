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
}Queue;



// Wrap the indices around to reuse empty slots.
void enqueue(Queue *q, int order, int capacity){
    if(q->count == capacity){
        printf("Queue is full.\n");
        return;
    }
    q->orders[q->rear] = order; 
    q->rear = (q->rear + 1) % capacity; 
    q->count++; 
    printf("Order %d added.\n", order);
}



void dequeue(Queue *q, int capacity){
    if(q->count == 0){
        printf("Queue is empty.\n");
        return;
    }
    printf("Serving order %d.\n", q->orders[q->front]);
    q->front = (q->front + 1) % capacity; 
    q->count--; 
}

void displayQueue(Queue *q, int capacity){
    if(q->count == 0){
        printf("Queue is empty.\n");
        return;
    }
    printf("Orders: ");
    for(int i = 0; i < q->count; i++){ 
        printf("%d ", q->orders[(q->front + i) % capacity]); 
    }
    printf("\n");
}

int main(void){
    Queue q = {0}; 
    int capacity, opt, order;

    printf("Maximum pending orders (1-%d): ", MAX);
    scanf("%d", &capacity);

    do{
        printf("\n1: Add order  2: Serve order  3: Display queue  4: Exit\n");
        scanf("%d", &opt);
        switch(opt){
        case 1:
            printf("Order number: ");
            scanf("%d", &order);
            enqueue(&q, order, capacity);
            break;
        case 2:
            dequeue(&q, capacity);
            break;
        case 3:
            displayQueue(&q, capacity);
            break;
        case 4: break;

        }
    }while(opt != 4);
    return 0;
}

