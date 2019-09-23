#include <iostream>
#include <string>
using namespace std;

int n1, n2, ans, ans_i, cnt[1001], pre[1001], asd[1001];
string s1, s2;

int main(){
    cin >> s1 >> s2;
    n1 = s1.length(), n2 = s2.length();
    for(int i = 0; i < n1; i++){
        char c = s1[i];
        for(int j = n2 - 1; j >= 0; j--){
            if(c == s2[j]){
                int MAX = 0, MAX_i = 0;
                for(int k = 0; k < j; k++){
                    if(cnt[k] > MAX)MAX = cnt[k], MAX_i = k;
                }
                if(MAX + 1 > cnt[j]) cnt[j] = MAX + 1, pre[j] = MAX_i;
                if(cnt[j] > ans) ans = cnt[j], ans_i = j;
            }
        }
    }
    for(int i = ans - 1; i >= 0; i--) asd[i] = ans_i, ans_i = pre[ans_i];
    cout << ans << '\n';
    for(int i = 0; i < ans; i++)cout << s2[asd[i]];
}