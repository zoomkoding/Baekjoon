#include <queue>
#include <vector>
#include <cstdio>
#define INF 1000000000

using namespace std;

vector<vector<int> > ll;
int ac[17][50020], depth[50020];
int n, m, v, w, u;

int find_LCA(int chd, int par){
    int diff = depth[chd] - depth[par];
    for(int i = 16; i >= 0; i--){
        if((1<<i) <= diff){
            chd = ac[i][chd];
            diff -= (1<<i);
        }
    }
    if(chd == par) return chd;
    for(int i = 16; i >= 0; i--){
        if(ac[i][chd] != ac[i][par]){
            chd = ac[i][chd];
            par = ac[i][par];
        } 
    } 
    return ac[0][chd];
}

void build_tree(){
    queue<int> q;
    depth[1] = 1, ac[0][1] = 1;
    q.push(1);
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i];
            if(depth[v] == 0){
                depth[v] = depth[u] + 1;
                ac[0][v] = u;
                q.push(v);
            }
        }
    }
}
void find_parent(){
    for(int i = 1; i < 17; i++){
        for(int j = 1; j < n + 1; j++)ac[i][j] = ac[i-1][ac[i-1][j]];
    }
}

int main(){
    scanf("%d", &n);
    ll = vector<vector<int> >(n + 1);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &v, &u);
        ll[v].push_back(u);
        ll[u].push_back(v);
    }
    build_tree();
    find_parent();

    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &v, &u);
        printf("%d\n", depth[v] < depth[u] ? find_LCA(v, u) : find_LCA(u, v));
    }
}