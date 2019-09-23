#include <cstdio>
#include <string.h>


int main(){
    char s[102];
    scanf("%s", s);
    int n = strlen(s), mid = n / 2, ans = 1;
    for(int i = 0; i < mid; i++){
        if(s[i] != s[n-i-1]){
            ans = 0; break;
        }
    }
    printf("%d", ans);
}