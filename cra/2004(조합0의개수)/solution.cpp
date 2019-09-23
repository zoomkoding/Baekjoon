#include <cstdio>
int main(){
    long long n,m,d,c5 = 0, c2 = 0;
    scanf("%lld %lld", &n, &m);
    d = n - m;
    for(long long i = 5; i <= n; i*=5)c5 += n / i - m / i - d / i ;
    for(long long i = 2; i <= n; i*=2)c2 += n / i - m / i - d / i ;
    printf("%lld", c5 < c2 ? c5: c2);
}

