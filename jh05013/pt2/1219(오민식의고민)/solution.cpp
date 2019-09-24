#include <cstdio>
#include <vector>
#define INF 987654321

typedef struct edge{
    long long u, v, w;
}edge;

using namespace std;

long long n, src, dest, m, u, v, c;
long long inc[111];
long long tot[111];
edge e[111];

int main(){
    scanf("%lld %lld %lld %lld", &n, &src, &dest, &m);
    for(int i = 0; i < n; i++)tot[i] = -INF;
    for(int i = 0; i < m; i++){
        scanf("%lld %lld %lld", &e[i].u, &e[i].v, &e[i].w);
    }
    for(int i = 0; i < n; i++)scanf("%lld", &inc[i]);
    tot[src] = inc[src];

    for(int k = 1; k < n; k++){
        for(int i = 0; i < m; i++){
            if(tot[e[i].u] == -INF) continue;
            if(tot[e[i].v] < tot[e[i].u] - e[i].w + inc[e[i].v]){
                tot[e[i].v] = tot[e[i].u] - e[i].w + inc[e[i].v];
            }
        }
    }
    if(tot[dest] == -INF){
        printf("gg");
        return 0;
    }
    int result = tot[dest];
    for(int i = 0; i < m; i++){
        if(tot[e[i].u] == -INF) continue;
        if(tot[e[i].v] < tot[e[i].u] - e[i].w + inc[e[i].v]){
            tot[e[i].v] = tot[e[i].u] - e[i].w + inc[e[i].v];
        }
    }
    if(result == tot[dest])printf("%lld", tot[dest]);
    else printf("Gee");
}