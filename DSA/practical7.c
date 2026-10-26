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
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

// PRACTICE: add an order unless the queue has reached capacity.
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

// PRACTICE: serve the oldest order, or report an empty queue.
void dequeue(Queue *q, int capacity){
    if(q->count == 0){
        printf("Queue is empty.\n");
        return;
    }
    printf("Serving order %d.\n", q->orders[q->front]);
    q->front = (q->front + 1) % capacity;
    q->count--;
}

// PRACTICE: display the orders from oldest to newest.
void displayQueue(const Queue *q, int capacity){
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
