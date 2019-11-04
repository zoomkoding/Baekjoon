#include <iostream>
#include <vector>
#define pif pair<int, float>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        int n, ans = 0;
        float m;
        cin >> n >> m;
        m *= 100;
        vector<pif> v(n);
        int dp[10001] = {0,};
        if(n == 0 && m == 0)break;
        for(int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
        for(int i = 0; i < n; i++){
            int x = float(v[i].second * 100), y = v[i].first;
            if(dp[x] < y)dp[x] = y;
            for(int j = x + 1; j <= m; j++){
                if(dp[j - x] == 0)continue;
                if(dp[j - x] + y > dp[j])dp[j] = dp[j - x] + y;
            }
        }
        for(int i = 1; i <= m; i++){
            if(ans < dp[i])ans = dp[i];
        }
        cout << ans << '\n';
    }
}