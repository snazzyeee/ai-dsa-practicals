// Title: Simulation of a Job Queue in a Pizza Parlour Using a Queue
//
// Problem statement:
// Simulate a pizza parlour that accepts at most M pending orders and serves them in first-come,
// first-served (FCFS) order. Implement enqueue, serve/delete (dequeue), and queue-status display
// operations, handling queue overflow and underflow.

#if 1 // change 1 to 0 to use your full-program area below.

#include <stdio.h>

#define MAX 10

// PSEUDOCODE: write your steps here.
/*





*/

// PRACTICE: use these fields or adapt them to your queue implementation.
typedef struct {
    int orders[MAX];
    int front, rear, count;
} Queue;

// PRACTICE: initialize the queue before taking orders.
void initialize(Queue *q){
    (void)q;
    printf("TODO: initialize the queue.\n");
}

// PRACTICE: add an order unless the queue has reached capacity.
void enqueue(Queue *q, int order, int capacity){
    (void)q; (void)order; (void)capacity;
    printf("TODO: enqueue the order.\n");
}

// PRACTICE: serve the oldest order, or report an empty queue.
void dequeue(Queue *q, int capacity){
    (void)q; (void)capacity;
    printf("TODO: dequeue the order.\n");
}

// PRACTICE: display the orders from oldest to newest.
void displayQueue(const Queue *q, int capacity){
    (void)q; (void)capacity;
    printf("TODO: display the queue.\n");
}

int main(void){
    Queue q = {0};
    int capacity, opt, order;

    printf("Maximum pending orders (1-%d): ", MAX);
    if(scanf("%d", &capacity) != 1 || capacity < 1 || capacity > MAX) return 1;
    initialize(&q);

    do{
        printf("\n1: Add order  2: Serve order  3: Display queue  4: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;
        if(opt == 1){
            printf("Order number: ");
            if(scanf("%d", &order) != 1) return 1;
            enqueue(&q, order, capacity);
        }else if(opt == 2){
            dequeue(&q, capacity);
        }else if(opt == 3){
            displayQueue(&q, capacity);
        }else if(opt != 4){
            printf("Invalid option.\n");
        }
    }while(opt != 4);
    return 0;
}

#else

// FULL PROGRAM: write your complete program here when practising from scratch.

#endif
