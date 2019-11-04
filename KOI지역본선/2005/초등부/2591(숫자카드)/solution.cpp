#include <iostream>
#include <cstring>
using namespace std;
char s[41];
int n, dp[41];
int main(){
    cin >> s;
    n = strlen(s), dp[0] = 1;
    if(s[0] == '0'){
        cout << 0;
        return 0;
    }
    if(n == 1 ){
        cout << 1;
        return 0;
    }
    if(s[1] == '0' && s[0] >= '4'){
        cout << 0;
        return 0;
    }
    if(s[1] == '0' || s[0] > '3' || (s[0] == '3' && s[1] > '4'))dp[1] = 1;
    else dp[1] = 2;
    for(int i = 2; i < n; i++){
        if(s[i + 1] == '0')dp[i + 1] = dp[i - 1], i++;
        else if(s[i - 1] == '0' || s[i - 1] > '3' || (s[i - 1] == '3' && s[i] > '4'))dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + dp[i - 2];
        if(s[i] == '0' && (s[i - 1] >= '4' || s[i - 1] == '0')){
            cout << 0;
            return 0;
        }
    } 
    cout << dp[n - 1];
}