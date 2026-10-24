// Title: Sorting First-Year Student Percentages Using Selection Sort and Bubble Sort
//
// Problem statement:
// Store first-year student percentages in an array of floating-point numbers. Sort them in
// ascending order using selection sort and bubble sort, and display the top five scores.

#include <stdio.h>

int noOfele(){
    int n;
    printf("Enter number of elements of array: \n");
    scanf("%d", &n);
    return n;
}
void inputUserArr(int ele, int userArr[]){
    int i;
    printf("Enter elements of original (unsorted) array: \n");
    for(i = 0; i < ele; i++){
        scanf("%d", &userArr[i]);
    }

}
void displaySorted(int ele, int sortedArr[]){
    for(int i = 0; i < ele; i++){
        printf("%d\n", sortedArr[i]);
    }
}



void selectionSort(int n, int oArr[]){
//selectionsort algo

for (int i = 0; i < n - 1; i++) {
    int smol = i;

    for (int j = i + 1; j < n; j++) {
        if (oArr[j] < oArr[smol]) {
            smol = j;
        }
    }//keeps checking from after 'i'

    int temp = oArr[i];
    oArr[i] = oArr[smol];
    oArr[smol] = temp;
}
}

void bubbleSort(int n, int oArr[]){

//bubblesort algo
for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; i++){
                       /*^represents the remaining part towards the right of the currently selected index*/
        if(oArr[j]>oArr[j+1]){
            int temp = oArr[j];
            oArr[j] = oArr[j+1];
            oArr[j+1]= temp;
        }
    }
}

}


void ui(){
    int opt;
    int ele = 0;
    ele = noOfele();
    int userArr[ele];
    inputUserArr(ele, userArr);
    do{
        printf("Which sorting technique do you wanna use?: \n");
        printf("1: Selection Sort \n");
        printf("2: Bubble Sort \n");
        printf("3: Display Array \n");
        printf("4: Exit \n");
        scanf("%d", &opt);

        switch(opt){
            case 1:
            selectionSort(ele, userArr);
            break;
            case 2:
            bubbleSort(ele, userArr);
            break;
            case 3:
            displaySorted(ele, userArr);
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
    ui();
    return 0;
}