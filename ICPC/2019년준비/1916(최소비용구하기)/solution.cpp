#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

ll ans, cnt, n, m, v1, v2, w, src, dst, visited[1001];
vector<vector<pll> > e;
int main(){
    scanf("%lld %lld", &n, &m);
    e = vector<vector<pll> >(n+1);
    for(int i = 0; i < m; i++){
        scanf("%lld %lld %lld", &v1, &v2, &w);
        e[v1].push_back(pll(-w, v2));
    }
    scanf("%lld %lld", &src, &dst);
    priority_queue<pll> pq;
    pq.push(pll(0, src));
    while(!pq.empty()){
        pll top = pq.top(); pq.pop();
        int tv = top.first, tx = top.second;
        visited[tx] = 1, cnt++;
        if(tx == dst){
            ans = tv;
            break;
        }
        for(int i = 0; i < e[tx].size(); i++){
            pll next = e[tx][i];
            int nv = next.first, nx = next.second;
            if(visited[nx])continue;
            pq.push(pll(tv + nv, nx));
        }
    }
    printf("%lld", -ans);

}