#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
#define X first
#define Y second
using pii = pair<int, int>;

#define INF 1000000000
#define SIZE 100010


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

vector< vector< pii > > ll;
int parent[17][SIZE], M[17][SIZE], m[17][SIZE];
int level[SIZE];
int n, k, v, w, u;


int find_LCA(int a, int b){
    int MAX = -INF, MIN = INF;
    int diff = level[a] - level[b];
    for(int i = 16; i >= 0; i--){
        if((1<<i) <= diff){
            MAX = max(MAX, M[i][a]);
            MIN = min(MIN, m[i][a]);
            a = parent[i][a];
            diff -= (1<<i);
        }
    }
    if(a == b) {
        printf("%d %d\n", MIN, MAX);
        return a;
    }
    for(int i = 16; i >= 0; i--){
        if(parent[i][a] != parent[i][b]){
            MAX = max(MAX, max(M[i][a], M[i][b]));
            MIN = min(MIN, min(m[i][a], m[i][b]));
            a = parent[i][a];
            b = parent[i][b];            
        } 
    } 
    MAX = max(MAX, max(M[0][a], M[0][b]));
    MIN = min(MIN, min(m[0][a], m[0][b]));
    printf("%d %d\n", MIN, MAX);
    return parent[0][a];
}

void build_tree(int root){
    queue<int> q;
    q.push(root);
    level[root] = 1;
    parent[0][root] = 1;
    
    while(!q.empty()){
        u = q.front(); q.pop();
        for(int i = 0; i < ll[u].size(); i++){
            v = ll[u][i].X, w = ll[u][i].Y;
            if(level[v] == 0){
                level[v] = level[u] + 1;
                parent[0][v] = u;
                m[0][v] = M[0][v] = w;
                q.push(v);
            }
        }
    }
}

void find_parent(){
    for(int i = 1; i < 17; i++){
        for(int j = 1; j < n + 1; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
            M[i][j] = max(M[i-1][j], M[i-1][parent[i-1][j]]);
            m[i][j] = min(m[i-1][j], m[i-1][parent[i-1][j]]);
        }
    }
}

int main(){
    n = readInt();
    ll = vector< vector< pii > >(n + 1);
    for(int i = 1; i < n; i++){
        v = readInt(), u = readInt(), w = readInt(); 
        ll[v].push_back(pii(u, w));
        ll[u].push_back(pii(v, w));
    }

    build_tree(1);
    find_parent();  
  
    k = readInt();

    while(k--){
        v = readInt(), u = readInt(); 
        level[v] > level[u] ? find_LCA(v, u) : find_LCA(u, v);       
    }
}