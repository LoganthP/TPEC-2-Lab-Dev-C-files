#include <stdio.h>
#include <stdlib.h>
#define MAX_PUMPS 100

int main() {
    int n,i;
    printf("Enter the number of petrol pumps: ");
    scanf("%d", &n);

    int petrol[MAX_PUMPS];
    int distance[MAX_PUMPS];

    printf("Enter the petrol and distance for each pump:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &petrol[i], &distance[i]);
    }

    int start = 0;
    int deficit = 0;
    int capacity = 0;
    for (i = 0; i < n; i++) {
        capacity += petrol[i] - distance[i];
        if (capacity < 0) {
            start = i + 1;
            deficit += capacity;
            capacity = 0;
        }
    }

if (capacity + deficit >= 0) {
        printf("The tour can be completed starting from pump %d.\n", start + 1);
    } else {
        printf("-1\n");
    }

    return 0;
}
