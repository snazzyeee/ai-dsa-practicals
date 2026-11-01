// Title: Graph Representation of Flight Paths and Connectivity Check
//
// Problem statement:
// Represent cities or airports as graph nodes, direct flights as edges, and flight costs (time or
// fuel) as edge weights using an adjacency list or adjacency matrix. Accept city names and flight
// costs, display the graph, and check whether a path exists between every pair of cities.

#include <stdio.h>

#define MAX 10

// graph[i][j] stores the cost of a direct flight; 0 means no flight.
// This program treats every flight as two-way, so both entries are filled.
void displayGraph(int n, char cities[MAX][31], int graph[MAX][MAX]){
    for(int i = 0; i < n; i++){ // Print details for every city.
        printf("%s:", cities[i]);
        for(int j = 0; j < n; j++){ // Check all possible destinations.
            if(graph[i][j] != 0) printf(" %s(%d)", cities[j], graph[i][j]); // Print existing flights.
        }
        printf("\n");
    }
}

// Depth-first search marks a city, then recursively follows each flight to
// an unvisited city. visited prevents loops when routes lead back again.
void dfs(int n, int graph[MAX][MAX], int city, int visited[]){
    visited[city] = 1; // Mark this city as reachable.
    for(int next = 0; next < n; next++){ // Check every possible next city.
        if(graph[city][next] != 0 && !visited[next]) dfs(n, graph, next, visited); // Follow unvisited flights.
    }
}

// Because flights are two-way, reaching every city from city 0 means every
// city can also reach every other city through some sequence of flights.
int isConnected(int n, int graph[MAX][MAX]){
    int visited[MAX] = {0}; // Start with no city marked reachable.
    dfs(n, graph, 0, visited); // Visit every city reachable from city zero.
    for(int i = 0; i < n; i++){ // Check whether DFS reached every city.
        if(!visited[i]) return 0; // A missed city means the graph is disconnected.
    }
    return 1;
}

int main(void){
    int graph[MAX][MAX] = {{0}}; // Start with no flights in the adjacency matrix.
    char cities[MAX][31]; // Store one name for each city.
    int n, opt, from, to, cost; // Store input and menu values.

    printf("Number of cities (1-%d): ", MAX);
    if(scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    for(int i = 0; i < n; i++){ // Read every city name.
        printf("City %d name (one word): ", i + 1);
        if(scanf("%30s", cities[i]) != 1) return 1;
    }

    do{
        printf("\n1: Add flight  2: Display graph  3: Check connectivity  4: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;
        switch(opt){
        case 1:
            printf("From city number, to city number, cost: ");
            if(scanf("%d %d %d", &from, &to, &cost) != 3) return 1;
            if(from < 1 || from > n || to < 1 || to > n || cost <= 0){
                printf("Invalid city number or cost.\n");
            }else{
                // Subtract 1 to convert city numbers to array indices.
                graph[from - 1][to - 1] = graph[to - 1][from - 1] = cost;
                printf("Flight added.\n");
            }
            break;
        case 2:
            displayGraph(n, cities, graph);
            break;
        case 3:
            if(isConnected(n, graph)) printf("Connected.\n");
            else printf("Not connected.\n");
            break;
        case 4: break;
        default: printf("Invalid option.\n");
        }
    }while(opt != 4);
    return 0;
}

