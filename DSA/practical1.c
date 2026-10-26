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
    
    printf("Enter each student's roll-no: \n");
    for(int i = 0; i < n; i++){
        if(scanf("%d", &stud[i]) != 1) return 0;
    }
    return 1;

}

int store_roll_no_b(int n, int stud[]){
    
    printf("Enter each student's roll-no in ascending (sorted-array): \n");
    for(int i = 0; i < n; i++){
        if(scanf("%d", &stud[i]) != 1) return 0;
        if(i > 0 && stud[i] < stud[i - 1]){
            printf("Roll numbers must be in ascending order.\n");
            return 0;
        }
    }
    return 1;

}

int ask_target(int *tgt){
    printf("Input target: \n");
    return scanf("%d", tgt) == 1;

}

int linearS(int target, int n, int stud[]){
    
    for(int i = 0; i < n; i++){
        if(target == stud[i]){
            return i;
        }
    }
    return -1;
    
}

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

void displaystud(int n, int stud[]){
    for(int i = 0; i < n; i++){
        printf("%d, ", stud[i]);
    }

}

void ui(int n, int stud[]){
    int opt;
    int hasData = 0;
    int idx;
    int target;
    do{
        printf("Which search do you want to use?: \n");
        printf("1: Linear Search \n");
        printf("2: Binary Search \n");
        printf("3: Display Array \n");
        printf("4: Exit \n");
        if(scanf("%d", &opt) != 1) return;

        switch(opt){
            case 1:
            if(!store_roll_no_l(n, stud)) return;
            hasData = 1;
            if(!ask_target(&target)) return;
            idx = linearS(target, n, stud);
            if(idx != -1){
            printf("Found at index %d\n", idx);
            }else{printf("Target not found! :(\n");
            }
            break;
            case 2:
            if(!store_roll_no_b(n, stud)) return;
            hasData = 1;
            if(!ask_target(&target)) return;
            idx = binaryS(target, n, stud);
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

    int n; //stores the number of roll numbers needed to be stored. 
    printf("How many roll numbers do you want to store?\n");
    if(scanf("%d", &n) != 1 || n > 1000 || n < 1){
        printf("Please enter an integer between 1-1000.");
        return -1;
    }
    int stud[n];
    ui(n, stud);

}
