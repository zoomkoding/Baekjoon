#include <cstdio>
#include <cmath>
long long n, m, ans = 1;
int main(){
    scanf("%lld %lld", &n, &m);
    
    for(int i = 0; i < m; i++){
        ans *= n*n/2;
    }
    printf("%lld", ans);
}