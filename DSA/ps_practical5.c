// Practical 5: Theatre booking with doubly linked lists
//
// displayAvailable:
// For each row, start at its head and follow next until NULL.
// Print the numbers of seats whose booked flag is zero.
//
// createRows:
// For each of ten rows, create seven seat nodes.
// Store the seat number and mark the initial bookings.
// Connect each node to the previous seat in both directions.
// Save the first node in the row's head pointer.
//
// changeBooking:
// Follow the row's list until the requested seat is found.
// If absent, report not found; if already in the requested state, report it.
// Otherwise set booked to 1 for booking or 0 for cancellation.
//
// freeRows:
// For every row, save next, free the current seat and move to next.
// Repeat until all seat nodes are freed.
//
// main:
// Create the theatre rows.
// Repeat Display, Book, Cancel or Exit using do-while and switch.
// For booking or cancelling, read row and seat and call changeBooking.
// Convert the user's row number to an array index by subtracting one.
// Free all rows on exit.
