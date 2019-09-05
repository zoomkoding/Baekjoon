#include <cstdio>
#include <vector>
#include <queue>
#define pii pair<int, int> 
#define IN first
#define I second
using namespace std;

int main(){
    int n, m, k, v1, v2, in[1001] = {0,}, visited[1001] = {0,};
    vector<int> ans;
    scanf("%d %d", &n, &m);
    vector<vector<int> > edge(n+1);
    while(m--){
        scanf("%d %d", &k, &v1);
        k--;
        while(k--){
            scanf("%d", &v2);
            edge[v1].push_back(v2);
            in[v2]++, v1 = v2;
        }
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i = 1; i < n + 1; i++)pq.push(pii(in[i], i));
    while(!pq.empty()){
        int top_i = pq.top().I, top_in = pq.top().IN; pq.pop();
        if(visited[top_i])continue;
        if(top_in != 0){
            printf("0\n");
            return 0;
        }
        visited[top_i] = 1;
        ans.push_back(top_i);
        for(int i = 0; i < edge[top_i].size(); i++){
            int next_i = edge[top_i][i];
            if(visited[next_i])continue;
            pq.push(pii(--in[next_i], next_i));
        }
    }
    for(int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);
}