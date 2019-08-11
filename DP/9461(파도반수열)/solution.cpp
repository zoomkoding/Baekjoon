#include <cstdio>

int main(){
    long long t, x, n[101];
    n[1] = n[2] = n[3] = 1, n[4] = n[5] = 2;
    for(int i = 6; i <= 100; i++) n[i] = n[i-1] + n[i-5];
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &x);
        printf("%lld\n", n[x]);
    }
}