#include <cstdio>
int t, n, m; 
int main(){
    scanf("%d", &t);
    while(t--){
        int c[21], dp[10001] = {0,};
        scanf("%d", &n);
        for(int i = 0; i < n; i++)scanf("%d", &c[i]);
        scanf("%d", &m);
        for(int i = 0; i < n; i++){
            dp[c[i]] ++;
            for(int j = 1; j <= m; j++){
                if(j - c[i] < 0)continue;
                dp[j] += dp[j - c[i]];
            }
        }
        printf("%d\n", dp[m]);  
    }
}