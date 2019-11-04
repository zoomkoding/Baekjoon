#include <cstdio>
int n, m, two[100001], dp[1000001];
int main(){
    scanf("%d", &n);
    two[0] = 1, dp[0] = 1;
    for(int i = 1; two[i - 1] <= n; i++)two[i] = two[i - 1] * 2, m++;
    for(int i = 0; i < m; i++){
        for(int j = two[i]; j <= n; j++)dp[j] = (dp[j] + dp[j - two[i]]) % 1000000000;
    }
    printf("%d", dp[n]);
}