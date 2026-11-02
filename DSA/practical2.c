// Title: Sorting First-Year Student Percentages Using Selection Sort and Bubble Sort
//
// Problem statement:
// Store first-year student percentages in an array of floating-point numbers. Sort them in
// ascending order using selection sort and bubble sort, and display the top five scores.

#include <stdio.h>



// Move the smallest remaining value into place.
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

int main(void){
    int n, opt; 
    printf("Enter number of students (1-1000): ");
    scanf("%d", &n);
    float sorted[1000]; 

    printf("Enter student percentages:\n");
    for(int i = 0; i < n; i++){ 
        scanf("%f", &sorted[i]);
    }

    do{ 
        printf("\n1: Selection Sort  2: Bubble Sort  3: Exit\n");
        scanf("%d", &opt);
        switch(opt){
        case 1:
        case 2: 
            if(opt == 1) selectionSort(n, sorted); 
            else bubbleSort(n, sorted); 
            printf("Sorted percentages: ");
            for(int i = 0; i < n; i++) printf("%.2f ", sorted[i]);
            printf("\nTop scores: ");
            for(int i = n - 1; i >= 0 && i >= n - 5; i--) printf("%.2f ", sorted[i]); 
            printf("\n");
            break;
        case 3: break;

        }
    }while(opt != 3);
    return 0;
}
