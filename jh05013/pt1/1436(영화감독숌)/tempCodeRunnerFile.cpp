#include <cstdio>
long long n, m, mid, cnt, ans, arr[10001];
void binarySearch(int l, int r){
    if(l <= r){
        mid = (l + r) / 2;
        cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += arr[i] / mid;
        }
        if(cnt >= m){
            ans = mid;
            binarySearch(mid + 1, r);
        }
        else binarySearch(l, mid - 1);
    }
}

int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++)scanf("%lld", &arr[i]);
    binarySearch(0, 2147483647);
    printf("%lld", ans);
}