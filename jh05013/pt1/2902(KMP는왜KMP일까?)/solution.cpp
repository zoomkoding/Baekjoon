#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')cout << s[i];
    }
}