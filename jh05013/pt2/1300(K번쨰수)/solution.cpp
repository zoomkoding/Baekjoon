#include <cstdio>

int main(){
    long long l = 1, r, n, k, mid, cnt, ans;
    scanf("%lld %lld", &n, &k);
    r = k;
    while(l <= r){
        printf("%lld %lld\n", l, r);
        mid = (l+r)/2, cnt = 0;
        for(int i = 1; i <= n; i++)cnt = mid / i < n ? cnt + mid / i : cnt + n;
        if(cnt >= k) ans = mid, r = mid - 1;
        else l = mid + 1;   
    }
    printf("%lld", ans);
}