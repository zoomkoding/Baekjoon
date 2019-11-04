#include <iostream>
#include <algorithm>
using namespace std;
int t, n, arr[100001][3], dp[100001][3];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        cin >> n;
        if(!n)break;
        for(int i = 1; i <= n; i++)cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        t++, dp[1][0] = 1000000, dp[1][1] = arr[1][1], dp[1][2] = arr[1][1] + arr[1][2];     
        for(int i = 2; i <= n; i++){
            dp[i][0] = arr[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = arr[i][1] + min(dp[i][0], min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])));
            dp[i][2] = arr[i][2] + min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]));
        }
        printf("%d. %d\n", t, dp[n][1]);
    }
}