#include <cstdio>
int n, k, dif, ans, vip[41], arr[41];
int main(){
    ans = 1, arr[0] = 1, arr[1] = 1;
    scanf("%d %d", &n, &k);    
    for(int i = 2; i <= n; i++) arr[i] = arr[i - 1] + arr[i - 2];
    for(int i = 1; i <= k; i++){
        scanf("%d", &vip[i]);
        dif = vip[i] - vip[i - 1] - 1;
        ans *= arr[dif];
    }
    dif = n - vip[k];
    ans *= arr[dif];
    printf("%d", ans);
}