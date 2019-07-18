//일단 edge를 다 받아
//받고 나서 트리를 만들어
    //1번 원소를 큐에 넣어
    //큐에 원소가 없을때까지 반복해
        //원소를 꺼내고 인접 원소의 값을 업데이트해줘
            //root로부터의 거리를 기록하고 
            //parent와 level을 기록해줘
            //parent가 0이면 넣어
//input이 들어오면 up해주고
//두점의 부모가 같아질때까지 올려
//두점으로부터 1번 원소까지 거리를 더하고 공통부모로부터 1번까지의 곱하기 2를 빼줘.

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
int parent[40020], level[40020], d[40020];
int n, m, v, w, u;

int LCA(int chd, int par){
    int diff = level[chd] - level[par];
    for(int i = 0; i < diff; i++)chd = parent[chd];    
    while(chd != par)chd = parent[chd], par = parent[par];
    return chd;
}

void build_tree(){
    queue<int> q;
    level[1] = 1, d[1] = 0, parent[1] = 1;
    q.push(1);
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].v;
            if(level[v] == 0){
                level[v] = level[u] + 1;
                parent[v] = u;
                d[v] = d[u] + ll[u][i].w;
                q.push(v);
            }
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
    build_tree();
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &v, &u);
        printf("%d\n", d[v] + d[u] - d[level[v] > level[u] ? LCA(v, u) : LCA(u, v)]*2);       
    }
}