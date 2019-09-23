#include <cstdio>
#include <string.h>
int main(){
    char s[1000003], bomb[40], temp[40], stack[1000002];
    scanf("%s %s", s, bomb);
    int top = 0, sn = strlen(s), bn = strlen(bomb);
    for(int i = 0; i < sn; i++){
        stack[top++] = s[i];
        int cnt = 0;
        for(int j = bn - 1; j >= 0; j--){
            if(bomb[j] != stack[top-1]) break;
            temp[cnt++] = stack[--top];
        }
        if(cnt == bn)continue;
        for(int j = cnt - 1; j >= 0; j--)stack[top] = temp[j], top ++;
    }
    if(!top)printf("FRULA");
    else for(int i = 0; i < top; i++)printf("%c", stack[i]);
}