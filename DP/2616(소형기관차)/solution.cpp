#include <cstdio>
#include <algorithm>
using namespace std;
long long n, m, t[50001], dp[4][50001];
int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)scanf("%lld", &t[i]);
    for(int i = 2; i <= n; i++)t[i] += t[i-1];
    scanf("%lld", &m);
    for(int i = 1; i <= 3; i++){
        for(int j = i * m; j <= n; j++){
            long long sum = t[j] - t[j - m];
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + sum); 
        }
    }
    printf("%lld", dp[3][n]);
}