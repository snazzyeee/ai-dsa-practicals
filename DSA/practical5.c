// Title: Ticket Booking System of Cinemax Theatre Using a Doubly Linked List
//
// Problem statement:
// Implement a ticket booking system for a theatre with 10 rows and 7 seats per row. Maintain seat
// availability using a doubly linked list for each row and an array of row head pointers, with
// some initial bookings. Support displaying available seats, booking seats, and cancelling
// bookings.

#if 1 // change 1 to 0 to use your full-program area below.

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define SEATS 7

typedef struct Seat Seat;

struct Seat {
    int number, booked;
    Seat *prev, *next;
};

// PSEUDOCODE: write your steps here.
/*





*/

// PRACTICE: allocate and link seven seats in each row, with some initially booked.
int createRows(Seat *rows[ROWS]){
    for(int row = 0; row < ROWS; row++){
        Seat *last = NULL;
        for(int seat = 1; seat <= SEATS; seat++){
            Seat *node = malloc(sizeof *node);
            if(node == NULL) return 0;
            node->number = seat;
            node->booked = (row == 0 && seat == 1) || (row == 2 && seat == 4);
            node->prev = last;
            node->next = NULL;
            if(last) last->next = node;
            else rows[row] = node;
            last = node;
        }
    }
    return 1;
}

// PRACTICE: show the free seats in every row.
void displayAvailable(Seat *rows[ROWS]){
    for(int row = 0; row < ROWS; row++){
        printf("Row %d:", row + 1);
        for(Seat *seat = rows[row]; seat; seat = seat->next){
            if(!seat->booked) printf(" %d", seat->number);
        }
        printf("\n");
    }
}

// PRACTICE: find a seat and book it only if it is free.
void bookSeat(Seat *row, int seat){
    while(row && row->number != seat) row = row->next;
    if(row == NULL) printf("Seat not found.\n");
    else if(row->booked) printf("Seat already booked.\n");
    else{
        row->booked = 1;
        printf("Seat booked.\n");
    }
}

// PRACTICE: find a seat and cancel only an existing booking.
void cancelSeat(Seat *row, int seat){
    while(row && row->number != seat) row = row->next;
    if(row == NULL) printf("Seat not found.\n");
    else if(!row->booked) printf("Seat is not booked.\n");
    else{
        row->booked = 0;
        printf("Booking cancelled.\n");
    }
}

// PRACTICE: free every seat in every row.
void freeRows(Seat *rows[ROWS]){
    for(int row = 0; row < ROWS; row++){
        Seat *seat = rows[row];
        while(seat){
            Seat *next = seat->next;
            free(seat);
            seat = next;
        }
        rows[row] = NULL;
    }
}

int main(void){
    Seat *rows[ROWS] = {NULL};
    int opt, row, seat, ok = 1;
    if(!createRows(rows)){
        printf("Memory allocation failed.\n");
        freeRows(rows);
        return 1;
    }

    do{
        printf("\n1: Available seats  2: Book  3: Cancel  4: Exit\n");
        if(scanf("%d", &opt) != 1){ ok = 0; break; }
        if(opt == 1){
            displayAvailable(rows);
        }else if(opt == 2 || opt == 3){
            printf("Row (1-10) and seat (1-7): ");
            if(scanf("%d %d", &row, &seat) != 2){ ok = 0; break; }
            if(row < 1 || row > ROWS || seat < 1 || seat > SEATS){
                printf("Invalid row or seat.\n");
            }else if(opt == 2){
                bookSeat(rows[row - 1], seat);
            }else{
                cancelSeat(rows[row - 1], seat);
            }
        }else if(opt != 4){
            printf("Invalid option.\n");
        }
    }while(opt != 4);

    freeRows(rows);
    return ok ? 0 : 1;
}

#else

// FULL PROGRAM: write your complete program here when practising from scratch.

#endif
