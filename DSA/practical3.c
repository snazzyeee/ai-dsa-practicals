// Title: Hash Table-Based Telephone Directory
// Problem statement: Store names and phone numbers using linear probing,
// quadratic probing and double hashing to handle collisions.
#include <stdio.h>
#define MAX 7

struct Client {
    int id, used;
    char name[31], phone[11];
};
struct Client table[MAX];

// A collision means another client already uses the intended slot. i counts
// attempts (0, 1, 2, ...); % MAX wraps an index back into the table.
int probe(int key, int i, int method) {
    int h = key % MAX;
    if (method == 1) return (h + i) % MAX;              // Linear
    if (method == 2) return (h + i * i) % MAX;          // Quadratic
    return (h + i * (1 + key % (MAX - 1))) % MAX;       // Double hashing
}

// Follow the chosen probe sequence until a free or matching ID slot is found.
void insert(int method){
    int index;
    struct Client client;
    printf("Enter non-negative ID, name and phone: ");
    if (scanf("%d %30s %10s", &client.id, client.name, client.phone) != 3 || client.id < 0) return;
    client.used = 1;
    for (int i = 0; i < MAX; i++){
        index = probe(client.id, i, method);
        if (!table[index].used || table[index].id == client.id) {
            table[index] = client; // Copy the entire record, including its name and phone.
            printf("Stored at index %d.\n", index);
            return;
        }
    }
    // Quadratic probing can revisit slots before finding every empty slot.
    printf("No slot found by this probing method.\n");
}

// Search must follow the same probe sequence that insertion used.
void search(int method) {
    int id, index;
    printf("Enter ID: ");
    if (scanf("%d", &id) != 1 || id < 0) return;
    for (int i = 0; i < MAX; i++) {
        index = probe(id, i, method);
        if (!table[index].used) break;
        if (table[index].id == id) {
            printf("%s %s\n", table[index].name, table[index].phone);
            return;
        }
    }
    printf("Client not found.\n");
}

int main(void){
    int method, choice;
    printf("Method: 1 Linear, 2 Quadratic, 3 Double hashing: ");
    scanf("%d", &method);
    do {
        printf("\n1 Add/update  2 Search  3 Display  4 Exit: ");
        scanf("%d", &choice);
        switch (choice){
        case 1: insert(method); break;
        case 2: search(method); break;
        case 3:
            for(int i = 0; i < MAX; i++){
                if (table[i].used == 1)
                    printf("%d: %d %s %s\n", i, table[i].id, table[i].name, table[i].phone);
            }
            break;
        case 4: break;
        default: printf("Invalid option.\n");
        }
    } while (choice != 4);
    return 0;
}
