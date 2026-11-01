// Title: Sorting First-Year Student Percentages Using Selection Sort and Bubble Sort
//
// Problem statement:
// Store first-year student percentages in an array of floating-point numbers. Sort them in
// ascending order using selection sort and bubble sort, and display the top five scores.

#include <stdio.h>

// Find the smallest value in the unsorted part and swap it into position i.
// The sorted part grows by one position on every pass.
void selectionSort(int n, float arr[]){
    for(int i = 0; i < n - 1; i++){ // Fill one sorted position on each pass.
        int smol = i; // Assume the first unsorted item is the smallest, smallest value's INDEX is stored in smol.
        for(int j = i + 1; j < n; j++){ // Compare it with remaining items.
            if(arr[j] < arr[smol]) smol = j; // Remember a smaller item.
        }
        float temp = arr[i]; // Save the value at position i.
        arr[i] = arr[smol]; // Put the smallest value in its final place.
        arr[smol] = temp; // Complete the swap.
    }
}

// Swap neighboring values whenever they are in the wrong order. After each
// pass, the largest remaining value has moved to its place on the right.
void bubbleSort(int n, float arr[]){
    for(int i = 0; i < n - 1; i++){ // Repeat enough passes to sort the list.
        for(int j = 0; j < n - i - 1; j++){ // Compare adjacent unsorted values.
            if(arr[j] > arr[j + 1]){ // Swap values that are in the wrong order.
                float temp = arr[j]; // Save the left value.
                arr[j] = arr[j + 1]; // Move the smaller right value left.
                arr[j + 1] = temp; // Move the saved value right.
            }
        }
    }
}

int main(void){
    int n, opt; // Store the count and selected menu option.
    printf("Enter number of students (1-1000): ");
    if(scanf("%d", &n) != 1 || n < 1 || n > 1000) return 1;
    float sorted[1000]; // Sort the percentages directly in this one array.

    printf("Enter student percentages:\n");
    for(int i = 0; i < n; i++){ // Read every percentage.
        if(scanf("%f", &sorted[i]) != 1 || sorted[i] < 0 || sorted[i] > 100){
            printf("Invalid percentage.\n");
            return 1;
        }
    }

    do{ // Keep showing the menu until the user exits.
        printf("\n1: Selection Sort  2: Bubble Sort  3: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;// check for integer input
        switch(opt){
        case 1:
        case 2: // Either method sorts this array; repeated sorts still work.
            if(opt == 1) selectionSort(n, sorted); // Run selection sort.
            else bubbleSort(n, sorted); // Run bubble sort.
            printf("Sorted percentages: ");
            for(int i = 0; i < n; i++) printf("%.2f ", sorted[i]);
            printf("\nTop scores: ");
            for(int i = n - 1; i >= 0 && i >= n - 5; i--) printf("%.2f ", sorted[i]); // Read the top five from the end.
            printf("\n");
            break;
        case 3: break;
        default: printf("Invalid option.\n");
        }
    }while(opt != 3);
    return 0;
}
