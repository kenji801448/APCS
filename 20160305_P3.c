#include <stdio.h>
#define MAX_LENGTH 10000010

int a[MAX_LENGTH];
int N;

int main() {
    
    //initial array a
    for (int i = 0; i < MAX_LENGTH; i++) {
        a[i] = 0;
    }

    //fetch inputs
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int start, end;
        scanf("%d%d", &start, &end);

        //assign 1 to the element if at least one segment cover this place
        for (int j = start; j < end; j++) {
            //1 for has segment
            a[j] = 1;
        }
    }

    //count how many elements had been covered
    int count = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (a[i]) {
            count += 1;
        }
    }
    printf("%d\n", count);
}
