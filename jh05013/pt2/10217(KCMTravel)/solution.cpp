#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

int t, n, m, k, u, v, c, d; 

typedef struct Point{
    int v, d, c, visited;
    Point(){}
    Point(int i, int j, int k){
        v = i;
        c = j;
        d = k;
        visited = 0;
    }
    Point(int i, int j){
        c = i;
        d = j;
    }
}Point;

void find_short(vector< vector<Point> > &ll, vector<int> &in, int n, int m){
    int min_d = INF;
    queue<int> q;
    vector< vector<Point> > v(n+1);
    v[1].push_back(Point(0, 0));
    q.push(1);
    while(!q.empty()){
        int front = q.front(); q.pop();
        printf("front는 %d\n", front);
        for(int i  = 1; i < n+1; i++){
            printf("%d, ", in[i]);
        }
        printf("\n");
        if(front == n)break;
        for(int i = 0; i < ll[front].size(); i++){
            if(ll[front][i].visited) continue;
            Point edge = ll[front][i];
            for(int j = 0; j < v[front].size(); j++){
                Point node = v[front][j];
                if(node.c + edge.c <= m) v[edge.v].push_back(Point(node.c + edge.c, node.d + edge.d));
            }
            ll[front][i].visited = 1;
            in[edge.v]--;
            if(!in[edge.v])q.push(edge.v);
        } 
    }
    for(int i = 0; i < v[n].size(); i++){
        printf("%d ", v[n][i].d);
        if(v[n][i].d < min_d)min_d = v[n][i].d;
    }
    if(min_d != INF)printf("%d\n", min_d);
    else printf("Poor KCM\n");
}


int main(){
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d %d", &n, &m, &k);
        vector< vector<Point> > ll(n+1);
        vector<int> in(n+1, 0);
        for(int j = 0; j < k; j++){
            scanf("%d %d %d %d", &u, &v, &c, &d);
            ll[u].push_back(Point(v, c, d));
            in[v]++;
        }
        find_short(ll, in, n, m);
    }
}