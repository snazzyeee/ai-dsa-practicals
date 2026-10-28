// Title: Graph Representation of Flight Paths and Connectivity Check
//
// Problem statement:
// Represent cities or airports as graph nodes, direct flights as edges, and flight costs (time or
// fuel) as edge weights using an adjacency list or adjacency matrix. Accept city names and flight
// costs, display the graph, and check whether a path exists between every pair of cities.

#include <stdio.h>

#define MAX 10

void addFlight(int graph[MAX][MAX], int from, int to, int cost){
    graph[from][to] = cost; // Save the flight cost from the first city to the second.
    graph[to][from] = cost; // Save the return flight because this graph is two-way.
    printf("Flight added.\n");
}

void displayGraph(int n, char cities[MAX][31], int graph[MAX][MAX]){
    for(int i = 0; i < n; i++){ // Print details for every city.
        printf("%s:", cities[i]);
        for(int j = 0; j < n; j++){ // Check all possible destinations.
            if(graph[i][j] != 0) printf(" %s(%d)", cities[j], graph[i][j]); // Print existing flights.
        }
        printf("\n");
    }
}

void dfs(int n, int graph[MAX][MAX], int city, int visited[]){
    visited[city] = 1; // Mark this city as reachable.
    for(int next = 0; next < n; next++){ // Check every possible next city.
        if(graph[city][next] != 0 && !visited[next]) dfs(n, graph, next, visited); // Follow unvisited flights.
    }
}

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
    int n, opt, from, to, cost, connected; // Store input and menu values.

    printf("Number of cities (1-%d): ", MAX);
    if(scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    for(int i = 0; i < n; i++){ // Read every city name.
        printf("City %d name (one word): ", i + 1);
        if(scanf("%30s", cities[i]) != 1) return 1;
    }

    do{
        printf("\n1: Add flight  2: Display graph  3: Check connectivity  4: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;
        if(opt == 1){
            printf("From city number, to city number, cost: ");
            if(scanf("%d %d %d", &from, &to, &cost) != 3) return 1;
            if(from < 1 || from > n || to < 1 || to > n || cost <= 0){
                printf("Invalid city number or cost.\n");
            }else{
                addFlight(graph, from - 1, to - 1, cost); // Convert user numbers to array indices.
            }
        }else if(opt == 2){
            displayGraph(n, cities, graph);
        }else if(opt == 3){
            connected = isConnected(n, graph);
            if(connected >= 0) printf(connected ? "Connected.\n" : "Not connected.\n");
        }else if(opt != 4){
            printf("Invalid option.\n");
        }
    }while(opt != 4);
    return 0;
}

