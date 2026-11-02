// Practical 7: Pizza order circular queue
//
// enqueue:
// If count equals capacity, report full and stop.
// Store the order at rear; advance rear using modulo capacity.
// Increase count and report the added order.
//
// dequeue:
// If count is zero, report empty and stop.
// Serve the order at front; advance front using modulo capacity.
// Decrease count.
//
// displayQueue:
// If empty, report it; otherwise print count orders starting at front.
// Use modulo capacity to wrap each array index.
//
// main:
// Set front, rear and count to zero; read the queue capacity.
// Repeat Add, Serve, Display or Exit using do-while and switch.
// Call the matching queue function for each operation.
