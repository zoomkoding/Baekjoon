#include <cstdio>

using namespace std;

int lvl[10001], par[10001], chd[10001][2], cnt[10001][2], pos[10001], MIN[10001], MAX[10001];
int max_lvl = 0;

int dfs(int node){
    int level = lvl[node], child;
    for(int i = 0; i < 2; i++){
        child = chd[node][i];
        if(child != -1){
            lvl[child] = level + 1;
            if(level + 1 > max_lvl) max_lvl = level + 1;
            cnt[node][i] = dfs(child) + 1;
        }
    }
    return cnt[node][0] + cnt[node][1];
}

void draw(int node, int start){
    pos[node] = start + cnt[node][0];
    if(chd[node][0] != -1)draw(chd[node][0], start);
    if(chd[node][1] != -1)draw(chd[node][1], pos[node] + 1);
}

int n, p, r, l, root = 1;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &p, &l, &r);
        if(r != -1)par[r] = p;
        if(l != -1)par[l] = p;
        chd[p][0] = l, chd[p][1] = r; 
    }
    while(par[root] != 0)root = par[root];
    lvl[root] = 1;
    dfs(root);
    draw(root, 1);
    for(int i = 1; i <= max_lvl; i++){
        MIN[i] = 100000;
        MAX[i] = 1;
    }
    for(int i = 1; i < n + 1; i++){
        if(MIN[lvl[i]] > pos[i])MIN[lvl[i]] = pos[i];
        if(MAX[lvl[i]] < pos[i])MAX[lvl[i]] = pos[i];
    }
    int ans = 1;
    for(int i = 1; i <= max_lvl; i++){
        if(MAX[i] - MIN[i] > MAX[ans] - MIN[ans])ans = i;
    }
    printf("%d %d", ans, MAX[ans] - MIN[ans] + 1);
}