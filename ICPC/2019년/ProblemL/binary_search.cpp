#include <cstdio>
#include <algorithm>
using namespace std;

int l, r, mid, ans, n, w1[251], w2[251];

int dfs(int v1, int v2, int i, int cut){
    if(v1 > cut || v2 > cut)return 0;
    if(i == n)return 1;
    return dfs(v1 + w1[i], v2, i + 1, cut) + dfs(v1, v2 + w2[i], i + 1, cut);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &w1[i], &w2[i]);
        r += w1[i];
    }
    while(l <= r){
        int mid = (l + r) / 2;
        if(dfs(0, 0, 0, mid))ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d", ans);

}