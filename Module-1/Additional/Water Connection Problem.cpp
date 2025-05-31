#include <stdio.h>
#include <limits.h>
#define MAXN 1100
int start[MAXN], end[MAXN], diameter[MAXN];
int ans;
int dfs(int w) {
    if (start[w] == 0) {
        return w;
    }
    if (diameter[w] < ans) {
        ans = diameter[w];
    }
    return dfs(start[w]);
}
void water_connection(int arr[][3], int n, int pipes) {
    int i,j;
	for ( i = 0; i < pipes; i++) {
        start[arr[i][0]] = arr[i][1];
        diameter[arr[i][0]] = arr[i][2];
        end[arr[i][1]] = arr[i][0];
    }
    int st_arr[MAXN], en_arr[MAXN], dm_arr[MAXN];
    int count = 0;
    for ( j = 1; j <= n; j++) {
        if (end[j] == 0 && start[j] != 0) {
            ans = INT_MAX;
            int w = dfs(j);
            st_arr[count] = j;
            en_arr[count] = w;
            dm_arr[count] = ans;
            count++;
        }
    }
      printf("%d\n", count);
    for ( j = 0; j < count; j++) {
        printf("%d %d %d\n", st_arr[j], en_arr[j], dm_arr[j]);
    }
}
int main() {
    int n = 9, pipes = 6;
    int arr[][3] = {{2, 3, 45}, {4, 5, 10}, {5, 8, 22}, {1, 2, 33}, {7, 6, 17}, {3, 7, 66}};
        water_connection(arr, n, pipes);
        return 0;
}
