#include <cstdio>

int main(){
    char s[102];
    int cnt = 0;
    scanf("%s", s);
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')cnt++;
    }
    printf("%d", cnt);
}