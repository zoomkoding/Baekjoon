#include <cstdio>
#include <cstring>
long long n, k, dp[1001][1001][2], a, b, m = 1000000003;
int main(){
    scanf("%lld %lld", &n, &k);
    dp[0][0][0] = 1;
    for(int i = 1; i < n; i++){
        dp[i][0][0] = dp[i - 1][0][0];
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % m;
            dp[i][j][1] = dp[i - 1][j - 1][0];
        }
    }
    a =  dp[n - 1][k][0] + dp[n - 1][k][1];
    memset(dp, 0, sizeof(dp));
    dp[0][1][1] = 1;
    for(int i = 1; i < n; i++){
        dp[i][0][0] = dp[i - 1][0][0];
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % m;
            dp[i][j][1] = dp[i - 1][j - 1][0];
        }
    }
    b = dp[n - 1][k][0];
    printf("%lld %lld", a, b);
}