#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pesticide;
    int days;
} Plant;

int poisonousPlants(int n, int* p) {
    Plant* stack = (Plant*)malloc(n * sizeof(Plant));
    int top = -1, max_days = 0;
    int i;
    for (i = 0; i < n; i++) {
        int days = 0;
        while (top >= 0 && stack[top].pesticide >= p[i]) {
            days = days > stack[top].days ? days : stack[top].days;
            top--;
        }
        if (top >= 0) {
            days++;
        } else {
            days = 0;
        }
        max_days = days > max_days ? days : max_days;
        stack[++top] = (Plant){p[i], days};
    }
    free(stack);
    return max_days;
}

int main() {
    int n,i;
    scanf("%d", &n);
    int* p = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    int result = poisonousPlants(n, p);
    printf("%d\n", result);
    free(p);
    return 0;
}
