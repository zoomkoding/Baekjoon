#include <cstdio>

int n, m, k, x1, y1, x2, y2, arr[301][301], dp[301][301];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)scanf("%d", &arr[i][j]);
    }
    for(int i = 0; i < m; i++)dp[0][i] = arr[0][i];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++)dp[i][j] = arr[i][j] + dp[i-1][j];
    }

    scanf("%d", &k);
    while(k--){
        int ans = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i = y1 - 1; i <= y2 - 1; i++){
            if(x1 - 2 >= 0) ans += dp[x2 - 1][i] - dp[x1 - 2][i];
            else ans += dp[x2 - 1][i];
        }
        printf("%d\n", ans);
    }

}