#include <stdio.h>
#define DEBUG 1
#define MAX_LENGTH 200000

int N, M, K;
int survive[MAX_LENGTH];
int bomb;

void initSurvive() {

    for (int i = 0; i < MAX_LENGTH; i++) {
        survive[i] = 1;
    }
}

void init() {

    initSurvive();
    bomb = 0;
}

int nextPlayer() {
    
    if (bomb == N-1) { //go back to the left end if have reach the right end
        bomb = -1;
    }

    while (!survive[bomb+1]) { //search for the nearest survive player
        bomb += 1;
    }
    return bomb+1;
}

void printSurvive() {

    for (int i = 0; i < N; i++) {
        printf("%d ", survive[i]);
    }
    printf("\n");
}

void printAll() {

    printSurvive();
}

int main() {

    init();

    scanf("%d%d%d", &N, &M, &K);

    if (DEBUG) {
        printAll();
    }

    int count = 0;
    while (count != K) {
        for (int i = 0; i < M-1; i++) {
            bomb = nextPlayer();
        }
        survive[bomb] = 0;
        bomb = nextPlayer();
        count += 1;
        if (DEBUG) {
            printAll();
        }
    }

    printf("%d\n", bomb+1);
}
