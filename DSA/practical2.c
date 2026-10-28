// Title: Sorting First-Year Student Percentages Using Selection Sort and Bubble Sort
//
// Problem statement:
// Store first-year student percentages in an array of floating-point numbers. Sort them in
// ascending order using selection sort and bubble sort, and display the top five scores.

#include <stdio.h>

void selectionSort(int n, float arr[]){
    for(int i = 0; i < n - 1; i++){ // Fill one sorted position on each pass.
        int smol = i; // Assume the first unsorted item is the smallest.
        for(int j = i + 1; j < n; j++){ // Compare it with remaining items.
            if(arr[j] < arr[smol]) smol = j; // Remember a smaller item.
        }
        float temp = arr[i]; // Save the value at position i.
        arr[i] = arr[smol]; // Put the smallest value in its final place.
        arr[smol] = temp; // Complete the swap.
    }
}

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

void displaySorted(int n, const float arr[]){
    printf("Sorted percentages: "); // Print a descriptive heading.
    for(int i = 0; i < n; i++) printf("%.2f ", arr[i]); // Print low to high.
    printf("\nTop scores: "); // Print a heading for the highest values.
    for(int i = n - 1; i >= 0 && i >= n - 5; i--) printf("%.2f ", arr[i]); // Print up to five highest values.
    printf("\n");
}

int main(void){
    int n, opt; // Store the count and selected menu option.
    printf("Enter number of students (1-1000): ");
    if(scanf("%d", &n) != 1 || n < 1 || n > 1000) return 1;
    float original[n], sorted[n]; // Keep original data and a sortable copy.

    printf("Enter student percentages:\n");
    for(int i = 0; i < n; i++){ // Read every percentage.
        if(scanf("%f", &original[i]) != 1 || !(original[i] >= 0 && original[i] <= 100)){
            printf("Invalid percentage.\n");
            return 1;
        }
    }

    do{ // Keep showing the menu until the user exits.
        printf("\n1: Selection Sort  2: Bubble Sort  3: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;
        if(opt == 1 || opt == 2){
            for(int i = 0; i < n; i++) sorted[i] = original[i]; // Restore unsorted input.
            if(opt == 1) selectionSort(n, sorted); // Run selection sort.
            else bubbleSort(n, sorted); // Run bubble sort.
            displaySorted(n, sorted); // Show sorted values and top five.
        }else if(opt != 3){
            printf("Invalid option.\n");
        }
    }while(opt != 3);
    return 0;
}
