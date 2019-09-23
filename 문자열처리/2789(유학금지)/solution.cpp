#include <cstdio>
char s[102];
int main(){
    scanf("%s", s);
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'C'
            || s[i] == 'A'
            || s[i] == 'M'
            || s[i] == 'B'
            || s[i] == 'R'
            || s[i] == 'I'
            || s[i] == 'D'
            || s[i] == 'G'
            || s[i] == 'E') continue;
        printf("%c", s[i]);
    }
}