#include <cstdio>
int n, arr[501][501], x[501], y[501];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d %d", &x[i], &y[i]);
  
    for(int k = 1; k < n; k++){
        for(int i = 0, j = k; j < n; i++, j++){
            int min = 987654321;
            for(int m = i; m < j; m++){
                int cnt = arr[i][m] + arr[m + 1][j] + x[i] * y[m] * y[j];
                if(min > cnt)min = cnt;
            }
            arr[i][j] = min;
        }
    }
    printf("%d", arr[0][n - 1]);
}