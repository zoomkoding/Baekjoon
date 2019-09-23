#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>

#define INF 1000000000
#define SIZE 50020

using namespace std;

vector<vector<int> > ll;
int ac[SIZE][17], depth[SIZE];
int n, m, v, w, u, max_level, temp, child;

void getTree(int current, int parent){
    depth[current] = depth[parent] + 1;
    ac[current][0] = parent;
    for(int i = 1; i <= max_level; i++){
        temp = ac[current][i-1];
        ac[current][i] = ac[temp][i-1];
    }
    int len = ll[current].size();
    for(int i = 0; i < len; i++){
        int child = ll[current][i];
        if(child != parent) getTree(child, current);
    }
}

int find_LCA(int a, int b){
    for(int i = max_level; i >= 0; i--){
        if(depth[a] <= depth[ac[b][i]]) b = ac[b][i];
    }
    if(a == b) return a;
    for(int i = max_level; i >= 0; i--){
        if(ac[a][i] != ac[b][i])a = ac[a][i], b = ac[b][i];
    }
    return ac[a][0];
}

int main(){
    scanf("%d", &n);
    ll = vector<vector<int> >(n + 1);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &v, &u);
        ll[v].push_back(u);
        ll[u].push_back(v);
    }
    depth[0] = -1;
    max_level = (int)floor(log2(SIZE));
    getTree(1, 0);
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &v, &u);
        printf("%d\n", depth[v] < depth[u] ? find_LCA(v, u) : find_LCA(u, v));
    }
}