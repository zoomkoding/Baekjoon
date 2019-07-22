#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#define INF 1000000000

using namespace std;

typedef struct Point{
    int v, w;
    Point(){}
    Point(int i, int j){
        v = i;
        w = j;
    }
}Point;

vector< vector< Point > > ll;
Point parent[100010];
int depth[100010];
int n, m, v, w, u;

void LCA(int chd, int par){
    int m = INF, M = 0;
    int diff = depth[chd] - depth[par];
    for(int i = 0; i < diff; i++){
        int w = parent[chd].w;
        m = m > w ? w : m;
        M = M < w ? w : M;
        chd = parent[chd].v;    
    }
    while(chd != par){
        int w1 = parent[chd].w, w2 = parent[par].w;
        m = m > w1 ? w1 : m;
        M = M < w1 ? w1 : M;
        m = m > w2 ? w2 : m;
        M = M < w2 ? w2 : M;
        chd = parent[chd].v;
        par = parent[par].v;
    }
    printf("%d %d\n", m, M);
}

void build_tree(int root){
    queue<int> q;
    q.push(root);
    depth[root] = 1;
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].v;
            if(depth[v] == 0){
                depth[v] = depth[u] + 1;
                parent[v] = Point(u, ll[u][i].w);
                q.push(v);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    ll = vector< vector< Point > >(n + 1);
    for(int i = 1; i < n; i++){
        scanf("%d %d %d", &v, &u, &w);
        ll[v].push_back(Point(u, w));
        ll[u].push_back(Point(v, w));
    }

    build_tree(1);

    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &v, &u);
        depth[v] > depth[u] ? LCA(v, u) : LCA(u, v);       
    }
}