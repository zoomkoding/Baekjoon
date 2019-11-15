#include <iostream>
#include <cstring>
using namespace std;
char p[4001], t[4001];
int pn, tn, dp[4001][4001], ans;

int find(int x, int y, int cnt){
    if(x == pn || y == tn)return cnt;
    int &ret = dp[x][y];
    if(p[x] == t[y])return ret = max(max(find(x + 1, y + 1, cnt + 1), find(x + 1, y, 0)), find(x, y + 1, 0));
    else {
        ret = max(find(x + 1, y, 0), find(x, y + 1, 0));
        return cnt;
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> p >> t;
    pn = strlen(p), tn = strlen(t);
    find(0, 0, 0);
    for(int i = 0; i < pn; i++){
        for(int j = 0; j < tn; j++){
            printf("%d", dp[i][j]);
            if(dp[i][j] > ans)ans = dp[i][j];
        }
        printf("\n");
    }
    
    cout << ans;
    
}