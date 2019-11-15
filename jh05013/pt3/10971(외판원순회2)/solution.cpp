#include <cstdio>
int n, w[10][10], dp[1 << 10][10], ans;

void find(int x){
    if(x == (1 << n) - 1){
        ans = 987654321;
        for(int i = 1; i < n; i++){
            if(dp[x][i] == 987654321 || !w[i][0])continue;
            if(ans > dp[x][i] + w[i][0])ans = dp[x][i] + w[i][0];
        }
        return;
    }
    for(int i = 1; i < n; i++){
        int add = 1 << i, y = add | x;
        if(x == y)continue;
        for(int j = 0; j < n; j++){
            if(dp[x][j] == 987654321 || !w[j][i])continue;
            if(dp[y][i] > dp[x][j] + w[j][i])dp[y][i] = dp[x][j] + w[j][i]; 
        }
    }
    find(x + 1);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < (1 << n) + 1; i++){
        for(int j = 0; j < n; j++)dp[i][j] = 987654321;
    }
    dp[1][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)scanf("%d", &w[i][j]);
    }
    find(1);
    printf("%d", ans);
}