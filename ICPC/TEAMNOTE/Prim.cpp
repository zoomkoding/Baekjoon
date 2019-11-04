#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int, int>
#define pip pair<int, pii>
int ans, cnt, n, m, a, b, c, par[100001];

int find(int i){
    if(par[i] == i)return i;
    return par[i] = find(par[i]);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)par[i] = i;
    priority_queue<pip> pq;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        pq.push(pip(-c, pii(a, b)));
    }
    while(!pq.empty() && cnt != n - 2){
        pip top = pq.top(); pq.pop();
        int tv = top.first, tx = top.second.first, ty = top.second.second;
        int px = find(tx), py = find(ty);
        if(px == py)continue;
        ans += -tv, cnt++;
        par[px] = py;
    }
    printf("%d", ans);
}