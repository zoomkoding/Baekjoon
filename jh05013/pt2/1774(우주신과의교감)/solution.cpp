#include <cstdio>
#include <queue>
#include <cmath>
#define pii pair<int, int>
#define pdp pair<double, pii>
using namespace std;

int n, m, v1, v2, par[1002], X[1002], Y[1002];

double sqr(double d){return d*d;}

int find(int x){
    if(par[x] == x)return x;
    return par[x] = find(par[x]);
}

int Union(int x, int y){
    int px = find(x), py = find(y);
    if(px == py)return 0;
    par[px] = py;
    return 1;
}

int main(){
    double ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &X[i], &Y[i]);
        par[i] = i;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &v1, &v2);
        Union(v1, v2);
    }
    priority_queue<pdp> pq;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            double d = sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]);
            pq.push(pdp(-d, pii(i, j)));
        }
    }
    int cnt = m;
    while(!pq.empty() && cnt != n - 1){
        pdp top = pq.top(); pq.pop();
        double tv = top.first;
        int tx = top.second.first, ty = top.second.second;
        if(Union(tx, ty))ans += sqrt(-tv), cnt++;
    }
    printf("%.2f", ans);
}