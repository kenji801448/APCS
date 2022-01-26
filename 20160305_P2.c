#include <stdio.h>
#define MAX_LENGTH 20
#define DEBUG 0

int R, C, M;
int a[MAX_LENGTH][MAX_LENGTH];
int b[MAX_LENGTH][MAX_LENGTH]; //b for backup
int operation[MAX_LENGTH];

//initial one dimensional array arr with -1
void initArray(int arr[]) {

    for (int i = 0; i < MAX_LENGTH; i++) {
        arr[i] = -1;
    }
}

//initial two dimensional array arr with -1 and column of MAX_LENGTH
void init2DArray(int arr[][MAX_LENGTH]) {

    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            arr[i][j] = -1;
        }
    }
}

//initial all the array
void init() {

    initArray(operation);
    init2DArray(a);
    init2DArray(b);
}

//print two dimensional array arr with row of R and column of C
void print2DArray(int arr[][MAX_LENGTH]) {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//print two dimensional array a and b
void print2Array() {

    printf("A:\n");
    print2DArray(a);

    if (DEBUG) { //print temp array b
        printf("B:\n");
        print2DArray(b);
    }
}

//flip operation 
void flip() {

    for (int i = 0; i < R / 2; i++) {
        for (int j = 0; j < C; j++) {
            //swap a[i][j] and a[R-i-1][j]
            int temp = a[i][j];
            a[i][j] = a[R-i-1][j];
            a[R-i-1][j] = temp;
        }
    }
}

//copy array A to array B
void copyA2B() {
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            b[i][j] = a[i][j];
        }
    }
}

//rotate operation
void rotate() {
    
    //copy a to b
    copyA2B();

    //clean out the a array
    init2DArray(a);

    //rotate b to generate new a
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            a[i][j] = b[j][C-1-i];
        }
    }

    //swap R and C
    int temp = R;
    R = C;
    C = temp;

    //clean out the b array
    init2DArray(b);
}

int main() {

    init();

    //fetch inputs
    scanf("%d%d%d", &R, &C, &M);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &operation[i]);
    }

    //iterate the operation array in reverse order
    for (int i = M-1; i >= 0; i--) {
        if (DEBUG) {
            print2Array();
        }

        if (operation[i]) {
            flip();
        } else {
            rotate();
        }
    }

    printf("%d %d\n", R, C);
    print2DArray(a);
}
