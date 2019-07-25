#include <cstdio>
long long n, m, l = 1, r, mid, cnt, ans, arr[10001];

int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        if(arr[i] > r) r = arr[i];
    }
    while(l <= r){
        mid = (l + r) / 2;
        cnt = 0;
        for(int i = 0; i < n; i++)cnt += arr[i] / mid;
        if(cnt >= m){
            ans = ans < mid ? mid : ans;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%lld", ans);
}