#include <cstdio>
long long n, zero[91], one[91];

int main(){
    scanf("%lld", &n);
    one[1] = 1;
    for(int i = 2; i <= n; i++){
        one[i] = zero[i-1];
        zero[i] = one[i-1] + zero[i-1];
    }
    printf("%lld", one[n]+zero[n]);
}