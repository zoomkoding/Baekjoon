#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){return (x1*y2+x2*y3+x3*y1) - (x1*y3+x3*y2+x2*y1);}
ll ans;
ll n, xo, yo, x[10001], y[10001];
int main(){
    scanf("%lld", &n);
    scanf("%lld %lld %lld %lld", &xo, &yo, &x[0], &y[0]);
    for(int i = 1; i < n - 1; i++){
        scanf("%lld %lld", &x[i], &y[i]);
        ans += area(xo, yo, x[i], y[i], x[i-1], y[i-1]);
    }
    ans = abs(ans);
    printf("%lld", ans/2);
    if(ans % 2 == 0) printf(".0\n");
    else printf(".5\n");
}