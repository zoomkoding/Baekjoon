#include <iostream>
using namespace std;
char s[2501];
int i, dp[2501], x, y, pre;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> s;
    for(int i = 0; i < 2501; i++)dp[i] = 2500;
    for(i = 0; s[i] != '\0'; i++){
        x = y = i;
        while(x >= 0 && s[x] == s[y]){
            if(x - 1 >= 0)pre = dp[x - 1];
            else pre = 0;
            if(pre + 1 < dp[y])dp[y] = pre + 1;
            x--, y++;
        }

        x = i - 1, y = i;
        while(x >= 0 && s[x] == s[y]){
            if(x - 1 >= 0)pre = dp[x - 1];
            else pre = 0;
            if(pre + 1 < dp[y])dp[y] = pre + 1;
            x--, y++;
        }
    }
    printf("%d", dp[i - 1]);
}