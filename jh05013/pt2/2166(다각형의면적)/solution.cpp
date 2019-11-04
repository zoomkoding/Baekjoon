#include <cstdio>
#include <cmath>
#define ll long long
int main(){
    ll ans = 0, n, xo, yo, x1, y1, x2, y2;
    scanf("%lld", &n);
    scanf("%lld %lld %lld %lld", &xo, &yo, &x2, &y2);
    for(int i = 1; i < n - 1; i++){
        x1 = x2, y1 = y2;
        scanf("%lld %lld", &x2, &y2);
        ans += (xo*y1+x1*y2+x2*yo) - (xo*y2+x2*y1+x1*yo);
    }
    printf("%.1lf", fabs(ans)/2);
}