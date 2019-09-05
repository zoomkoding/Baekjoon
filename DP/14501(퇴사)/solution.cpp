#include <cstdio>

int n, t[16], p[16], v[16];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d %d", &t[i], &p[i]);
    for(int i = 1; i < n + 1; i++){
        v[i] = v[i-1];
        for(int j = 1; j < 6; j++){
            if(i - j < 0 || j != t[i - j])continue;
            if(v[i] < v[i - j] + p[i - j])v[i] = v[i - j] + p[i - j];
        }
    }
    printf("%d", v[n]);
}