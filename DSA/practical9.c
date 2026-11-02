// Title: Graph Representation of Flight Paths and Connectivity Check
//
// Problem statement:
// Represent cities or airports as graph nodes, direct flights as edges, and flight costs (time or
// fuel) as edge weights using an adjacency list or adjacency matrix. Accept city names and flight
// costs, display the graph, and check whether a path exists between every pair of cities.

#include <stdio.h>

#define MAX 10



void displayGraph(int n, char cities[MAX][31], int graph[MAX][MAX]){
    for(int i = 0; i < n; i++){ 
        printf("%s:", cities[i]);
        for(int j = 0; j < n; j++){ 
            if(graph[i][j] != 0) printf(" %s(%d)", cities[j], graph[i][j]); 
        }
        printf("\n");
    }
}



// Mark visited cities so we don't follow the same route again.
void dfs(int n, int graph[MAX][MAX], int city, int visited[]){
    visited[city] = 1; 
    for(int next = 0; next < n; next++){ 
        if(graph[city][next] != 0 && !visited[next]) dfs(n, graph, next, visited); 
    }
}



int isConnected(int n, int graph[MAX][MAX]){
    int visited[MAX] = {0}; 
    dfs(n, graph, 0, visited); 
    for(int i = 0; i < n; i++){ 
        if(!visited[i]) return 0; 
    }
    return 1;
}

int main(void){
    int graph[MAX][MAX] = {{0}}; 
    char cities[MAX][31]; 
    int n, opt, from, to, cost; 

    printf("Number of cities (1-%d): ", MAX);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){ 
        printf("City %d name (one word): ", i + 1);
        scanf("%30s", cities[i]);
    }

    do{
        printf("\n1: Add flight  2: Display graph  3: Check connectivity  4: Exit\n");
        scanf("%d", &opt);
        switch(opt){
        case 1:
            printf("From city number, to city number, cost: ");
            scanf("%d %d %d", &from, &to, &cost);
            
            graph[from - 1][to - 1] = graph[to - 1][from - 1] = cost;
            printf("Flight added.\n");
            break;
        case 2:
            displayGraph(n, cities, graph);
            break;
        case 3:
            if(isConnected(n, graph)) printf("Connected.\n");
            else printf("Not connected.\n");
            break;
        case 4: break;

        }
    }while(opt != 4);
    return 0;
}

