#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int n, m, n1, n2, answer;
int* visited;
vector<vector<int> > v;
queue<int> q;

int main(){
    scanf("%d %d", &n, &m);
    visited = new int[n+1];
    for(int i = 0; i <= n; i++){
        v.push_back(vector<int>());
        visited[i] = 0;
    }
    
    while(m--){
        scanf("%d %d", &n1, &n2);
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        answer ++;
        for(int i = 0; i < v[temp].size(); i++){
            if(!visited[v[temp][i]]) {
                q.push(v[temp][i]);
                visited[v[temp][i]] = 1;
            }
        }
    }
    printf("%d", answer-1);
}