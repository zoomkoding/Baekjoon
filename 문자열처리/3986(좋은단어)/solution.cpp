#include <cstdio>

char stack[100002];
int n, top, ans;

int main(){
    scanf("%d", &n);
    while(n--){
        top = 0;
        char s[100002];
        scanf("%s", s);
        stack[top++] = s[0];
        for(int i = 1; s[i] != '\0'; i++){
            if(stack[top-1] == s[i])top --;
            else stack[top++] = s[i];
        }
        printf("%d\n", top);
    }
}