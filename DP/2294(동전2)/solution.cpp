#include <cstdio>
int n, k, t, coin[101], cnt[10001];
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &coin[i]);
    }
    
    for(int i = 1; i <= k; i++){
        int MIN = 10000;
        for(int j = 0; j < n; j++){
            if(i - coin[j] < 0) continue;
            if(cnt[i - coin[j]] == 0 && i - coin[j] != 0)continue;
            if(MIN > cnt[i - coin[j]] + 1)MIN = cnt[i - coin[j]] + 1;
            cnt[i] = MIN;
        }
    }
    if(cnt[k] == 0)printf("-1");
    else printf("%d", cnt[k]);
}