#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long t, n, k, dp[101][101][2];
int find(){
    dp[0][0][0] = 1, dp[0][0][1] = 1;
    for(int i = 1; i < n; i ++){
        dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
        dp[i][0][1] = dp[i - 1][0][0];
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0];
        }
    }
    return dp[n - 1][k][0] + dp[n - 1][k][1];
}
int main(){
    scanf("%lld", &t);
    while(t--){
        memset(dp, 0, sizeof(dp));
        scanf("%lld %lld", &n, &k);
        
        printf("%lld\n", find());
    }
}