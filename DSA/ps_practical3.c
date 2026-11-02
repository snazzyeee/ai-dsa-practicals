// Practical 3: Hash table telephone directory
//
// probe:
// Find the starting index using key modulo table size.
// Linear: add the attempt number.
// Quadratic: add the square of the attempt number.
// Double hashing: add attempt number times the second hash value.
// Apply modulo table size to wrap the index.
//
// insert:
// Read the client ID, name and phone; mark the record as used.
// Try at most table-size probe positions.
// Store the record in an empty slot or update a matching ID.
// If no position works, report that no slot was found.
//
// search:
// Read the ID and follow the same probing sequence as insertion.
// Print the details if found; stop at an empty slot.
// Report not found if no matching record exists.
//
// main:
// Choose one probing method for the table.
// Repeat Add/update, Search, Display or Exit using do-while and switch.
// Display only occupied slots.
