#include <stdio.h>
#define MAX_LENGTH 5000
#define DEBUG 0

int N;
int friend[MAX_LENGTH];
int visited[MAX_LENGTH];

void initArray(int arr[], int value) {

    for (int i = 0; i < MAX_LENGTH; i++) {
        arr[i] = value;
    }
}

void init() {

    initArray(friend, -1);
    initArray(visited, 0);
}

void printArray(int arr[]) {

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printAll() {

    printf("friend:\n");
    printArray(friend);

    printf("visited:\n");
    printArray(visited);

    printf("\n");
}

int getOne() {

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            return i;
        }
    }
    return -1;
}

int main() {

    init();

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &friend[i]);
    }
    
    int count = 0;
    int current = getOne();
    while (current >= 0) {
        count += 1;

        while (!visited[current]) {
            if (DEBUG) {
                printf("current=%d count=%d\n", current, count);
                printAll();
            }
            visited[current] = 1;
            current = friend[current];
        }
        current = getOne();
    }
    if (DEBUG) {
        printAll();
    }

    printf("%d\n", count);
}
