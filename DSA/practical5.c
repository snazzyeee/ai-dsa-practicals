// Title: Ticket Booking System of Cinemax Theatre Using a Doubly Linked List
//
// Problem statement:
// Implement a ticket booking system for a theatre with 10 rows and 7 seats per row. Maintain seat
// availability using a doubly linked list for each row and an array of row head pointers, with
// some initial bookings. Support displaying available seats, booking seats, and cancelling
// bookings.

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define SEATS 7

typedef struct Seat Seat;

struct Seat {
    int number, booked;
    Seat *prev, *next;
};

int createRows(Seat *rows[ROWS]){
    for(int row = 0; row < ROWS; row++){ // Create one linked list for every theatre row.
        Seat *last = NULL; // Track the previous seat while building a row.
        for(int seat = 1; seat <= SEATS; seat++){ // Create the seven seats in this row.
            Seat *node = malloc(sizeof *node); // Allocate memory for one seat.
            if(node == NULL) return 0; // Report failure when memory is unavailable.
            node->number = seat; // Store this seat number.
            node->booked = (row == 0 && seat == 1) || (row == 2 && seat == 4); // Add initial bookings.
            node->prev = last; // Link backwards to the previous seat.
            node->next = NULL; // The new seat has no next seat yet.
            if(last) last->next = node; // Link the previous seat forward.
            else rows[row] = node; // Save the first seat as the row head.
            last = node; // Make this seat the previous seat for the next loop.
        }
    }
    return 1;
}

void displayAvailable(Seat *rows[ROWS]){
    for(int row = 0; row < ROWS; row++){ // Visit each theatre row.
        printf("Row %d:", row + 1);
        for(Seat *seat = rows[row]; seat; seat = seat->next){ // Move through the row's list.
            if(!seat->booked) printf(" %d", seat->number); // Print only free seats.
        }
        printf("\n");
    }
}

void bookSeat(Seat *row, int seat){
    while(row && row->number != seat) row = row->next; // Find the requested seat node.
    if(row == NULL) printf("Seat not found.\n");
    else if(row->booked) printf("Seat already booked.\n");
    else{
        row->booked = 1; // Mark the available seat as booked.
        printf("Seat booked.\n");
    }
}

void cancelSeat(Seat *row, int seat){
    while(row && row->number != seat) row = row->next; // Find the requested seat node.
    if(row == NULL) printf("Seat not found.\n");
    else if(!row->booked) printf("Seat is not booked.\n");
    else{
        row->booked = 0; // Mark the booked seat as free.
        printf("Booking cancelled.\n");
    }
}

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

