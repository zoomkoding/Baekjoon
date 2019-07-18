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
vector<Point> parent;
vector<int> depth;
int n, m, v, w, u;

char buf[1 << 17];

inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? sum : -sum;
}

void LCA(int chd, int par){
    int dis = 0;
    int diff = depth[chd] - depth[par];
    for(int i = 0; i < diff; i++){
        dis += parent[chd].w;
        chd = parent[chd].v;    
    }
    while(chd != par){
        dis += parent[chd].w + parent[par].w;
        chd = parent[chd].v;
        par = parent[par].v;
    }
    printf("%d\n", dis);
}

void build_tree(int root){
    queue<int> q;
    q.push(root);
    depth[root] = 1;
    int count = 0;
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].v;
            if(depth[v] == 0){
                depth[v] = depth[u] + 1;
                parent[v] = Point(u, ll[u][i].w);
                q.push(v);
            }
        }
    }
}

int main(){
    n = readInt();
    ll = vector< vector< Point > >(n + 1);
    for(int i = 1; i < n; i++){
        v = readInt(), u = readInt(), w = readInt();
        ll[v].push_back(Point(u, w));
        ll[u].push_back(Point(v, w));
    }
    parent = vector<Point>(n + 1);
    depth = vector<int>(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(ll[i].size() == 1) {
            build_tree(i);
            break;
        }
    }

    m = readInt();
    while(m--){
        v = readInt(), u = readInt();
        depth[v] > depth[u] ? LCA(v, u) : LCA(u, v);       
    }
}