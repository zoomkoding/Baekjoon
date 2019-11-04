#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
long long n, ans, a = 1, b = 1;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            long long cnt = 0, start = 0, valid = 1;
            swap(s[i], s[j]);
            for(int x = 0; x < n; x++){
                if(s[x] == '(')start++;
                else{
                    if(!start){
                        valid = 0;
                        break;
                    }
                    start--;
                    if(!start)cnt++;
                } 
            }
            if(!start && valid && cnt > ans){
                ans = cnt, a = i + 1, b = j + 1;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << '\n' << a << ' ' << b;
}