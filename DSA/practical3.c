// Title: Hash Table-Based Telephone Directory
//
// Problem statement:
// Store clients' names and phone numbers using a hash table.
// Handle collisions using linear probing, quadratic probing and double hashing.

#include <stdio.h>
#include <string.h>

#define MAX 7 // Fix the hash table size.

// client IDs are the keys; the other arrays hold the matching details.
int H[MAX];
int occupied[MAX];
char names[MAX][31];
char phones[MAX][11];

int h1(int key){
    return key % MAX; // Map a key to its first table index.
}

int h2(int key){
    return 1 + key % (MAX - 1); // Create a non-zero second hash step.
}

int sqr(int x){
    return x*x;
}

int linearProb(int key, int i){
    return (h1(key) + i) % MAX; // Move one slot for every collision.
}

int quadProb(int key, int i){
    return (h1(key) + sqr(i)) % MAX; // Move by squared attempt numbers.
}

int doubleHash(int key, int i){
    return (h1(key) + i * h2(key)) % MAX; // Move by a second hash step.
}

int probe(int key, int i, int method){
    if(method == 1) return linearProb(key, i); // Use linear probing when selected.
    if(method == 2) return quadProb(key, i); // Use quadratic probing when selected.
    return doubleHash(key, i); // main only allows methods 1, 2 and 3.
}

// returns 0 if input fails; otherwise the menu can continue.
int insertClient(int method){
    // gets client data from the user, iterates over collisions if any and calls probe(,,method)
    int key; // Store the client's ID.
    char name[100], phone[100]; // Read input before copying it into table-sized arrays.

    printf("Enter client ID (non-negative): ");
    if(scanf("%d", &key) != 1 || key < 0){
        printf("Invalid client ID.\n");
        return 0;
    }

    printf("Enter client name: ");
    if(scanf("%99s", name) != 1 || strlen(name) > 30){
        printf("Invalid name.\n");
        return 0;
    }

    printf("Enter phone: ");
    if(scanf("%99s", phone) != 1 || strlen(phone) > 10 ||
       strspn(phone, "0123456789") != strlen(phone)){
        printf("Invalid phone number.\n");
        return 0;
    }

    // i is the attempt number, try another slot when there is a collision.
    for(int i = 0; i < MAX; i++){ // Try every possible probe position.
        int idx = probe(key, i, method); // Calculate this attempt's table index.

        // an existing ID is updated instead of adding a duplicate.
        if(occupied[idx] == 0 || H[idx] == key){
            H[idx] = key; // Store the client's ID.
            strcpy(names[idx], name); // Store the matching name.
            strcpy(phones[idx], phone); // Store the matching phone number.
            occupied[idx] = 1; // Mark this table slot as used.
            printf("Client stored at index %d.\n", idx);
            return 1;
        }// if occupied == 1 then i increments anyways
    }

    // shortcut: quadratic probing may miss empty slots; use another method for full coverage.
    printf("No available slot found by this probing method.\n");
    return 1;
}

int searchClient(int key, int method){
    // search follows the same sequence used while inserting the key.
    for(int i = 0; i < MAX; i++){ // Follow the same sequence used by insertion.
        int idx = probe(key, i, method); // Get the next table index.
        if(occupied[idx] == 0) return -1;
        if(H[idx] == key) return idx;
    }
    return -1;
}

void display(){
    for(int i = 0; i < MAX; i++){ // Print all table positions.
        if(occupied[i] == 1){
            printf("%d: ID %d | %s | %s\n", i, H[i], names[i], phones[i]);
        }else{
            printf("%d: Empty\n", i);
        }
    }
}

int main(void){
    int method, opt, key; // Store the probing method, menu choice and ID.

    printf("Choose a collision handling method:\n");
    printf("1: Linear Probing\n2: Quadratic Probing\n3: Double Hashing\n");
    if(scanf("%d", &method) != 1 || method < 1 || method > 3){
        printf("Invalid method.\n");
        return 1;
    }

    // use one method for this table, so search retraces insertion's steps.
    do{
        printf("\n1: Add or update client\n2: Search by client ID\n3: Display table\n4: Exit\n");
        if(scanf("%d", &opt) != 1){
            printf("Invalid option.\n");
            return 1;
        }

        switch(opt){
            case 1:
                if(!insertClient(method)) return 1;
                break;
            case 2: {
                printf("Enter client ID: ");
                if(scanf("%d", &key) != 1 || key < 0){
                    printf("Invalid client ID.\n");
                    return 1;
                }
                int idx = searchClient(key, method);
                if(idx == -1){
                    printf("Client not found.\n");
                }else{
                    printf("Name: %s | Phone: %s\n", names[idx], phones[idx]);
                }
                break;
            }
            case 3:
                display();
                break;
            case 4:
                printf("Exited.\n");
                break;
            default:
                printf("Enter a valid option.\n");
        }
    }while(opt != 4);

    return 0;
}
