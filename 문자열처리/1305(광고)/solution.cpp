#include <iostream>
using namespace std;
int n, pi[1000001];
char s[1000001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>s;
    int j = 0;
    for(int i = 1; i < n; i++){
        while(s[i] != s[j] && j > 0)j = pi[j-1];
        if(s[i] == s[j])pi[i] = ++j;
    }
    cout << n - pi[n-1];
}