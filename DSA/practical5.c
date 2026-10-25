// Title: Ticket Booking System of Cinemax Theatre Using a Doubly Linked List
//
// Problem statement:
// Implement a ticket booking system for a theatre with 10 rows and 7 seats per row. Maintain seat
// availability using a doubly linked list for each row and an array of row head pointers, with
// some initial bookings. Support displaying available seats, booking seats, and cancelling
// bookings.

#if 1 // change 1 to 0 to use your full-program area below.

#include <stdio.h>

#define ROWS 10
#define SEATS 7

typedef struct Seat Seat;

// PRACTICE: define struct Seat here, with seat data and two links.

// PSEUDOCODE: write your steps here.
/*





*/

// PRACTICE: allocate and link seven seats in each row, with some initially booked.
void createRows(Seat *rows[ROWS]){
    (void)rows;
    printf("TODO: create the rows.\n");
}

// PRACTICE: show the free seats in every row.
void displayAvailable(Seat *rows[ROWS]){
    (void)rows;
    printf("TODO: display available seats.\n");
}

// PRACTICE: find a seat and book it only if it is free.
void bookSeat(Seat *row, int seat){
    (void)row; (void)seat;
    printf("TODO: book the seat.\n");
}

// PRACTICE: find a seat and cancel only an existing booking.
void cancelSeat(Seat *row, int seat){
    (void)row; (void)seat;
    printf("TODO: cancel the booking.\n");
}

// PRACTICE: free every seat in every row.
void freeRows(Seat *rows[ROWS]){
    (void)rows;
    printf("TODO: free the rows.\n");
}

int main(void){
    Seat *rows[ROWS] = {NULL};
    int opt, row, seat;
    createRows(rows);

    do{
        printf("\n1: Available seats  2: Book  3: Cancel  4: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;
        if(opt == 1){
            displayAvailable(rows);
        }else if(opt == 2 || opt == 3){
            printf("Row (1-10) and seat (1-7): ");
            if(scanf("%d %d", &row, &seat) != 2) return 1;
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
    return 0;
}

#else

// FULL PROGRAM: write your complete program here when practising from scratch.

#endif
