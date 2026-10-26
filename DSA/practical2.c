// Title: Sorting First-Year Student Percentages Using Selection Sort and Bubble Sort
//
// Problem statement:
// Store first-year student percentages in an array of floating-point numbers. Sort them in
// ascending order using selection sort and bubble sort, and display the top five scores.

#include <stdio.h>

void selectionSort(int n, float arr[]){
    for(int i = 0; i < n - 1; i++){
        int smol = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[smol]) smol = j;
        }
        float temp = arr[i];
        arr[i] = arr[smol];
        arr[smol] = temp;
    }
}

void bubbleSort(int n, float arr[]){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displaySorted(int n, const float arr[]){
    printf("Sorted percentages: ");
    for(int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    printf("\nTop scores: ");
    for(int i = n - 1; i >= 0 && i >= n - 5; i--) printf("%.2f ", arr[i]);
    printf("\n");
}

int main(void){
    int n, opt;
    printf("Enter number of students (1-1000): ");
    if(scanf("%d", &n) != 1 || n < 1 || n > 1000) return 1;
    float original[n], sorted[n];

    printf("Enter student percentages:\n");
    for(int i = 0; i < n; i++){
        if(scanf("%f", &original[i]) != 1 || !(original[i] >= 0 && original[i] <= 100)){
            printf("Invalid percentage.\n");
            return 1;
        }
    }

    do{
        printf("\n1: Selection Sort  2: Bubble Sort  3: Exit\n");
        if(scanf("%d", &opt) != 1) return 1;
        if(opt == 1 || opt == 2){
            // start each method with the original unsorted values.
            for(int i = 0; i < n; i++) sorted[i] = original[i];
            if(opt == 1) selectionSort(n, sorted);
            else bubbleSort(n, sorted);
            displaySorted(n, sorted);
        }else if(opt != 3){
            printf("Invalid option.\n");
        }
    }while(opt != 3);
    return 0;
}
