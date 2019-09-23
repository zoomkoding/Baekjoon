#include <cstdio>
int n, ans, arr[1001], cnt[1001];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        int MAX = 0;
        for(int j = 0; j < i; j++){
            if(arr[i] >= arr[j]) continue;
            if(MAX < cnt[j])MAX = cnt[j];
        }
        cnt[i] = MAX + 1;
        if(ans < cnt[i]) ans = cnt[i];
    }
    printf("%d", ans);
}