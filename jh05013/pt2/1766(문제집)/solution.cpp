#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int, int> 
#define IN first
#define I second
using namespace std;

int in[32001], visited[32001], n, m, v1, v2;
vector<vector<int> > edge;


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    edge = vector<vector<int> >(n+1);
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;
        in[v2]++;
        edge[v1].push_back(v2);
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i = 1; i < n + 1; i++)pq.push(pii(in[i], i));
    while(!pq.empty()){
        pii top = pq.top(); pq.pop();
        if(visited[top.I])continue;
        visited[top.I] = 1;
        cout << top.I << ' ';
        int top_in = top.IN, top_i = top.I;
        for(int i = 0; i < edge[top_i].size(); i++){
            int next_i = edge[top_i][i];
            in[next_i]--;
            pq.push(pii(in[next_i], next_i));
        }
    }
}