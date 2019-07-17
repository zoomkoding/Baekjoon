#include <cstdio>
#include <vector>
#include <queue>
#define INF 10000000

using namespace std;

int V, E, K, u, v, w, n;
vector< vector< pair<int, int> > > ll;
vector<int> d;

struct cmp{
    bool operator()(int a, int b){return d[a] > d[b];}
};

int main(){
    scanf("%d %d %d", &V, &E, &K);
    ll = vector< vector< pair<int, int> > >(V+1);
    d = vector<int>(V+1);
    priority_queue<int, vector<int>, cmp> pq;

    for(int i = 1; i < V+1; i++) {
        d[i] = INF;
        if(i == K)d[i] = 0;
        pq.push(i);
    }
    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &u, &v, &w);
        ll[u].push_back(make_pair(v, w));
    }
    
    while(n < V - 1){
        u = pq.top(); pq.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].first, w = ll[u][i].second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(v);
            }
        }
        n++;
    }
    for(int i = 1; i < d.size() ; i++){
        if(d[i] == INF) printf("INF\n");
        else printf("%d\n", d[i]);
    }
}