#include <cstdio>
long long n, k, dp[65][10];
int main(){
    for(int i = 0; i < 10; i++)dp[0][i] = 1;
    for(int i = 1; i < 65; i ++){
        for(int j = 0; j < 10; j ++){
            for(int k = 0; k <= j; k++)dp[i][j]+= dp[i-1][k];
        }
    }
    scanf("%lld", &n);
    while(n--){
        scanf("%lld", &k);
        long long sum = 0;
        for(int i = 0; i < 10; i++)sum += dp[k - 1][i];
        printf("%lld\n", sum);
    }
}