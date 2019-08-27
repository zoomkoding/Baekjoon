#include <cstdio>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int n, w[10001], sum[10001][2], MAX[10001], v1, v2;
vector<int> e[10001];
vector< vector<int> > tree;

void make_tree(){
    int visited[10001] = {0,};
    tree = vector< vector<int> > (n + 1);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(int i = 0; i < e[front].size(); i++){
            int next = e[front][i];
            if(visited[next])continue;
            visited[next] = 1;
            tree[front].push_back(next);
            q.push(next);
        }
    }
}
//한쪽 child의 연산이 끝났다고 하면 이 결과가 parent로 전달되서 다른 child 할 땐 연산한 애들로 진행이 되어야 한다.
void find(int v, int p, int gp, int ggp){
    sum[v][0] = w[v] + max(sum[gp][0], sum[gp][1]);
    sum[v][1] = w[v] + max(sum[ggp][0], sum[ggp][1]);
    for(int i = 0; i < tree[v].size(); i++){
        find(tree[v][i], v, p, gp);
    }
    sum[gp][0] = max(MAX[gp], max(sum[v][1], sum[v][0]));
    sum[ggp][0] = max(MAX[ggp], max(sum[v][1], sum[v][0]));
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)scanf("%d", &w[i]);
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &v1, &v2);
        e[v1].push_back(v2);
        e[v2].push_back(v1);
    }
    make_tree();

    find(1, 0, 0, 0);
    for(int i = 1; i <= n; i++){
        printf("%d\n", sum[i][0]);
    }
}