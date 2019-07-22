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
int parent[17][100020], M[17][100020], m[17][100020];
int level[100010];
int n, k, v, w, u;


void LCA(int chd, int par){
    int MIN = INF, MAX = -INF;
    int diff = level[chd] - level[par];
    for(int i = 16; i >= 0; i--){
        if((1<<i) <= diff){
            if(m[i][chd] < MIN) MIN = m[i][chd];
            if(M[i][chd] > MAX) MAX = M[i][chd];
            chd = parent[i][chd];
            diff -= (1<<i);
        }
    }
    if(chd == par){
        printf("%d %d\n", MIN, MAX);
        return;
    }
    for(int i = 16; i >= 0; i--){
        if(parent[i][chd] != parent[i][par]){
            if(m[i][chd] < MIN) MIN = m[i][chd];
            if(m[i][par] < MIN) MIN = m[i][par];

            if(M[i][chd] > MAX) MAX = M[i][chd];
            if(M[i][par] > MAX) MAX = M[i][par];
            
            chd = parent[i][chd];
            par = parent[i][par];
        } 
    } 
    MIN = min(MIN, min(m[chd][0], m[par][0]));
    MAX = max(MAX, max(M[chd][0], M[par][0]));
    printf("%d %d\n", MIN, MAX);
}

void build_tree(int root){
    queue<int> q;
    q.push(root);
    level[root] = 1;
    parent[0][root] = 1;
    
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].v, w = ll[u][i].w;
            if(level[v] == 0){
                level[v] = level[u] + 1;
                parent[0][v] = u;
                m[0][v] = M[0][v] = w;
                q.push(v);
            }
        }
    }
}

void find_parent(){
    for(int i = 1; i < 17; i++){
        for(int j = 1; j < n + 1; j++){
            int x = i-1, y = parent[i-1][j];
            parent[i][j] = parent[x][y];
            m[i][j] = m[i-1][parent[i-1][j]] < m[i-1][j] ? m[i-1][parent[i-1][j]] : m[i-1][j];
            M[i][j] = M[i-1][parent[i-1][j]] > M[i-1][j] ? M[i-1][parent[i-1][j]] : M[i-1][j];
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

    for(int i = 0; i < 17; i++){
        for(int j = 0; j < n + 1; j++){
            M[i][j] = -INF, m[i][j] = INF;
        }
    }
    build_tree(1);


    find_parent();

    for(int i = 0; i < 17; i++){
        for(int j = 1; j < n + 1; j++){
            printf("[%d %d] ", m[i][j], M[i][j]);
        }
        printf("\n");
    }
    
    scanf("%d", &k);
    while(k--){
        scanf("%d %d", &v, &u);
        level[v] > level[u] ? LCA(v, u) : LCA(u, v);       
    }
}