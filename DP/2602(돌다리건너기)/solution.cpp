#include <iostream>
#include <cstring>
using namespace std;
char s[2][101], p[21];
int pn, sn, dp[101][2][21];
int main(){
    cin >> p >> s[0] >> s[1];
    pn = strlen(p), sn = strlen(s[0]);
    if(p[0] == s[0][0])dp[0][0][0] = 1;
    if(p[0] == s[1][0])dp[0][1][0] = 1;
    for(int i = 1; i < sn; i++){
        for(int j = 0; j < 2; j++){
            dp[i][j][0] = dp[i - 1][j][0];
            if(s[j][i] == p[0])dp[i][j][0]++;
            for(int k = 1; k < pn; k++){
                dp[i][j][k] = dp[i - 1][j][k];
                if(s[j][i] == p[k])dp[i][j][k] += dp[i - 1][!j][k - 1];
            }
        }
    }
    printf("%d", dp[sn - 1][0][pn - 1] + dp[sn - 1][1][pn - 1]);
}
