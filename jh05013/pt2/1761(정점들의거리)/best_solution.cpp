#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M,level[40005],parent[17][40005],dist[40005];
vector<pair<int,int> > adj[40005];
pair<int,int> Query[10000];

int input(){
    cin >> N;
    for(int i=0;i<N-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> Query[i].first >> Query[i].second;
    }
    return 0;
}

int findlevel(){
    queue<int> q;
    int checked[40005] = {0};
    q.push(1);
    level[1] = 0;
    parent[0][1] = 1;
    dist[1] = 0;
    checked[1] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<adj[now].size();i++){
            int v = adj[now][i].first, w = adj[now][i].second;
            if(checked[v]) continue;
            q.push(v);
            level[v] = level[now] + 1;
            parent[0][v] = now;
            dist[v] = dist[now] + w;
            checked[v] = 1;
        }
    }
    return 0;
}

int up(int now,int toup){
    for(int i=16;i>=0;i--){
        if((1<<i) <= toup){
            now = parent[i][now];
            toup -= (1<<i);
        }
    }
    return now;
}

int lca(int l,int r){
    if(l==r) return l;
    for(int i=16;i>=0;i--){
        if(parent[i][l] != parent[i][r]){
            l = parent[i][l];
            r = parent[i][r];
        }
    }
    return parent[0][l];
}

int main(){
    ios::sync_with_stdio(false);
    input();
    findlevel();
    for(int i=1;i<=16;i++){
        for(int j=1;j<=N;j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
    for(int i=0;i<M;i++){
        int l = Query[i].first,r = Query[i].second;
        if(level[l] > level[r]){
            int tmp = l;
            l = r;
            r = tmp;
        }
        cout << dist[l] + dist[r] - 2*dist[lca(l,up(r,level[r] - level[l]))] << "\n";
    }
    return 0;
}
