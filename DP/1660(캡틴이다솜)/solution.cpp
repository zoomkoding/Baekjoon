#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000], dp[300001];
int n, x;
int main(){
    scanf("%d", &x);

    for(int i = 1; i <= x; i++)dp[i] = 300001;
    dp[0] = 0, arr[1] = 1;
    for(int i = 2; arr[i - 1] <= 300000; i++)arr[i] = arr[i - 1] + i, n = i;
    for(int i = 1; i < n; i++)arr[i] += arr[i - 1];
    for(int i = 1; i < n; i++){
        for(int j = arr[i]; j <= x; j++){
            if(dp[j - arr[i]] + 1 < dp[j])dp[j] = dp[j - arr[i]] + 1;
        }
    }
    printf("%d", dp[x]);
}