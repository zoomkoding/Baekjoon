#include <cstdio>

char s[8][10];
int ans;

int main(){
    for(int i = 0; i < 8; i++){
        scanf("%s", s[i]);
        for(int j = i % 2; j < 8; j+=2)if(s[i][j] == 'F')ans++;
    }
    printf("%d", ans);
}