#include <stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
int maxGoldRecur(int i, int j, int n, int m, int mat[][3]) {
    if (i < 0 || i >= n || j >= m)
        return 0;  
    int ans = 0;
    ans = max(ans, maxGoldRecur(i-1, j+1, n, m, mat));
    ans = max(ans, maxGoldRecur(i, j+1, n, m, mat));
    ans = max(ans, maxGoldRecur(i+1, j+1, n, m, mat));
    return mat[i][j] + ans;
}
int maxGold(int n, int m, int mat[][3]) {
    int ans = 0;
    int i;
    for ( i = 0; i < n; i++) {
        ans = max(ans, maxGoldRecur(i, 0, n, m, mat));
        
    }
    
    return ans;
}

int main() {
    int mat[3][3] = {
        {1, 3, 3},
        {2, 1, 4},
        {0, 6, 4}
    };
    int n = 3, m = 3;
    printf("%d\n", maxGold(n, m, mat));
    return 0;
}
