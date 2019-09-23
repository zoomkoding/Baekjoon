#include <cstdio>
#include <string.h>
int n, v, ans, c;
int main(){
    scanf("%d", &n);
    while(n--){
        char s[102];
        scanf("%s", s);
        v = 1;
        for(int i = 0; s[i] != '\0'; i++){
            c = 1;
            for(int j = i; s[j] != '\0'; j++){
                if(s[i] != s[j])c = 0;
                if(s[i] == s[j] && !c){
                    v = 0; 
                    break;
                }
            }
            if(!v)break;
        }
        ans += v;
    }
    printf("%d", ans);
}