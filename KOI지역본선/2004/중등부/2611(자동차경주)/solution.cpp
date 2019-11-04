#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;
int n, m, p, q, r, d[1001], pre[1001], visited[1001], in[1001];
vector<pii> dst, v[1001];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &p, &q, &r);
        if(q == 1)dst.push_back(pii(r, p));
        v[p].push_back(pii(r, q));
    }
    d[1] = 0;
    priority_queue<pii> pq;
    pq.push(pii(0, 1));
    while(!pq.empty()){
        pii top = pq.top(); pq.pop();
        int tv = top.first, tx = top.second;
        // if(visited[tx])continue;
        visited[tx] = 1;

        for(int i = 0; i < v[tx].size(); i++){
            int nv = v[tx][i].first, nx = v[tx][i].second;
            if(visited[nx])continue;
            if(d[nx] < tv + nv){
                d[nx] = tv + nv;
                pre[nx] = tx;
                pq.push(pii(d[nx], nx));
            }
        }
    }
    int M = 0, Mi = - 1;
    for(int i = 0; i < dst.size(); i++){
        if(M < d[dst[i].second] + dst[i].first)Mi = dst[i].second, M = d[dst[i].second] + dst[i].first;
    }
    vector<int> trace;
    printf("%d\n", M);
    while(Mi){
        trace.push_back(Mi);
        Mi = pre[Mi];
    }
    for(int i = trace.size() - 1; i >= 0; i--)printf("%d ", trace[i]);
}