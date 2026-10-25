// Title: Graph Representation of Flight Paths and Connectivity Check
//
// Problem statement:
// Represent cities or airports as graph nodes, direct flights as edges, and flight costs (time or
// fuel) as edge weights using an adjacency list or adjacency matrix. Accept city names and flight
// costs, display the graph, and check whether a path exists between every pair of cities.

#if 1 // change 1 to 0 to use your full-program area below.

#include <stdio.h>

#define MAX 10

// PSEUDOCODE: write your steps here.
/*





*/

// PRACTICE: represent each direct flight and its cost in the matrix.
// This practice menu uses two-way flights and positive costs.
void addFlight(int graph[MAX][MAX], int from, int to, int cost){
    (void)graph; (void)from; (void)to; (void)cost;
    printf("TODO: add the flight.\n");
}

// PRACTICE: print the cities and their connected cities with costs.
void displayGraph(int n, char cities[MAX][31], int graph[MAX][MAX]){
    (void)n; (void)cities; (void)graph;
    printf("TODO: display the graph.\n");
}

// PRACTICE: use DFS or BFS; return 1 if every city is reachable, otherwise 0.
int isConnected(int n, int graph[MAX][MAX]){
    (void)n; (void)graph;
    printf("TODO: check connectivity.\n");
    return -1;
}

int main(void){
    int graph[MAX][MAX] = {{0}};
    char cities[MAX][31];
    int n, opt, from, to, cost, connected;

    printf("Number of cities (1-%d): ", MAX);
    if(scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    for(int i = 0; i < n; i++){
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
                addFlight(graph, from - 1, to - 1, cost);
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

#else

// FULL PROGRAM: write your complete program here when practising from scratch.

#endif
