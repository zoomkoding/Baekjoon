#include <cstdio>
#include <algorithm>
using namespace std;
int n, arr[51], dp[51][500001], ans = -1;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for(int i = 0; i < 51; i++){
        for(int j = 0; j < 500001; j++)dp[i][j] = -1;
    }
    dp[0][0] = arr[0], dp[0][arr[0]] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 500001; j++){
            if(dp[i - 1][j] == -1)continue;
            dp[i][j + arr[i]] = dp[i - 1][j];
            dp[i][j] = dp[i - 1][j] + arr[i];
        }
        for(int j = 0; j < 500001; j++){
            if(dp[i][j] == j && j > ans) ans = j;
        }
    }
    
    printf("%d", ans);
}