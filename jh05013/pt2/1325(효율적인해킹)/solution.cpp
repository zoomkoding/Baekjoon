#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int m, n, v, w, M;
vector<vector<int> > ll;

int bfs(int s){
    int c = 0;
    queue<int> q;
    q.push(s);
    vector<int> visited = vector<int>(n+1, 0);
    visited[s] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i = 0; i < ll[x].size(); i++){
            int y = ll[x][i];
            if(visited[y])continue;
            visited[y] = 1;
            q.push(y);
            c++;
        }
    }
    return c;
}

int main(){
    scanf("%d %d", &n, &m);
    ll = vector<vector<int> >(n+1);
    vector<int> trust(n+1);
    for(int i = 0 ; i < m; i++){
        scanf("%d %d", &v, &w);
        ll[w].push_back(v);
    }
    for(int i = 1; i < n + 1; i++){
        trust[i] = bfs(i);
        if(trust[i] > M) M = trust[i];
    }
    for(int i = 1; i < n + 1; i++){
        if(trust[i] == M) printf("%d ", i);
    } 
}