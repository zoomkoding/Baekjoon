#include <cstdio>
int t, n, dp[1001];
int main(){
    dp[0] = 1, dp[1] = 1, dp[2] = 5;
    for(int i = 3; i < 1001; i++){
        dp[i] = dp[i - 1] + dp[i - 2] * 4;
        for(int j = 3; j <= i; j++)dp[i] += dp[i - j] * 2;
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}