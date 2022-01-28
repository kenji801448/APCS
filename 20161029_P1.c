#include <stdio.h>
#define DEBUG 0
#define LENGTH 3

int a[LENGTH];

void printA() {

    for (int i = 0; i < LENGTH; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort() {

    for (int i = 0; i < LENGTH-1; i++) {
        for (int j = 0; j < LENGTH-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int isTriangle() {

    if (a[0] + a[1] > a[2]) {
        return 1;
    }
    return 0;
}

int main() {

    for (int i = 0; i < LENGTH; i++) {
        scanf("%d", &a[i]);
    }

    if (DEBUG) {
        printA();
    }

    bubbleSort();
    printA();

    if (isTriangle()) {
        int diff = a[0] * a[0] + a[1] * a[1] - a[2] * a[2];
        if (diff < 0) {
            printf("Obtuse\n");
        } else if (diff == 0) {
            printf("Right\n");
        } else {
            printf("Acute\n");
        }
    } else {
        printf("No\n");
    }
}
