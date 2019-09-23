#include <cstdio>
int main(){
    int n,m,d,c5 = 0, c2 = 0;
    scanf("%d %d", &n, &m);
    d = n - m;
    for(int i = 5; i <= n; i*=5)c5 += n / i - m / i - d / i ;
    for(int i = 2; i <= n; i*=2)c2 += n / i - m / i - d / i ;
    printf("%d", c5 < c2 ? c5: c2);
}