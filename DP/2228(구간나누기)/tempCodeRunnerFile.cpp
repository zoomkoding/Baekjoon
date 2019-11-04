#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF -10000000 
using namespace std;
int n, m, arr[101], dp[101][101][2], ans;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < 2; k++)dp[i][j][k] = INF;
        }
    }
    for(int i = 1; i <= n; i++)scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++){
        dp[i][1][1] = max(arr[i] + dp[i - 1][1][1], arr[i]); dp[i][1][0] = max(dp[i - 1][1][1], dp[i - 1][1][0]);
        for(int j = 2; j <= m; j++){
            //이번 원소를 선택하지 않는다면
            //이전에 j개 있던 경우 중 제일 큰 경우를 가지고 있으면 되지
            if(dp[i - 1][j][0] != INF)dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
            if(dp[i - 1][j][1] != INF)dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1]);
            //선택한다면
            //이전에 j개 있던 경우 중 선택한 경우나 이전에 j - 1개 있던 경우 중 선택 안한 경우
            if(dp[i - 1][j - 2][1] != INF)dp[i][j][1] = max(dp[i][j][1], arr[i] + dp[i - 1][j - 2][1]);
            if(dp[i - 1][j - 1][0] != INF)dp[i][j][1] = max(dp[i][j][1], arr[i] + dp[i - 1][j - 1][0]);
            if(dp[i - 1][j][1] != INF)dp[i][j][1] = max(dp[i][j][1], arr[i] + dp[i - 1][j][1]);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++)printf("%10d ", dp[j][i][0]);
        printf("\n");
    }
    printf("\n");
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++)printf("%10d ", dp[j][i][1]);
        printf("\n");
    }
    printf("%d %d", dp[n][m][0], dp[n][m][1]);
}