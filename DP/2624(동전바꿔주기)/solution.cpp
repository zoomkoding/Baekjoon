#include <cstdio>
int t, k, dp[10001], p[101], n[101]; 
int main(){
    scanf("%d %d", &t, &k);
    for(int i = 0; i < k; i++)scanf("%d %d", &p[i], &n[i]);
    dp[0] = 1;
    for(int i = 0; i < k; i++){
        for(int j = t; j >= 0; j--){
            for(int s = 1; s <= n[i]; s++){
                if(j - p[i] * s < 0)continue;
                if(dp[j - p[i] * s])dp[j] += dp[j - p[i] * s];
            }
        }
        
    }
    printf("%d", dp[t]);
}