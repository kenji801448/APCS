#include <stdio.h>
#define DEBUG 0
#define MAX_LENGTH 20

int N, M;
int a[MAX_LENGTH][MAX_LENGTH];
int candidate[MAX_LENGTH];

void initA() {

    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            a[i][j] = 0;
        }
    }
}

void initCandidate() {

    for (int i = 0; i < MAX_LENGTH; i++) {
        candidate[i] = 0;
    }
}

void init() {

    initA();
    initCandidate();
}

void printA() {
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printCandidate() {

    for (int i = 0; i < N; i++) {
        printf("%d ", candidate[i]);
    }
    printf("\n");
}

void printAll() {
    
    printA();
    printCandidate();
}

int main() {
    
    init();

    //fetch input
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    if (DEBUG) {
        printAll();
    }
    //choose the maximum for each row and assign to the candidate array
    for (int i = 0; i < N; i++) {
        int max_of_row_i = a[i][0];
        for (int j = 1; j < M; j++) {
            if (max_of_row_i < a[i][j]) {
                max_of_row_i = a[i][j];
            }
        }
        candidate[i] = max_of_row_i;
    }

    //sum the candidates up
    int S = 0;
    for (int i = 0; i < N; i++) {
        S += candidate[i];
    }
    printf("%d\n", S);

    //try S factors of each candidate
    int hasFactor = 0;
    int first = 1;
    for (int i = 0; i < N; i++) {
        if (S % candidate[i] == 0) {
            if (!first) {
                printf(" ");
            }
            printf("%d", candidate[i]);
            first = 0;
            hasFactor = 1;
        }
    }

    //S have no factor belongs to the candidate array
    if (!hasFactor) {
        printf("-1");
    }
    printf("\n");
}
