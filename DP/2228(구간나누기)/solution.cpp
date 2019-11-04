#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF -10000000 
using namespace std;
int n, m, arr[101], dp[101][101][2], ans;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d", &arr[i]);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k < 2; k++)dp[i][j][k] = INF;
        }
    }
    dp[1][1][1] = arr[1];
    for(int i = 2; i <= n; i++){
        dp[i][1][1] = max(arr[i], arr[i] + dp[i - 1][1][1]), dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1]);
        for(int j = 2; j <= m; j++){
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
            dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j][1]);
            if(dp[i][j][1] != INF)dp[i][j][1] += arr[i];
        }
    }
    printf("%d", max(dp[n][m][0], dp[n][m][1]));
}