#include <stdio.h>
#define DEBUG 0

int infor[9][5];
int base[3];
int score, out, b;

void initInfor() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 5; j++) {
            infor[i][j] = -1;
        }
    }
}

void initBase() {

    for (int i = 0; i < 3; i++) {
        base[i] = 0;
    }
}

void init() {

    initInfor();
    initBase();
}

void printInfor() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", infor[i][j]);
        }
        printf("\n");
    }
}

void printBase() {

    for (int i = 0; i < 3; i++) {
        printf("%d ", base[i]);
    }
    printf("\n");
}

void printAll() {
    
    printf("infor:\n");
    printInfor();

    printf("base:\n");
    printBase();

    printf("score=%d out=%d b=%d\n", score, out, b);
    printf("\n");
}

void moveOneBase() {

    if (base[2]) { //third base runner go home
        score += 1;
        base[2] = 0;
    }
    base[2] = base[1]; //2 -> 3
    base[1] = base[0]; //1 -> 2
    base[0] = 0; //clear the first base
}

void push(int number) {
    
    for (int i = 0; i < number; i++) {
        moveOneBase();
    }

    //handle the batter
    if (number == 4) { //home run
        score += 1;
    } else {
        //the batter take the base of number-1
        base[number-1] = 1;
    }
}

void process() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            int temp = infor[j][i];
            if (DEBUG) {
                printf("temp=%d\n", temp);
            }
            if (temp) { //hit
                push(temp);
            } else { //out
                out += 1;
                if (out == b) { //reach the condition
                    return;
                }
                if (out % 3 == 0) { //change 
                    initBase();
                }
            }
            if (DEBUG) {
                printAll();
            }
        }
    }
}

int main() {

    init();

    //fetch input
    for (int i = 0; i < 9; i++) {
        int a;
        scanf("%d", &a);
        for (int j = 0; j < a; j++) {
            char str[3];
            scanf("%s", str);
            switch (str[0]) {
                case '1': //one-base hit
                    infor[i][j] = 1;
                    break;
                case '2': //two-base hit
                    infor[i][j] = 2;
                    break;
                case '3': //three-base hit
                    infor[i][j] = 3;
                    break;
                case 'H': //homerun
                    infor[i][j] = 4;
                    break;
                default: //out
                    infor[i][j] = 0;
            }
        }
    }
    scanf("%d", &b);

    if (DEBUG) {
        printAll();
    }

    process();
    printf("%d\n", score);
}
