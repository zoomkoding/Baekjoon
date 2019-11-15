#include <iostream>
#include <cstring>
using namespace std;
char p[4001], t[4001];
int pn, tn, dp[4001][4001], ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> p >> t;
    pn = strlen(p), tn = strlen(t);
    for(int i = 0; i < pn; i++){
        for(int j = 0; j < tn; j++){
            if(p[i] != t[j])continue;
            if(i == 0 || j == 0)dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + 1;
            if(dp[i][j] > ans) ans = dp[i][j];
            
        }
    }
    cout << ans;
}