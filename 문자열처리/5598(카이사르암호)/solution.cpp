#include <cstdio>
char s[1002];
int main(){
    scanf("%s", s);
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] - 3 < 'A')printf("%c", s[i] + 23);
        else printf("%c", s[i] - 3);
    }
}