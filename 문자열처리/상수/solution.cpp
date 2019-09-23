#include <cstdio>
char s[2][5];
int main(){
    int ans = 0;
    scanf("%s %s", s[0], s[1]);
    for(int i = 2; i >= 0; i--){
        if(s[0][i] > s[1][i]){
            ans = 0;
            break;
        }
        if(s[0][i] < s[1][i]){
            ans = 1;
            break;
        }
    }
    for(int i = 2; i >= 0; i--)printf("%c", s[ans][i]);
}