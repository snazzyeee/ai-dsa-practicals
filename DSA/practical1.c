// Title: Menu-Driven Program to Search Roll Numbers Using Linear and Binary Search
//
// Problem statement:
// Store the roll numbers of students who attended a training program in an array.
// a) Use linear search on the roll numbers stored in random order to check
//    whether a particular student attended the training program.
// b) Use binary search on the roll numbers stored in sorted order to check
//    whether a particular student attended the training program.

#include <stdio.h>

int linearS(int target, int n, int stud[]){
    for(int i = 0; i < n; i++){ // Check elements from the first to the last.
        if(target == stud[i]){ // Compare the target with the current element.
            return i; // Return its index when it matches.
        }
    }
    return -1; // Tell the caller that no match exists.
    
}

int binaryS(int target, int n, int stud[]){
    int low = 0; // Start with the first possible index.
    int high = n-1; // End with the last possible index.
    
    while(low <= high){ // Continue while a search range remains.
        int mid = (high + low)/2; // Find the middle index.
        
        if(target == stud[mid]){
            return mid; // The target is at the middle index.
        }
        else if(target < stud[mid]){
            high = mid - 1; // Discard the larger right half.
        }
        else{
            low = mid + 1; // Discard the smaller left half.
        }
    }
    return -1;
    
}

int main(void){
    int n, choice, target, index;
    int stud[1000]; // Store up to 1000 roll numbers.
    printf("How many roll numbers (1-1000)? ");
    if(scanf("%d", &n) != 1 || n < 1 || n > 1000) return 1;

    do{
        printf("\n1: Linear search  2: Binary search  3: Exit\n");
        if(scanf("%d", &choice) != 1) return 1;
        if(choice != 1 && choice != 2) continue;

        if(choice == 1) printf("Enter each student's roll-no (unsorted):\n");
        else printf("Enter each student's roll-no in ascending order:\n");
        for(int i = 0; i < n; i++){
            if(scanf("%d", &stud[i]) != 1) return 1;
            // Binary search only works when the input is sorted.
            if(choice == 2 && i > 0 && stud[i] < stud[i - 1]){
                printf("Roll numbers must be in ascending order.\n");
                return 1;
            }
        }
        printf("Enter roll number to search: ");
        if(scanf("%d", &target) != 1) return 1;
        if(choice == 1) index = linearS(target, n, stud);
        else index = binaryS(target, n, stud);
        if(index == -1) printf("Roll number not found.\n");
        else printf("Found at index %d\n", index);
    }while(choice != 3);
    return 0;
}
