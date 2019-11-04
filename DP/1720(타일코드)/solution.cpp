#include <cstdio>
int n, dp[31], sym[31];
int main(){
    scanf("%d", &n);
    dp[1] = 1, dp[2] = 3, sym[1] = 1, sym[2] = 3, sym[3] = 1, sym[4] = 5;
    for(int i = 3; i <= n; i++)dp[i] = dp[i - 1] + dp[i - 2] * 2;
    for(int i = 5; i <= n; i++)sym[i] = sym[i - 2] + sym[i - 4] * 2;
    printf("%d", (dp[n] - sym[n]) / 2 + sym[n]);
}