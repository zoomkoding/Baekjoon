#include <iostream>
#include <algorithm>
using namespace std;

int m, n, arr[251][2], dp[251][62501];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
        m += arr[i][0];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++)dp[i][j] = 987654321;
    }
    dp[0][arr[0][0]] = 0;
    dp[0][0] = arr[0][1];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= m; j++){
            if(dp[i - 1][j] == -1)continue;
            dp[i][j + arr[i][0]] = min(dp[i][j + arr[i][0]], dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + arr[i][1]); 
        }
    }
    int ans = 987654321;
    for(int i = 0; i <= m; i++)ans = min(ans, max(i, dp[n - 1][i]));
    cout << ans;
}