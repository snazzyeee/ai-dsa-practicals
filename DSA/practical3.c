// Title: Implementation of a Hash Table-Based Telephone Directory Using Collision Resolution Techniques
//
// Problem statement:
// Implement a telephone book for N clients using a hash table to quickly look up a client's
// telephone number. Handle collisions using linear probing, quadratic probing, and double
// hashing.

#include <stdio.h>
#include <stdbool.h>
#define MAX 7

int h1(int key){
    return key%MAX;
}

int h2(int key){
    return 1 + key % (MAX - 1);
}

int sqr(int x){
    return x*x;
}
// idk how to make the hash table
// use of struct?? or array?

typedef struct {
    int clientId; // basically the key.
    char name[31];
    char phone[11];
    bool occupied;
} Client;

Client hash_table[MAX] = {0};

int linearProb(int key, int i){
    // i denotes the interation, so the caller function
    // would have to send over the value of i as well
    // how to increment the value of i over each iteration?
    return (h1(key) + i) % MAX;
    
}
int quadProb(int key, int i){
    return (h1(key) + sqr(i)) % MAX;
    
}
int doubleHash(int key, int i){
    return (h1(key) + i * h2(key)) % MAX;  
}

void linearinsertion(int key){
    int idx;
    for(int i = 0; i<MAX; i++){
    idx = linearProb(key, i);
    }

    // first take the data from the user (client id) linked with the respective phone number and name.
    // client id will be treated as key.

    // where am i taking the client id from the user?

    // need to get client id.

    if(// condition?){
        Store the client ID, name and phone number.
        Mark the slot as occupied.
        Report success and stop.
    }

    else if(occupied==1){ 
        // use linearProb
    }
// if no usable spot found, report that insertion failed.
}

void ui(int ele){
    int opt;
    
    do{
        printf("Which sorting technique do you wanna use?: \n");
        printf("1: Linear Probing \n");
        printf("2: Quadratic Probing \n");
        printf("3: Double Hashing \n");
        printf("4: Exit. \n");
        scanf("%d", &opt);

        switch(opt){
            case 1:
            
            break;
            case 2:
            
            break;
            case 3:
            
            break;
            case 4:
            opt = 4;
            break;
            default:
            printf("Enter valid input.\n");
            
        }
    }while(opt != 4);
}

int main(){
    int ele = noOfele();
    ui(ele);
}