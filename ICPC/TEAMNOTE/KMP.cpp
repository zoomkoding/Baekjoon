#include <cstdio>
#include <string.h>

char t[1000002], p[1000002];
int ans[1000002], pi[1000002], tn, pn, an;

void make_pi(){
    int j = 0;
    for(int i = 1; i < pn; i++){
        while(j > 0 && p[i] != p[j]) j = pi[j-1]; 
        if(p[i] == p[j]) pi[i] = ++j; 
    }
}

void do_KMP(){
    int j = 0;
    for(int i = 0; i < tn; i++){
        while(t[i] != p[j] && j > 0)j = pi[j - 1];
        if(t[i] == p[j])j++;
        if(j == pn - 1)ans[an++] = i - pn + 3;
    }
}

int main(){
    fgets(t, 1000002, stdin);
    fgets(p, 1000002, stdin);
    tn = strlen(t), pn = strlen(p);
    make_pi();
    do_KMP();
    printf("%d\n", an);
    for(int i = 0; i < an; i++)printf("%d ", ans[i]);
}