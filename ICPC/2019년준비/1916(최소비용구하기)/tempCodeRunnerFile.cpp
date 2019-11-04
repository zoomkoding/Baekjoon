#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int, int>

int ans, cnt, n, m, v1, v2, w, src, dst, visited[1001];
vector<vector<pii> > e;
int main(){
    scanf("%d %d", &n, &m);
    e = vector<vector<pii> >(n+1);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        e[v1].push_back(pii(-w, v2));
    }
    scanf("%d %d", &src, &dst);
    priority_queue<pii> pq;
    pq.push(pii(0, src));
    while(!pq.empty() && cnt != n){
        pii top = pq.top(); pq.pop();
        int tv = top.first, tx = top.second;
        visited[tx] = 1, cnt++;
        if(tx == dst){
            ans = tv;
            break;
        }
        for(int i = 0; i < e[tx].size(); i++){
            pii next = e[tx][i];
            int nv = next.first, nx = next.second;
            if(visited[nx])continue;
            pq.push(pii(tv + nv, nx));
        }
    }
    printf("%d", -ans);

}