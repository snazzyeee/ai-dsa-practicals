// Practical 9: Flight graph and connectivity
//
// displayGraph:
// For each city, inspect its row in the adjacency matrix.
// Print every destination with a nonzero flight cost.
//
// dfs:
// Mark the current city as visited.
// For each connected, unvisited city, call dfs recursively.
//
// isConnected:
// Clear the visited array and start dfs from city zero.
// Return false if any city remains unvisited; otherwise return true.
//
// main:
// Start with a zero matrix and read city names.
// Repeat Add flight, Display, Connectivity or Exit using do-while and switch.
// To add a flight, read two city numbers and the cost.
// Subtract one from city numbers and store the cost in both directions.
// Call displayGraph or isConnected for the other operations.
