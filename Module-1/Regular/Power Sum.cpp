#include <stdio.h>
#include <math.h>

int powerSumHelper(int X, int N, int num) {
    int power = pow(num, N);
    if (power > X) return 0;
    else if (power == X) return 1;
    else return powerSumHelper(X - power, N, num + 1) + powerSumHelper(X, N, num + 1);
}

int powerSum(int X, int N) {
    return powerSumHelper(X, N, 1);
}

int main() {
    int X, N;
    printf("Enter X: ");
    scanf("%d", &X);
    printf("Enter N: ");
    scanf("%d", &N);
    int result = powerSum(X, N);
    printf("%d\n", result);
    return 0;
}
