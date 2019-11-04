#include <iostream>
#include <cstring>
using namespace std;
char s[1001];
int sn, x, y, m = 10000;
int main(){
    cin >> s;
    sn = strlen(s);
    for(int i = 0; i < sn; i++){
        x = y = i;
        while(x >= 0 && y < sn && s[x] == s[y])x--, y++;
        if(y == sn && x < m)m = x;
        x = i, y = i + 1;
        while(x >= 0 && y < sn && s[x] == s[y])x--, y++;
        if(y == sn && x < m)m = x;
    }
    cout << sn + m + 1;
}