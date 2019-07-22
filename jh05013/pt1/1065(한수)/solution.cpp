#include <iostream>
#include <string>

using namespace std;

int main(){
    int n = 0, c = 0;
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        if(s.length() <= 2) {
            c++;
            continue;
        }
        int k = s[1] - s[0];
        for(int j = 2; j < s.length(); j++){
            if(s[j] - s[j-1] != k) {
                k = 100; 
                break;
            }
        }
        if(k != 100)c++;
    }
    cout << c;
}