#include <cstdio>
int n, m, w[31], dp[40001], q, sum;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &w[i]);
        sum += w[i];
    }
    for(int i = 0; i < n; i++){
        int weight = w[i];
        for(int j = sum; j >= weight; j--){
            if(dp[j - weight])dp[j] = 1;
        }
        dp[weight] = 1;
    }
    dp[0] = 1;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &q);
        int yes = 0;
        for(int j = 0; j <= sum - q; j++){
            if(dp[j] && dp[j + q]){
                yes = 1;
                break;
            }
        }
        if(yes)printf("Y ");
        else printf("N ");
        
    }
}