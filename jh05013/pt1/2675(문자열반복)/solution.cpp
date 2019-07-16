#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n;

    while(n--){
        cin >> m >> s;
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < m; j++)printf("%c", s[i]);
        }
        printf("\n");
    }
}