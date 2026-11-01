// Title: Simulation of a Job Queue in a Pizza Parlour Using a Queue
//
// Problem statement:
// Simulate a pizza parlour that accepts at most M pending orders and serves them in first-come,
// first-served (FCFS) order. Implement enqueue, serve/delete (dequeue), and queue-status display
// operations, handling queue overflow and underflow.

#include <stdio.h>

#define MAX 10

// A circular queue serves the oldest order first (FIFO). front points to
// the oldest order; rear points to where the next order will be inserted.
typedef struct{
    int orders[MAX]; // Store order numbers.
    int front, rear, count; // Track oldest position, next free position and size.
}Queue;

// q is a pointer: q->count accesses the count field of the actual queue.
// Reject an order when count already equals the chosen capacity.
void enqueue(Queue *q, int order, int capacity){
    if(q->count == capacity){
        printf("Queue is full.\n");
        return;
    }
    q->orders[q->rear] = order; // Save the new order at the rear.
    q->rear = (q->rear + 1) % capacity; // Wrap rear to zero after the last slot.
    q->count++; // Record one more waiting order.
    printf("Order %d added.\n", order);
}

// Dequeue serves the front order. The modulo operation wraps the index back
// to 0 after the final slot, letting later orders reuse freed positions.
void dequeue(Queue *q, int capacity){
    if(q->count == 0){
        printf("Queue is empty.\n");
        return;
    }
    printf("Serving order %d.\n", q->orders[q->front]);
    q->front = (q->front + 1) % capacity; // Move front to the next oldest order.
    q->count--; // Record one fewer waiting order.
}

void displayQueue(const Queue *q, int capacity){
    if(q->count == 0){
        printf("Queue is empty.\n");
        return;
    }
    printf("Orders: ");
    for(int i = 0; i < q->count; i++){ // Visit each waiting order in FIFO order.
        printf("%d ", q->orders[(q->front + i) % capacity]); // Wrap indices when needed.
    }
    printf("\n");
}

int main(void){
    Queue q = {0}; // Start with front, rear and count all at zero.
    int capacity, opt, order;

    printf("Maximum pending orders (1-%d): ", MAX);
    if(scanf("%d", &capacity) != 1 || capacity < 1 || capacity > MAX) return 1;

    do{
        printf("\n1: Add order  2: Serve order  3: Display queue  4: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;
        switch(opt){
        case 1:
            printf("Order number: ");
            if(scanf("%d", &order) != 1) return 1;
            enqueue(&q, order, capacity);
            break;
        case 2:
            dequeue(&q, capacity);
            break;
        case 3:
            displayQueue(&q, capacity);
            break;
        case 4: break;
        default: printf("Invalid option.\n");
        }
    }while(opt != 4);
    return 0;
}

