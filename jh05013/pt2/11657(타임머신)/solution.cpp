#include <cstdio>
#include <vector>
#define INF 5000000
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector< vector<long long> > e(m, vector<long long>(3));
    vector<long long> dist(n+1, INF);
    for(int i = 0; i < m; i++){
        scanf("%lld %lld %lld", &e[i][0], &e[i][1], &e[i][2]);
    }
    dist[1] = 0;

    for(int k = 1; k < n; k++){
        for(int i = 0; i < m; i++){
            int u = e[i][0], v = e[i][1], w = e[i][2];
            if(dist[u] == INF)continue;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w; 
            }
        }
    }

    for(int i = 0; i < m; i++){
        if(dist[e[i][0]] == INF)continue;
        if(dist[e[i][1]] > dist[e[i][0]] + e[i][2]){
            printf("-1");
            return 0;
        }
    }
    for(int i = 2; i < n + 1; i++){
        if(dist[i] < INF)printf("%lld\n", dist[i]);
        else printf("-1\n");
    }
    
}