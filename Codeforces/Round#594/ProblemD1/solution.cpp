#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, ans, a, b;
int v1, v2;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> s;
    
    for(int i = 0; i <n; i++){
        if(s[i] == '(')v1++;
        else v2++;
    }
    if(v1 != v2){
        cout << 0 << '\n' << 1<< ' ' << 1;
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int cnt = 0;
            swap(s[i], s[j]);
            for(int x = 0; x < n; x++){
                int start = 0, valid = 1;
                for(int y = 0; y < n; y++){
                    int cur = (x + y) % n;
                    if(s[cur] == '(')start++;
                    else{
                        if(!start){
                            valid = 0;
                            break;
                        }
                        start--;
                    } 
                }
                if(!start && valid)cnt++;
            }
            if(cnt > ans){
                ans = cnt, a = i, b = j;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << '\n' << a + 1<< ' ' << b + 1;
}