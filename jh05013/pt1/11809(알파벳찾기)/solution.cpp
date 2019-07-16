#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string s;
int c[26];

int main(){
    cin >> s;
    for(int i  = 0 ;i < 26; i++)c[i] = -1;
    for(int i = 0; i < s.length(); i++)if(c[s[i]-'a']==-1)c[s[i]-'a'] = i;
    for(int i = 0; i < 26; i++)printf("%d ", c[i]);    

}