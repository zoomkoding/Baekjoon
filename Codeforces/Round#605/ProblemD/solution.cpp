#include <cstdio>
#include <algorithm>
using namespace std;
int n, arr[500001], dp[500001][2], ans;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    dp[0][0] = 1, dp[0][1] = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i - 1]){
            dp[i][0] = dp[i - 1][0] + 1; 
            if(i != 1 && arr[i] > arr[i - 2])dp[i][1] = dp[i - 1][1] + 1;
            else dp[i][1] = dp[i - 1][1] + 1;
        }
        else {
            dp[i][0] = 1;
            if(i != 1 && arr[i] > arr[i - 2])dp[i][1] = dp[i - 2][0] + 1;
            else dp[i][1] = 1;
        }
    }
    for(int i = 0; i < n; i++)ans = max(ans, max(dp[i][0], dp[i][1]));
    printf("%d", ans);
}