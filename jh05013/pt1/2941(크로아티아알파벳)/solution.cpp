#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int c = 0;
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        c++;
        if(s[i] == 'c'){
            if(s[i+1] == '=' || s[i+1] == '-') i++;
        }
        else if(s[i] == 'd'){
            if(s[i+1] == 'z' && s[i+2] == '=') i+=2;
            else if(s[i+1] == '-')i++;
        }
        else if(s[i] == 'l' && s[i+1] == 'j')i++;
        else if(s[i] == 'n' && s[i+1] == 'j')i++;
        else if(s[i] == 's' && s[i+1] == '=')i++;
        else if(s[i] == 'z' && s[i+1] == '=')i++;
    }
    cout << c;
}