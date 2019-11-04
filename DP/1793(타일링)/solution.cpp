#include <cstdio>
int n;
char dp[251][101];

int main(){
    dp[0][0] = dp[1][0] = 1;
    for(int i = 2; i < 251; i++){
        for(int j = 100; j >= 0; j--){
            int t = dp[i - 2][j] * 2;
            if(t >= 10) dp[i][j + 1] ++, dp[i][j] = t - 10;
            else dp[i][j] = t;
        }
        for(int j = 0; j <= 100; j++){
            int t = dp[i][j] + dp[i - 1][j];
            if(t >= 10) dp[i][j + 1] ++, dp[i][j] = t - 10;
            else dp[i][j] = t;
        }
    }
    while(scanf("%d", &n) == 1){
        int print = 0;
        for(int i = 100; i >= 0; i--){
            if(dp[n][i] != 0)print = 1;
            if(!print)continue;
            printf("%c", '0' + dp[n][i]);
        }
        printf("\n");
    }

}