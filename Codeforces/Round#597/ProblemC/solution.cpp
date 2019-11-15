#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
char s[100001];
long long dp[100001], n, valid = 1;
int main(){
    scanf("%s", s);
    if(s[0] == 'm' || s[0] == 'w')valid = 0;
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; s[i - 1] != '\0'; i++){
        if(s[i - 1] == 'u' && s[i - 2] == 'u')dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        else if(s[i - 1] == 'n' && s[i - 2] == 'n')dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        else dp[i] = dp[i - 1];
        n = i;
        if(s[i - 1] == 'm' || s[i - 1] == 'w'){
            valid = 0;
            break;
        }
    }
    if(valid)printf("%lld", dp[n]);
    else printf("0");
}