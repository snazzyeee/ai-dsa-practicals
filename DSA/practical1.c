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
    for(int i = 0; i < n; i++){ 
        if(target == stud[i]){ 
            return i; 
        }
    }
    return -1; 
    
}



// Binary search needs sorted roll numbers.
int binaryS(int target, int n, int stud[]){
    int low = 0; 
    int high = n-1; 
    
    while(low <= high){ 
        int mid = (high + low)/2; 
        
        if(target == stud[mid]){
            return mid; 
        }
        else if(target < stud[mid]){
            high = mid - 1; 
        }
        else{
            low = mid + 1; 
        }
    }
    return -1;
    
}

int main(void){
    int n, choice, target, index;
    int stud[1000]; 
    printf("How many roll numbers (1-1000)? ");
    scanf("%d", &n);

    do{
        printf("\n1: Linear search  2: Binary search  3: Exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
        case 2: 
        if(choice == 1) printf("Enter each student's roll-no (unsorted):\n");
        else printf("Enter each student's roll-no in ascending order:\n");
        for(int i = 0; i < n; i++){
            scanf("%d", &stud[i]);
        }
        printf("Enter roll number to search: ");
        scanf("%d", &target);
        if(choice == 1) index = linearS(target, n, stud);
        else index = binaryS(target, n, stud);
        if(index == -1) printf("Roll number not found.\n");
        else printf("Found at index %d\n", index);
        break;
        case 3: break; 

        }
    }while(choice != 3);
    return 0;
}
