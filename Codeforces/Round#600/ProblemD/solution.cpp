#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, par[200001], cmp, ans;
int find(int x) {
    if (x == par[x])return x;
    return par[x] = find(par[x]);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)par[i] = i;
    for(int i = 0; i < m; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        int p1 = find(v1), p2 = find(v2);
        if(p1 == p2)continue;
        if(p1 < p2)swap(p1, p2);
        par[p2] = p1;
    }
    cmp = find(1);
    for(int i = 2; i <= n; i++){
        int px = find(i);
        if(i > cmp)cmp = px;
        
        else{
            if(px == cmp){
                continue;
            }
            else if(px < cmp){
                ans++;
                par[px] = cmp;
            }
            else {
                ans++;
                par[cmp] = px;
                cmp = px;
            }
        }
    }
    printf("%d", ans);
    
}