// Title: Menu-Driven Program to Search Roll Numbers Using Linear and Binary Search
//
// Problem statement:
// Store the roll numbers of students who attended a training program in an array.
// a) Use linear search on the roll numbers stored in random order to check
//    whether a particular student attended the training program.
// b) Use binary search on the roll numbers stored in sorted order to check
//    whether a particular student attended the training program.

#include <stdio.h>

int store_roll_no_l(int n, int stud[]){
    printf("Enter each student's roll-no: \n"); // Ask for unsorted roll numbers.
    for(int i = 0; i < n; i++){ // Visit every array position.
        if(scanf("%d", &stud[i]) != 1) return 0; // Stop on invalid input.
    }
    return 1;

}

int store_roll_no_b(int n, int stud[]){
    printf("Enter each student's roll-no in ascending (sorted-array): \n"); // Binary search needs sorted data.
    for(int i = 0; i < n; i++){ // Read every roll number.
        if(scanf("%d", &stud[i]) != 1) return 0; // Reject non-integer input.
        if(i > 0 && stud[i] < stud[i - 1]){ // Check that this number keeps the array sorted.
            printf("Roll numbers must be in ascending order.\n");
            return 0;
        }
    }
    return 1;

}

int ask_target(int *tgt){
    printf("Input target: \n"); // Ask which roll number to find.
    return scanf("%d", tgt) == 1; // Return 1 only after reading a number.

}

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

void displaystud(int n, int stud[]){
    for(int i = 0; i < n; i++){ // Print every stored roll number.
        printf("%d, ", stud[i]); // Print one element.
    }

}

void ui(int n, int stud[]){
    int opt; // Store the selected menu option.
    int hasData = 0; // Remember whether the array has been filled.
    int idx; // Store the index found by a search.
    int target; // Store the roll number to search for.
    do{
        printf("Which search do you want to use?: \n");
        printf("1: Linear Search \n");
        printf("2: Binary Search \n");
        printf("3: Display Array \n");
        printf("4: Exit \n");
        if(scanf("%d", &opt) != 1) return; // End safely on invalid menu input.

        switch(opt){
            case 1:
            if(!store_roll_no_l(n, stud)) return; // Read random-order values.
            hasData = 1; // Mark that the array now contains values.
            if(!ask_target(&target)) return; // Read the value to find.
            idx = linearS(target, n, stud); // Search each array element.
            if(idx != -1){
            printf("Found at index %d\n", idx);
            }else{printf("Target not found! :(\n");
            }
            break;
            case 2:
            if(!store_roll_no_b(n, stud)) return; // Read ascending values.
            hasData = 1; // Mark that the array now contains values.
            if(!ask_target(&target)) return; // Read the value to find.
            idx = binaryS(target, n, stud); // Search by repeatedly halving the range.
            if(idx != -1){
            printf("Found at index %d\n", idx);
            }else{printf("Target not found! :(\n");
            }
            break;
            case 3:
            if(hasData) displaystud(n, stud);
            else printf("No roll numbers entered yet.\n");
            break;
            case 4:
            opt = 4;
            break;
            default:
            printf("Invalid Option");
        }


    }while(opt != 4);

    printf("Exited.");
}

int main(){

    int n; // Store how many roll numbers the user wants to enter.
    printf("How many roll numbers do you want to store?\n");
    if(scanf("%d", &n) != 1 || n > 1000 || n < 1){
        printf("Please enter an integer between 1-1000.");
        return -1;
    }
    int stud[n]; // Create an array with exactly n roll-number slots.
    ui(n, stud); // Start the menu-driven program.

}
