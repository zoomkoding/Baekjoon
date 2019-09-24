#include <cstdio>
#define GRAPH 1
#define TREE 2

using namespace std;

int t, n, m, v1, v2;
int par[1001];

int find(int i){
    if(par[i] == i)return i;
    return par[i] = find(par[i]);
}

int isCycle(int x, int y){
    int px = find(x), py = find(y);
    if(px == py)return 1;
    par[px] = py;
    return 0;
}

int main(){
    scanf("%d", &t);
    while(t--){
        int ans = TREE;
        scanf("%d %d", &n, &m);
        if(n != m + 1) ans = GRAPH;
        for(int i = 1; i < n + 1; i++)par[i] = i;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &v1, &v2);
            if(ans == GRAPH)continue;
            if(isCycle(v1, v2))ans = GRAPH;
        }
        printf("%s", ans == TREE ? "tree\n" : "graph\n");
    }
}