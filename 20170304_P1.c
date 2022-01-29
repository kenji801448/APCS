#include <stdio.h>
#define MAX_LENGTH 1010
#define DEBUG 0

char X[MAX_LENGTH];
int A, B;

void printX() {

    for (int i = 0; X[i] != '\0'; i++) {
        printf("%c", X[i]);
    }
    printf("\n");
}

void initX() {
    
    for (int i = 0; i < MAX_LENGTH; i++) {
        X[i] = '\0';
    }
}

int main() {

    initX();

    char temp;
    for (int i = 0; ; i++) {
        scanf("%c", &temp);
        if (temp == '\n') {
            X[i] = '\0';
            break;
        } else {
            X[i] = temp;
        }
    }

    if (DEBUG) {
        printX();
    }

    int diff = 0;
    for (int i = 0; X[i] != '\0'; i++) {
        if (i % 2) { //odd
            diff += X[i] - 48; //from char to int
        } else {
            diff -= X[i] - 48; //from char to int
        }
        if (DEBUG) {
            printf("%d\n", diff);
        }
    }

    printf("%d\n", diff < 0 ? diff * -1 : diff);
}
