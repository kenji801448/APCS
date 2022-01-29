#include <stdio.h>
#define MAX_LENGTH 50
#define DEBUG 0

int N, direction;
int a[MAX_LENGTH][MAX_LENGTH];
int row, col;
int boundary_upper, boundary_bottom, boundary_left, boundary_right;

//0:left, 1:up, 2:right, 3:down
int delta_row[4] = {0, -1, 0, 1};
int delta_col[4] = {-1, 0, 1, 0};

void initA() {

    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            a[i][j] = -1;
        }
    }
}

void init() {

    initA();
}

void printA() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int shoudlTurnRound() {
    
    switch (direction) {
        case 0:
            if (boundary_left - col > 1) {
                boundary_left -= 1;
                return 1;
            }
        case 1:
            if (boundary_upper - row > 1) {
                boundary_upper -= 1;
                return 1;
            }
        case 2:
            if (col - boundary_right > 1) {
                boundary_right += 1;
                return 1;
            }
        case 3:
            if (row - boundary_bottom > 1) {
                boundary_bottom += 1;
                return 1;
            }
    }
    return 0;
}

int main() {

    init();
    if (DEBUG) {
        printA();
    }
    
    scanf("%d%d", &N, &direction);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    if (DEBUG) {
        printA();
    }

    row = col = N/2;
    boundary_left = boundary_upper = boundary_right = boundary_bottom = N/2;

    while (boundary_left >= 0 && boundary_upper >= 0 && boundary_right < N && boundary_bottom < N) {
        if (row < 0 || row == N || col < 0 || col == N) {
            break;
        }
        printf("%d", a[row][col]);
        if (DEBUG) {
            printf("boundary_left=%d boundary_upper=%d boundary_right=%d, boundary_bottom=%d\n", boundary_left, boundary_upper, boundary_right, boundary_bottom);
        }
        row += delta_row[direction];
        col += delta_col[direction];

        if (shoudlTurnRound()) {
            row -= delta_row[direction];
            col -= delta_col[direction];
            direction = (direction + 1) % 4;
            row += delta_row[direction];
            col += delta_col[direction];
        }
    }
    printf("\n");
}
