#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int n1, n2, cnt[1001];
string s1, s2;
vector<int> print;

int main(){
    int ans = 0, ans_i = -1; 
    cin >> s1 >> s2;
    n1 = s1.length(), n2 = s2.length();
    vector<int> p(n2, -1);
    for(int i = 0; i < n1; i++){
        char c = s1[i];
        for(int j = n2 - 1; j >= 0; j--){
            if(c == s2[j]){
                int MAX = 0, MAX_i = -1;
                for(int k = 0; k < j; k++){
                    if(cnt[k] > MAX)MAX = cnt[k], MAX_i = k;
                }
                if(MAX + 1 > cnt[j]) cnt[j] = MAX + 1, p[j] = MAX_i;
                if(cnt[j] > ans) ans = cnt[j], ans_i = j;
            }
        }
    }
    for(int i = 0; i < n1; i++){
        printf("%d", cnt[i]);
    }
    cout << ans << '\n';
    while(ans_i != -1){
        print.push_back(ans_i);
        ans_i = p[ans_i];
    }
    for(int i = print.size() - 1; i >= 0; i--)cout << s2[print[i]];
}