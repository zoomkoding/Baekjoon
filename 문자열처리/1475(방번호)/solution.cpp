#include <cstdio>
#include <string.h>

char s[10];
int arr[10], ans;

int main(){
    scanf("%s", s);
    for(int i = 0; s[i] != '\0'; i++)arr[s[i]-'0'] ++;
    ans = (arr[6] + arr[9]) % 2 ? (arr[6] + arr[9]) / 2 + 1: (arr[6] + arr[9]) / 2;
    for(int i = 0; i < 9; i++){
        if(i == 6)continue;
        if(ans < arr[i])ans = arr[i];
    }
    printf("%d", ans);
}