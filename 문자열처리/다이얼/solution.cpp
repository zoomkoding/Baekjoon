#include <cstdio>
#include <string.h>

char s[20];
int n, ans;

int main(){
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0; i < n; i++){
        if(s[i] < 'D')ans += 3;
        else if(s[i] < 'G') ans += 4;
        else if(s[i] < 'J') ans += 5;
        else if(s[i] < 'M') ans += 6;
        else if(s[i] < 'P') ans += 7;
        else if(s[i] < 'T') ans += 8;
        else if(s[i] < 'W') ans += 9;
        else ans += 10;
    }
    printf("%d", ans);
}