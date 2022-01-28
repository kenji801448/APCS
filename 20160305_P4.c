#include <stdio.h>
#define MAX_LENGTH 100
#define DEBUG 0

int n;
int children[MAX_LENGTH][MAX_LENGTH];
int degree[MAX_LENGTH];
int depth[MAX_LENGTH];

//print out the twodimensional array children with alignment padding
void printChildren() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", children[i][j]);
        }
        printf("\n");
    }
}

//print out one dimensional array
void printArray(int arr[]) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//print out all information, for DEBUG only
void printAll() {

    printf("children:\n");
    printChildren();
    
    printf("degree:\n");
    printArray(degree);
    
    printf("depth:\n");
    printArray(depth);
    printf("\n");
}

//initial children two dimensional array with value of -1
void initChildren() {

    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            children[i][j] = -1;
        }
    }
}

//initial one dimensional array with value of 0
void initArray(int arr[]) {
    
    for (int i = 0; i < MAX_LENGTH; i++) {
        arr[i] = 0;
    }
}

//initial all the variables
void init() {
    
    initChildren();
    initArray(depth);
    initArray(degree);
}

//recursively calculate maximum depth of node
int maxDepthOf(int node) {

    if (degree[node]) { //has at least one child
        int childNode = children[node][0];
        int max_depth = -1;
        for (int i = 0; childNode >= 0; i++) {
            int height_child = maxDepthOf(childNode);
            if (max_depth < height_child) {
                max_depth = height_child;
            }
            childNode = children[node][i];
        }
        return max_depth + 1;
    } else { //has no child
        return 0;
    }
}

int main() {

    init();

    //fetch input and get children and degree arrays ready
    scanf("%d", &n);
    if (DEBUG) {
        printAll();
    }
    for (int i = 0; i < n-1; i++) {
        int parent, child;
        scanf("%d%d", &parent, &child);

        children[parent][degree[parent]] = child;
        degree[parent] += 1;
    }

    if (DEBUG) {
        printAll();
    }

    //get depth array ready
    for (int i = 0; i < n; i++) {
        depth[i] = maxDepthOf(i);
    }

    if (DEBUG) {
        printAll();
    }

    int M = 0;
    //traverse all the nodes for longest distance from any leaf node to the ancestor node 
    //and then go down to another leaf node by different paths
    for (int i = 0; i < n; i++) {
        if (degree[i] > 1) { //only the nodes with degree greater than 1 have different paths
            int largest_distance = 0, largest_distance_2 = 0;
            int childNode = children[i][0];
            for (int j = 0; childNode >= 0; j++) { //visit all the child node of node i
                if (largest_distance < depth[childNode]) {
                    largest_distance_2 = largest_distance;
                    largest_distance = depth[childNode];
                } else if (largest_distance_2 < depth[childNode]) {
                    largest_distance_2 = depth[childNode];
                }
                childNode = children[i][j];
            }
            if (DEBUG) {
                printf("i=%d largest_distance=%d largest_distance_2=%d\n", i, largest_distance, largest_distance_2);
            }

            if (M < largest_distance + largest_distance_2) {
                M = largest_distance + largest_distance_2 + 2;
            }
        }
    }
    printf("%d\n", M);
}
