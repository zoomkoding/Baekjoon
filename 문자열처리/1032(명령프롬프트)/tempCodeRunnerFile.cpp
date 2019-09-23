#include <cstdio>
char s[51][52];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%s", s[i]);
    for(int i = 0; s[0][i] != '\0'; i++){
        int good = 1;
        for(int j = 1; j < n; j++){
            if(s[0][i] != s[j][i]){
                good = 0; break;
            }
        }
        printf("%c", good ? s[0][i] : '?');
    }
}