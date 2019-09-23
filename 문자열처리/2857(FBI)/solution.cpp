#include <cstdio>
#include <string.h>

int main(){
    int n, ans = 0;
    char s[12];
    for(int i = 0; i < 5; i++){
        scanf("%s", s);
        n = strlen(s);
        for(int j = 0; j < n - 2; j++){
            if(s[j] == 'F' && s[j+1] == 'B' && s[j+2] == 'I'){
                ans ++;
                printf("%d ", i+1);
                break;
            }
        }
    }
    if(!ans)printf("HE GOT AWAY!");
}