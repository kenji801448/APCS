#include <stdio.h>
#define MAX_LENGTH 20
#define DEBUG 0

int n;
int a[MAX_LENGTH];

//initial the one dimensional array arr with -1 and length of MAX_LENGTH
void initArray(int arr[]) {

    for (int i = 0; i < MAX_LENGTH; i++) {
        arr[i] = -1;
    }
}

//initial all the array
void init() {

    initArray(a);
}

//print one dimensional array arr with length of n
void printArray(int arr[]) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//implement bubble sort
void bubbleSort() {

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {

    init();

    //fetch inputs
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (DEBUG) {
        printArray(a);
    }

    bubbleSort();
    printArray(a);

    //initial two variable with -1 for NOT existing
    int less_than = -1, greater_than = -1;

    //search for the max score less than 60 points and the min score greater than 60 points
    for (int i = 0; i < n; i++) {
        if (a[i] < 60) {
            less_than = a[i];
        } else {
            greater_than = a[i];
            break;
        }
    }

    //decide whether the less_than score truely exists
    if (less_than < 0) { //score doesn't exists
        printf("best case\n");
    } else { //print out the score
        printf("%d\n", less_than);
    }

    //decide whether the greater_than score truely exists
    if (greater_than < 0) { //score doesn't exists
        printf("worst case\n");
    } else { //print out the score
        printf("%d\n", greater_than);
    }
}
