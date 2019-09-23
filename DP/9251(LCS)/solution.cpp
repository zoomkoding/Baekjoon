#include <iostream>
#include <string>
using namespace std;

int n1, n2, ans, cnt[1001];
string s1, s2;

int main(){
    cin >> s1 >> s2;
    n1 = s1.length(), n2 = s2.length();
    for(int i = 0; i < n1; i++){
        char c = s1[i];
        for(int j = n2 - 1; j >= 0; j--){
            if(c == s2[j]){
                int MAX = 0;
                for(int k = 0; k < j; k++){
                    if(cnt[k] > MAX)MAX = cnt[k];
                }
                if(MAX + 1 > cnt[j]) cnt[j] = MAX + 1;
                if(cnt[j] > ans) ans = cnt[j];
            }
        }
    }
    cout << ans;
}