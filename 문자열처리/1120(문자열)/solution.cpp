#include <cstdio>
#include <string.h>

int main(){
    char s1[52], s2[52];
    scanf("%s %s", s1, s2);
    int diff = strlen(s2) - strlen(s1), ans = 50;
    for(int i = 0; i <= diff; i++){
        int cnt = 0;
        for(int j = 0; s1[j] != '\0'; j++){
            if(s1[j] != s2[j + i])cnt ++;
        }
        if(ans > cnt)ans = cnt;
    }
    printf("%d", ans);
}