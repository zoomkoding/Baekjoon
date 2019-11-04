#include <cstdio>
long long n, dp[101];
int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)dp[i] = i;
    for(int i = 4; i <= n; i++){
        long long x = dp[i - 3] * 2;
        for(int j = 0; i + j <= n; j++){
            if(dp[i + j] < x)dp[i + j] = x;
            x += dp[i - 3];
        }
    }
    printf("%lld", dp[n]);
}