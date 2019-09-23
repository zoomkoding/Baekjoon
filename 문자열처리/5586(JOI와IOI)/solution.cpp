#include <cstdio>
#include <string.h>

char s[10002];
int n, J, I;
int main(){
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0; i < n - 2; i++){
        if(s[i+1] == 'O' && s[i+2] == 'I'){
            if(s[i] == 'J')J++;
            else if(s[i] == 'I')I++;
        }
    }
    printf("%d\n%d", J, I);
}