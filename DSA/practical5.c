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



void displayAvailable(Seat *rows[ROWS]){
    for(int row = 0; row < ROWS; row++){ 
        printf("Row %d:", row + 1);
        
        for(Seat *seat = rows[row]; seat != NULL; seat = seat->next){ 
            if(seat->booked == 0) printf(" %d", seat->number); 
        }
        printf("\n");
    }
}






void createRows(Seat *rows[ROWS]){ 
    for(int row = 0; row < ROWS; row++){ 
        Seat *last = NULL; 
        for(int seat = 1; seat <= SEATS; seat++){ 
            Seat *node = malloc(sizeof *node); 

            node->number = seat; 
            node->booked = (row == 0 && seat == 1) || (row == 2 && seat == 4); 
            node->prev = last; 
            node->next = NULL; 
            if(last) last->next = node; 
            else rows[row] = node; 
            last = node; 
        }
    }
}



// book = 1 to reserve a seat, 0 to cancel.
void changeBooking(Seat *row, int seat, int book){
    while(row != NULL && row->number != seat) row = row->next; 
    if(row == NULL) printf("Seat not found.\n");
    
    else if(row->booked == book) printf(book ? "Seat already booked.\n" : "Seat is not booked.\n");
    else{
        row->booked = book; 
        printf(book ? "Seat booked.\n" : "Booking cancelled.\n");
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
    }
}

int main(void){
    Seat *rows[ROWS] = {NULL}; 
    int opt, row, seat;
    createRows(rows);

    
    do{
        printf("\n1: Available seats  2: Book  3: Cancel  4: Exit\n");
        scanf("%d", &opt);
        switch(opt){
        case 1:
            displayAvailable(rows);
            break;
        case 2:
        case 3: 
            printf("Row (1-10) and seat (1-7): ");
            scanf("%d %d", &row, &seat);
            if(opt == 2){
                
                changeBooking(rows[row - 1], seat, 1); 
            }else{
                changeBooking(rows[row - 1], seat, 0); 
            }
            break;
        case 4: break;

        }
    }while(opt != 4);

    freeRows(rows);
    return 0;
}

