#include <cstdio>
#include <vector>
#define pii pair<int, int>
using namespace std;
int cnt, n, m, p, q, r, d[1001], pre[1001], in[1001], trace[1001];
vector<pii> v[1001];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &p, &q, &r);
        if(p == 1)d[q] = r, pre[q] = 1;
        else{
            v[p].push_back(pii(r, q));
            in[q]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(in[i])continue;
        for(int j = 0; j < v[i].size(); j++){
            int nv = v[i][j].first, nx = v[i][j].second;
            if(d[nx] < d[i] + nv){
                d[nx] = d[i] + nv;
                pre[nx] = i;
            }
            in[nx]--;
        }
        in[i] = 1, i = -1;
    }
    trace[cnt++] = 1;
    while(pre[1] != 1){
        trace[cnt++] = pre[1];
        pre[1] = pre[pre[1]];
    }
    

    printf("%d\n1 ", d[1]); 
    for(int i = cnt - 1; i >= 0; i--)printf("%d ", trace[i]);
}