#include <cstdio>
int n, cur, d = -1, arr[16];
int main(){
    long long ans = 0, c = 0, coin = 0;
    scanf("%d %lld", &n, &c);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++){
        cur = arr[i] - arr[i-1];
        if(cur != 0)cur = cur > 0 ? 1 : -1;
        if(d == cur || cur == 0)continue;
        if(d > 0)c += coin * arr[i-1], coin = 0;
        else coin = c / arr[i-1], c -= coin * arr[i-1];
        if(c > ans)ans = c;
        d = cur;
    }
    if(c + coin * arr[n - 1] > ans)ans = c + coin * arr[n - 1];
    printf("%lld", ans);
}