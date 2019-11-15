#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;
vector<pii> arr;
int n, x, y, dp[101], ans;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        arr.push_back(pii(x, y));
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        int best = 0;
        for(int j = 0; j < i; j++){
            if(arr[j].second > arr[i].second)continue;
            if(dp[j] > best)best = dp[j];
        }
        dp[i] = best + 1;
        if(ans < dp[i]) ans = dp[i];
    }
    printf("%d", n - ans);
}