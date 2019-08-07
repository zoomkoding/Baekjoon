#include <cstdio>
#include <vector>
#define INF 200000000

typedef struct edge{
    int u, v, w;
}edge;

using namespace std;

int n, src, dest, m, u, v, c;
int inc[100];
int tot[100];
edge e[100];

int main(){
    scanf("%d %d %d %d", &n, &src, &dest, &m);
    for(int i = 0; i < n; i++)tot[i] = -INF;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    if(n == 1){
        for(int i = 0; i < m; i++){
            if(tot[e[i].u] == -INF) continue;
            if(tot[e[i].v] < tot[e[i].u] - e[i].w + inc[e[i].v]){
                tot[e[i].v] = tot[e[i].u] - e[i].w + inc[e[i].v];
            }
        }
        if(tot[dest] > inc[dest]) printf("Gee");
        else if(tot[dest] == inc[dest]) printf("%d", inc[dest]);
        else printf("gg");
    }
    for(int i = 0; i < n; i++)scanf("%d", &inc[i]);
    tot[src] = 0;
    for(int k = 1; k <= n - 1; k++){
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
    if(result == tot[dest])printf("%d", tot[dest]);
    else printf("Gee");


}