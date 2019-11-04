#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int src, c, m, n, arr[17][17], dp[1 << 17];
char temp;
int find(int i, int cnt){
    if(cnt >= m)return 0;
    int &ret = dp[i];
    if(ret != INF)return ret;
    for(int j = 0; j < n; j++){
        int s1 = i | (1 << j);
        if(s1 != i)continue;
        for(int k = 0; k < n; k++){
            int s2 = i | (1 << k);
            if(s2 == i)continue;
            ret = min(ret, arr[j][k] + find(s2, cnt + 1));
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cin >> arr[i][j];
    }
    for(int i = 0; i <= (1 << n); i++) dp[i] = INF;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == 'Y') c ++, src += (1 << i);
    }
    cin >> m;
    int ans = find(src, c);
    if(ans == INF)cout << "-1";
    else cout << ans;
}