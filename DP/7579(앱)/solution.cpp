#include <cstdio>
#include <cstring>
int N, M, m[101], c[101], dp[10001];
int main(){
    scanf("%d %d", &N, &M);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++)scanf("%d", &m[i]);
    for(int i = 0; i < N; i++)scanf("%d", &c[i]);
    for(int i = 0; i < N; i++){
        int cost = c[i];
        for(int j = 10000; j >= cost; j--){
            if(dp[j - cost] == -1)continue;
            if(dp[j - cost] + m[i] > dp[j])dp[j] = dp[j - cost] + m[i];
        }
        if(dp[cost] < m[i])dp[cost] = m[i];
    }
    for(int i = 0; i < 10001; i++){
        if(dp[i] >= M){
            printf("%d", i);
            break;
        }
    }
}

