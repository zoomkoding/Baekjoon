#include <cstdio>
#include <cstdlib>

int main(){
    char s1[10], s2[10], s1m[10], s1M[10], s2m[10], s2M[10];
    scanf("%s %s", s1, s2);
    
    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] == '5' || s1[i] == '6')s1M[i] = '6', s1m[i] = '5';
        else s1M[i] = s1m[i] = s1[i];
    }
    for(int i = 0; s2[i] != '\0'; i++){
        if(s2[i] == '5' || s2[i] == '6')s2M[i] = '6', s2m[i] = '5';
        else s2M[i] = s2m[i] = s2[i];
    }
    printf("%d %d", atoi(s1m) + atoi(s2m), atoi(s1M) + atoi(s2M));
}